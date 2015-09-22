#!/usr/bin/python

import sys
import tempfile
import shutil
import subprocess
import os
import glob

def is_llvm_file(file):
    if not os.path.exists(file):
        return False
    if os.path.isdir(file):
        return False
    if file.endswith(".ll"):
        return True
    with open(file) as fd:
        if fd.read(len("; ModuleID")) == "; ModuleID":
            return True
    return "LLVM" in subprocess.check_output(["file", file])

def is_elf_file(file):
    if not os.path.exists(file):
        return False
    return "ELF" in subprocess.check_output(["file", file])


def aggregate_bitcode(archives, ar):
    elf_object_files = []
    # First we unpack all archive files into seperate folders
    # (there can be name collisions)
    count = 0
    for i in archives:
        archive_dir = os.path.join(tempdir, "%d_%s" %(count, os.path.basename(i)))
        count += 1
        os.mkdir(archive_dir)
        subprocess.check_output([ar, "x", os.path.abspath(i)],
                                cwd = archive_dir)

    llvm_files = []
    for root, dirs, files in os.walk(tempdir):
        for file in files:
            if "SYM_TAB" in file:
                continue
            file = os.path.join(root, file)
            # Collect all bitcode LLVM files
            if not is_llvm_file(file):
                elf_object_files.append(file)
            else:
                llvm_files.append(file)

    return elf_object_files, llvm_files


def check_output(*args, **kwargs):
    if "VERBOSE" in os.environ:
        print
        print "linker: ", " ".join([str(x) for x in args[0]])
    return subprocess.check_output(*args, **kwargs)

def llvm_link(files, output):
    check_output([os.path.join(args.llvm_dir, "bin", "llvm-link"),
                             "-o", output] + files)
    return output

def llvm_opt(input, output):
    check_output([os.path.join(args.llvm_dir, "bin", "opt"),
                  "-std-compile-opts", "-always-inline", "-o", output, input])
    return output

def llvm_llc(file, output, flags):
    check_output([os.path.join(args.llvm_dir, "bin", "llc")] + flags + ["-o", output, file])
    return output

def start_as(AS, file, args, output):
    check_output([AS, file] + args + ["-o", output])
    return output


def start_ld(flags, objects, output):
    # check_output([os.path.join(args.llvm_dir, "bin", "clang")] + ["-Wl,--start-group"] + objects + ["-Wl,--end-group"]
    #             + flags + ["-c", "-o", output + ".obj"])

    check_output([args.clang, "-Wl,--start-group"] + objects + ["-Wl,--end-group"]
                 + flags + ["-o", output, "-Wl,-gc-sections"])

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description='Linker for dOSEK.')
    parser.add_argument("--output", "-o", metavar='OUT', help='The file to generate')
    parser.add_argument("--linker-prefix", metavar='PREFIX', help='Output file prefix')
    parser.add_argument("--llvm-dir", metavar='LLVM_DIR', help='Where are the llvm binaries located')
    parser.add_argument("--march", metavar='MARCH', help='Target Architecture for llc [arm|x86]')
    parser.add_argument("--mcpu", metavar='MCPU', help='Target CPU for llc [cortex-a9|i386')
    parser.add_argument("--clang", metavar='CLANG_BINARY', help='Clang binary location')
    parser.add_argument("--ar", default="/usr/bin/ar", help="ar binary location", metavar="AR")
    parser.add_argument("--use-as", default=None, help="use the given assembler", metavar="AR")


    args, unkown_args = parser.parse_known_args()
    archives = [x for x in unkown_args if x.endswith(".a")]
    elf_files = [x for x in unkown_args if is_elf_file(x)]
    llvm_files = [x for x in unkown_args if is_llvm_file(x)]
    compiler_flags = [x for x in unkown_args if x.startswith("-mattr")]



    # Remove file arguments from unkown args
    linker_flags = [x for x in unkown_args
                   if not(x in archives + elf_files + llvm_files + compiler_flags)]

    if args.march:
        llc_march = "-march=" + args.march
    else:
        llc_march = ""

    if args.mcpu:
        llc_mcpu = "-mcpu=" + args.mcpu
    else:
        llc_mcpu = ""

    try:
        tempdir = tempfile.mkdtemp()
        (elf_, llvm_) = aggregate_bitcode(archives, args.ar)
        elf_files += elf_
        llvm_files += llvm_
        print "ELF:", elf_files
        print "LLVM:", llvm_files

        # Link all bitcode files together
        bitcode     = llvm_link(llvm_files, args.linker_prefix + "-stage1.bc")
        bitcode_opt = llvm_opt(bitcode, args.linker_prefix + "-stage2.bc")
        llc_flags = [llc_march, llc_mcpu, "-ffunction-sections", "-fdata-sections", "-nozero-initialized-in-bss"]
        llc_flags += compiler_flags
        llc_flags = [x for x in llc_flags if not x == ""]
        if args.use_as:
            asm = llvm_llc(bitcode_opt, args.linker_prefix + ".asm", llc_flags)
            as_args = [x[4:] for x in unkown_args if x.startswith("-Wa,")]
            system_object = start_as(args.use_as, asm, as_args, args.linker_prefix + ".obj")
        else:
            llc_flags += ["-filetype=obj"]
            system_object = llvm_llc(bitcode_opt, args.linker_prefix + ".obj", llc_flags)

        start_ld(linker_flags, [system_object] + elf_files, args.output)
    finally:
        shutil.rmtree(tempdir)
        pass

