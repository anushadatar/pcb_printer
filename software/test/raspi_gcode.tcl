open_gerber ../pcb_printer/software/test_data/rectangle/test-F.Cu.gbr
isolate test-F.Cu.gbr -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/test_data/rectangle/test.gcode
