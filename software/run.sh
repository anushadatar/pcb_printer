python2 ../../FlatCAM-8.5/FlatCAM.py --shellfile=/home/josh/Github/pcb_printer/software/flatcam_scripts/gbr_to_gcode.tcl

python gcode_format.py -p test_data/rectangle/test.gcode

python gcode_stream.py -s -p output.gcode