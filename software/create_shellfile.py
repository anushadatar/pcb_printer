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
    parser.add_argument('--file', action="store", dest='filename',
                    help="ABSOLUTE filepath of the gerber or svg file.")
    parser.add_argument('--tool-diameter', action="store", dest='tool_diameter', 
                    help="Tool diameter associated with cut.")
    
    args = parser.parse_args() 
    print(args)
    return args


def create_shellfile(filename, tool_diameter):                                  
    """
    Creates tcl script based on input args.
    Requires filename and tool diameter and outputs appropriate gccode file
    given specified routing parameters.
    
    Naming intentionally kept generic to facilitate job-to-job file 
    maintenance across system.

    filename = PATH to file containing either GBR or SVG file.
    tool_diameter = The diameter of the given cutting tool, IN INCHES.
    
    output from function -> tcl file naamed "create_gcode.tcl"
    output when ran in flatcam -> gcode file named "current_job.gcode"
    """
    # Keep naming generic for consistency.                                            
    tcl_file = open("create_gcode.tcl", "w")                                    
    name = filename[(filename.rfind("/") + 1): len(filename)]                   
    # Flatcam currently supports both gcode files and svg files.                
    if (filename[len(filename)-3 : len(filename)] == "svg"):
        tcl_file.write("import_svg " + filename + " -outname geometry.gbr_iso \n")
    elif (filename[len(filename)-3 : len(filename)] == "gbr"):                  
        tcl_file.write("open_gerber " + filename + "\n")          
        tcl_file.write("isolate " + name + " -dia " + tool_diameter + " -outname geometry.gbr_iso -combine\n")
        tcl_file.write("cncjob geometry.gbr_iso -tooldia " + tool_diameter + " -outname cnc.gbr_iso_cnc\n")
        tcl_file.write("write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode")
 
    elif (filename[len(filename)-3 : len(filename)] == "drl"):
        tcl_file.write("open_excellon " + filename + " -outname excellon \n")
        tcl_file.write("drillcncjob excellon -outname drillcnc job - drillz 0.059 -travelz 0.1 feedrate 3 \n")
        tcl_file.write("write_gcode drlcncjob ../pcb_printer/software/current-job.gcode")
    else:
        print("Filetype not supported. Executing last gcode command generated.")
                                                                        
    tcl_file.close()  

args = process_args()
print("Filename : " + str(args.filename))
create_shellfile(args.filename, args.tool_diameter)
