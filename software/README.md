This software directory's function is to develop a framework to convert a .gbr
file output into a gcode equivalent file (containing coordinates and paths) and then convert that into
paths for the CNC. Those paths can then yield motor instructions for the CNC.

The main path planning is handled by the third-party tool Flatcam. Installation can be tricky; streamlined Ubuntu instructions
are included below. Raspberry Pi setup requires additional adjustments to the Flatam stack - contact us for details!

## Dev Framework: Ubuntu Setup Instructions
While the final project will likely use a Raspberry Pi to setup up computation and screaming, it can often be more convenient to use a machine with Ubuntu for software and testing. To set up this framework, first install the Flatcam Dependencies:
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
python3 configure.py 
make
sudo make install
~~~~~
- [Flatcam 8.5](https://bitbucket.org/jpcgt/flatcam/downloads/) 

Finally, actually install flatcam. Grab the zip file for Flatcam from [here](https://bitbucket.org/jpcgt/flatcam/downloads/).
~~~~
cd [folderName]
chmod +x setup_ubuntu.sh
sudo ./setup_ubuntu.sh
python FlatCAM.py
~~~~

<b> Note that this currently uses Python2. One day, when Anusha and Josh ascend to true open source hackerdudes, it will use python3, 
 like on the Raspi. Today is not that day. </b>

Potentially Useful Resources:
[C++ tool](https://github.com/pcb2gcode/pcb2gcode)
[Validation](https://carbide3d.com/apps/pcb/)
[Another tool](https://github.com/Nikolay-Kha/PCBConverter)
