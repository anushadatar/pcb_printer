This software directory's function is to develop a framework to convert a .gbr
file output into an intermeddiary gcode equivalent and then convert that into
paths for the CNc. Those paths can then yield motor instructions for the CNC.

The main path planning is handled by the third-party tool Flatcam, which can be
downloaded from [here](http://flatcam.org/manual/installation.html). Successful 
implementation on the Raspberry Pi platform requires modifications to the software
stack - contact us for details.

Potentially Useful Resources:
[C++ tool](https://github.com/pcb2gcode/pcb2gcode)
[Validation](https://carbide3d.com/apps/pcb/)
[Another tool](https://github.com/Nikolay-Kha/PCBConverter)
