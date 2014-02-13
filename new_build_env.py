#!/usr/bin/python

import os
import sys
import logging
import optparse
import subprocess

def setup_logging(log_level):
    """ setup the logging module with the given log_level """

    l = logging.INFO # default
    if log_level == 1:
        l = logging.DEBUG
    
    logging.basicConfig(level=l)

def cmake_bool(value):
    if value:
        return "ON"
    return "OFF"

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))

    usage = "usage: %prog [options]"
    parser = optparse.OptionParser(usage=usage)
    parser.add_option('-g', '--generator', dest='GENERATOR', default = "make",
                      help="CMake Generator (make|ninja|eclipse)")
    parser.add_option('-a', '--arch', dest='ARCH', default = "i386",
                      help="CMake Generator (i386|posix)")
    parser.add_option('', '--no-encoded', dest='NO_ENCODED', default = False,
                      action="store_true",
                      help="Build an unencoded system (default: false)")
    parser.add_option('', '--no-mpu', dest='NO_MPU', default = False,
                      action="store_true",
                      help="Build an unencoded system (default: false)")
    parser.add_option('-v', '--verbose', dest='verbose', action='count',
                      help="increase verbosity (specify multiple times for more)")
    parser.add_option('-c', '--clean', dest='CLEAN', action="store_true",
                      default = False,
                      help="remove all files from current directory before")

    (options, args) = parser.parse_args()

    if len(args) > 0:
        parser.print_help()
        sys.exit(-1)

    setup_logging(options.verbose)

    generator_dict = {"make": "Unix Makefiles",
                      "ninja": "Eclipse CDT4 - Ninja",
                      "eclipse": "Eclipse CDT4 - Unix Makefile"}

    options.GENERATOR = generator_dict[options.GENERATOR]
    options.REPODIR   = base_dir
    options.ENCODED_SYSTEM = cmake_bool(not options.NO_ENCODED)
    options.MPU_PROTECTION = cmake_bool(not options.NO_MPU)

    logging.info("Build System: %s", options.GENERATOR)
    logging.info("Arch: %s", options.ARCH)
    logging.info("Encoded System: %s", options.ENCODED_SYSTEM)
    logging.info("MPU Protection: %s", options.MPU_PROTECTION)



    # Don't think too much about it
    options = eval(str(options))
    toolchain_file = "%(REPODIR)s/toolchain/%(ARCH)s.cmake" % dict(options)
    logging.info("Toolchain File: %s", toolchain_file)

    if options["CLEAN"]:
        logging.info("Removing all files in current directory...")
        subprocess.call("rm * -rf", shell=True)

    subprocess.call(["cmake", "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
                     '-DCMAKE_TOOLCHAIN_FILE=%s' % toolchain_file,
                     "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
                     "-G", options["GENERATOR"],
                     "-DENCODED_SYSTEM=%s" % options["ENCODED_SYSTEM"],
                     "-DMPU_PROTECTION=%s" % options["MPU_PROTECTION"],
                     options["REPODIR"]])

if __name__ == '__main__':
    main()
