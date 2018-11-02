open_gerber edge_test.gbr
isolate edge_test.gbr -outname geometry.gbr_iso -combine
cncjob geometry.gbr_iso -outname cnc.gbr_iso_cnc
write_gcode cnc.gbr_iso_cnc output.gcode
