open_gerber test_data/rectangle/test-F.Cu.gbr
isolate test-F.Cu.gbr -dia 1 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 1 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode