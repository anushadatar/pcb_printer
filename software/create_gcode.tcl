open_gerber /home/anusha/pcb_printer/software/test_data/rectangle/test-F.Cu.gbr
isolate test-F.Cu.gbr -dia 12 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 12 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode