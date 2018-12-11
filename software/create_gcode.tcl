open_gerber /home/anusha/pcb_printer/software/test_data/name_tag/name_tag-F.SilkS.gbr
isolate name_tag-F.SilkS.gbr -dia 0.015 -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -tooldia 0.015 -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc ../pcb_printer/software/current_job.gcode