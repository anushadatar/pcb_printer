open_excellon ../pcb_printer/software/test_data/drl/will.drl -outname excellon.drl
drillcncjob excellon.drl -outname drlcncjob.drl
write_gcode drillcncjob.drl ../pcb_printer/software/test_data/drl/test.gcode
