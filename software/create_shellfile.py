#!/usr/bin/env python3
"""
Utility script to generate tcl script for the PCB mill general bash script.

Should accept command line args with either a gerber file or svg file and
associated parameters and create a tcl file that is the filename.tcl that,
when run on startup with Flatcam, will create a gcode file.
"""

import argparse
import sys
import os

def process_args():
    """
    Processes commands associated with creating the tcl script.
    """

    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', action="store", dest='filename',
                    help="Filename of the gerber or svg file.")
    parser.add_argument('--tool-diameter', action="store", dest='tool_diameter', 
                    help="Tool diameter associated with cut.")
    
    args = parser.parse_args() 
    print(args)
    return args

def create_shellfile(filename, tool_diameter):
    """
    Creates tcl script based on input args.
    """
    tcl_file = open("create_gcode.tcl", "w")
    # Flatcam currently supports both gcode files and svg files. 
    if (filename[len(filename)-3 : len(filename)] == "svg"):
        tcl_file.write("test \n asdjas")   
    elif (filename[len(filename)-3 : len(filename)] == "gbr"):
        tcl_file.write("a different test. \n asdsadas.")
    else:
        print("Filetype not supported.")
    tcl_file.close()

args = process_args()
print(args.filename)
create_shellfile(args.filename, args.tool_diameter)
print("Done") 
