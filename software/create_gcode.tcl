open_gerber /home/anusha/code/pcb_printer/software/edge_test.gbr
isolate edge_test.gbr -dia 0.0039 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 0.0039 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode