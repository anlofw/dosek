#!/usr/bin/python

import struct
import imp
from gzip import GzipFile
from optparse import OptionParser
from generator.stats_binary import read_symbols, read_regions, find_symbol
from generator.statistics import Statistics
from collections import namedtuple


def open_trace(filename):
    f = open(filename, "rb")
    if ord(f.read(1)) == 0x1f and ord(f.read(1)) == 0x8b:
        f.seek(0,0)
        return GzipFile(fileobj = f)
    f.seek(0,0)
    return f

def read_trace(trace_plugin_filename, trace_filename):
    """Generator that iterates over all events in trace"""

    trace_plugin = imp.load_source("trace", trace_plugin_filename)
    trace_file = open_trace(trace_filename)
    trace_event = trace_plugin.Trace_Event()

    acctime = 0
    while True:
        # Read trace length
        try:
            lengthNO = trace_file.read(4)
            if len(lengthNO) == 0:
                break
        except IOError:
            print "Could not read data from file"

        # Read Trace-Event
        length = struct.unpack('!I', lengthNO)[0]
        trace_event.ParseFromString(trace_file.read(length))

        # More compact dump for traces:
        if trace_event.HasField("time_delta"):
            acctime += trace_event.time_delta

        yield (acctime, trace_event)
    trace_file.close()


class SymbolMap(dict):
    """The Symbol map maps memory addresses to symbols for fast
    translation"""
    def __init__(self, symbols):
        self.symbols = symbols
        for symbol in symbols:
            if not symbol.size:
                self[symbol.addr] = symbol

        for symbol in symbols:
            if symbol.size:
                for i in range(symbol.addr, symbol.addr+symbol.size):
                    self[i] = symbol

class CoredosDetector:
    START  = 1
    WITHIN = 2
    END    = 4

    def __init__(self, symbol_map):
        self.symbol_map = symbol_map
        self.syscall_endurance = set()

        for symbol in self.symbol_map.symbols:
            start = symbol.addr
            end   = symbol.addr+1
            if symbol.size:
                end = symbol.addr + symbol.size
            # All interrupt handlers are part of the system
            if symbol.name.startswith("irq_") \
               or symbol.name.startswith("isr_") \
               or symbol.name == "handler_exit":
                self.syscall_endurance.update(range(start, end))

            if symbol.name.startswith("__OS_"):
                self.syscall_endurance.update(range(start, end))

    def for_addr(self, addr):
        ret = 0
        if addr in self.syscall_endurance:
            ret |= self.WITHIN
        if ret == 0:
            if self.symbol_map.get(addr) is None:
                ret |= self.WITHIN
        return ret

    def classify(self, last_addr, current_addr, next_addr):
        this = self.for_addr(current_addr)
        if this:
            before = self.for_addr(last_addr)
            after  = self.for_addr(next_addr)
            if before == 0:
                this |= self.START
            if after == 0:
                this |= self.END
            if after & self.START:
                this |= self.END
        return this

class SyscallRegion:
    def __init__(self, start_time):
        self.start_time = start_time
        self.trace      = []
        self.end_time   = start_time
    def push_symbol(self, time, symbol):
        if not self.trace or self.trace[-1][1] != symbol:
            self.trace.append([1, symbol])
        else:
            self.trace[-1][0] += 1
        # Increase time
        assert time >= self.end_time
        self.end_time = time

def syscall_regions(trace_events, symbol_map):
    """Generator that returns detected syscall regions"""
    last_addr = current_addr = next_addr = None
    detector = CoredosDetector(symbol_map)

    region = None

    for time, event in trace_events:
        if event.HasField("memaddr"):
            continue
        # Read one event ahead and preserve one old event
        last_addr    = current_addr
        current_addr = next_addr
        next_addr = event.ip

        # When "pipeline" is full
        if last_addr:
            classified = detector.classify(last_addr, current_addr, next_addr)
            #print hex(current_addr), classified, symbol
            # If event has no class, simply continue
            if classified == 0:
                continue
            symbol = symbol_map.get(current_addr)
            if classified & detector.START:
                assert region is None, region
                region = SyscallRegion(time)

            # Symbol is part of the current region
            region.push_symbol(time, symbol)

            # We are a generator, therefore we yield the current
            # syscall region
            if classified & detector.END:
                yield region
                region = None



def main(options, args):
    symbols = [x for x in read_symbols(options.elf)
               if x.addr]
    symbol_map = SymbolMap(symbols)

    trace_events = read_trace(options.traceplugin, options.trace)
    stats = Statistics.load(options.stats)
    for abb in stats.find_all("AtomicBasicBlock").values():
        if not 'generated-function' in abb:
            continue
        abb["activations"] = []

    for syscall_region in syscall_regions(trace_events, symbol_map):
        names = [x[1].name for x in syscall_region.trace if x[1]]
        region_length = sum([x[0] for x in syscall_region.trace])
        event_type = None
        for name in names:
            if "__OS_syscall" in name:
                assert event_type  is None
                event_type = name
            if name in ("__OS_ASTSchedule", "__OS_StartOS_dispatch"):
                assert event_type  is None
                event_type = name
        #print region_length, event_type

        for abb in stats.find_all("AtomicBasicBlock").values():
            if not 'generated-function' in abb:
                continue
            if event_type in abb["generated-function"]:
                trace_info = {
                    "cycles": region_length,
                    "trace": [(x[0], x[1].name) for x in syscall_region.trace],
                    "start-time": syscall_region.start_time,
                    "end-time": syscall_region.end_time,
                }
                abb["activations"].append(trace_info)

    print options.stats
    stats.save(options.stats)


if __name__ == "__main__":
    parser = OptionParser()

    parser.add_option("-e", "--elf", dest="elf",
                      help="elf binary", metavar="ELF")
    parser.add_option("-t", "--trace", dest="trace",
                      help="trace.pb", metavar="TRACE")
    parser.add_option("-o", "--objdump", dest="objdump", default="/usr/bin/objdump",
                      help="objdump binary location", metavar="OBJDUMP")
    parser.add_option("-p", "--trace-plugin", dest="traceplugin",
                      help="python trace plugin path", metavar="OBJDUMP")
    parser.add_option("", "--stats-dict", dest="stats",
                      help="stats.dict.py path", metavar="STATS")


    (options, args) = parser.parse_args()

    main(options, args)
