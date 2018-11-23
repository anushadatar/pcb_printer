### Script to automate mill operation.
# Argument 0 should be file path.
# Argument 1 should be tool diameter (in inches). 

python3 create_shellfile.py --file $1 --tool-diameter $2 

python2 ../../FlatCAM-8.5/FlatCAM.py --shellfile=~/pcb_printer/software/create_gcode.tcl

python gcode_format.py -p current_job.gcode

python gcode_stream.py -s -p output.gcode
