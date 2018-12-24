### Script to automate mill operation.
# Argument 1 should be file path.
# Argument 2 should be tool diameter (in inches). 

# Crete an appropriate tcl file for the given constraints.
python3 create_shellfile.py --file $1 --tool-diameter $2 

# Run the Flatcam software to create the gcode file.
python $FLATCAM_DIR/FlatCAM.py --shellfile=$ETCH_SW_DIR/create_gcode.tcl

# Format the gcode to be more compatible with the parser.
python3 gcode_format.py -p current_job.gcode

# Stream the gcode to the arduino.
python3 gcode_stream.py -s -p output.gcode
