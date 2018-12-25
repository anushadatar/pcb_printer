# Etch a Schech : CNC PCB Mill
This repository contains documentation, firmware, and software for Aiden Carley-Clopton, Quinn Kelley, Josh Deng, and Anusha Datar's Olin College Principles of Engineering FA18 final project. Over the course of three two-week sprints, we developed a highly functional and robust two-axis compound table with z-axis spindle assembly capable of milling Printed Circuit Boards (PCBs).

## Docs
The docs directory contains the source for the project [website](https://anushadatar.github.io/pcb_printer/), which includes extensive documentation of the overall project architeture, subsystem development, and the design and implementation process. It also contains a more general [poster](https://github.com/anushadatar/pcb_printer/blob/master/docs/artifacts/poster.pdf) for external documentation purposes.

## Firmware
The firmware directory contains the production source code for the real-time control system of the final project and test code associated with hardware integration and system maintenance. 

The [gcode_parse/](https://github.com/anushadatar/pcb_printer/tree/master/firmware/gcode_parse) directory contains code that, with the necessary dependencies, can be compiled for the Arduino Uno V3 and flashed onto the chip by means of the [gcode_parse.ino](https://github.com/anushadatar/pcb_printer/blob/master/firmware/gcode_parse/gcode_parse.ino) file. 

## Software
The software directory contains the software to run the high-level computation necessary to determine and send commands to the real-time controller. With the necessary dependencies, the 


## Dependencies
The [software page of the project website](https://anushadatar.github.io/pcb_printer/software.html) contains links to all of the external software packages necessary to run this code. For more software setup details for the computational platform, use the software [guide](https://github.com/anushadatar/pcb_printer/blob/master/software/README.md). Note that a new run file with the proper pathing is necessary for any new environment, and for the code to run properly the environment must be UNIX-compliant.
