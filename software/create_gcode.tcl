open_gerber /home/anusha/o.gbr
isolate o.gbr -dia 0.0195 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 0.0195 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode