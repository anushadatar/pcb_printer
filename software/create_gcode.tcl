open_gerber /media/pi/5614-2C01/test-F.Cu.gbr
isolate test-F.Cu.gbr -dia 0.0039 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 0.0039 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode