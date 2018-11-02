This software directory's function is to develop a framework to convert a .gbr
file output into a gcode equivalent file (containing coordinates and paths) and then convert that into
paths for the CNC. Those paths can then yield motor instructions for the CNC.

The main path planning is handled by the third-party tool Flatcam. Installation can be tricky; streamlined Ubuntu instructions
are included below. Raspberry Pi setup requires additional adjustments to the Flatam stack - contact us for details!

## Dev Framework: Ubuntu Setup Instructions
While the final project will likely use a Raspberry Pi to setup up computation and screaming, it can often be more convenient to use a machine with Ubuntu for software and testing. To set up this framework, first install [Flatcam 8.2](https://bitbucket.org/jpcgt/flatcam/downloads/) from source - download the folder for Ubuntu, unzip it, and run the setup_ubuntu bash script. This will install a variety of necessary dependencies. 	While the final project will likely use a Raspberry Pi to setup up computation and screaming, it can often be more convenient to use a machine with Ubuntu for software and testing. To set up this framework, first install [Flatcam 8.2](https://bitbucket.org/jpcgt/flatcam/downloads/) from source - download the folder for Ubuntu, unzip it, and run the setup_ubuntu bash script. This will install a variety of necessary dependencies. 
Some of the dependencies will need to be installed separately:
 - [SIP](https://www.riverbankcomputing.com/software/sip/download)
 
Download the newest stable source .tar.gz file from [here](https://www.riverbankcomputing.com/software/sip/download). Untar it using
`tar -xvf [folderName] `. 

Then, install the package with the following commands. 
~~~~~
cd [folderName]
python3 configure.py
make
sudo make install
~~~~~
- [PyQt4](https://www.riverbankcomputing.com/software/pyqt/download)
Download the newest stable source .tar.gz file from [here](https://www.riverbankcomputing.com/software/sip/download). Untar it using
`tar -xvf [folderName] `. 

Then, install the package with the following commands. 
~~~~~
cd [folderName]
$qmake_location = whereis qmake
python3 configure.py -q $qmake_location
make
sudo make install
~~~~~

Potentially Useful Resources:
[C++ tool](https://github.com/pcb2gcode/pcb2gcode)
[Validation](https://carbide3d.com/apps/pcb/)
[Another tool](https://github.com/Nikolay-Kha/PCBConverter)
