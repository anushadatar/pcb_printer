open_gerber /home/anusha/pcb_printer/software/test_data/Logo/Logo-F.Cu.gbr
isolate Logo-F.Cu.gbr -dia 0.0039 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 0.0039 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode