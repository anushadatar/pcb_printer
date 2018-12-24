This software directory's function is to develop a framework to convert a .gbr
file output into a gcode equivalent file (containing coordinates and paths) and then convert that into
paths for the CNC. Those paths can then yield motor instructions for the CNC.

The main path planning is handled by the third-party tool Flatcam. Installation can be tricky; streamlined Ubuntu instructions
are included below. Raspberry Pi setup requires additional adjustments to the Flatam stack - contact us for details!


## Dev Framework: Ubuntu Setup Instructions
While the Etch A Schech uses a Raspberry Pi to setup up computation and screaming, it can often be more convenient to use a machine with Ubuntu for software and testing. To set up this framework, first install the Flatcam Dependencies:
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

Then, install the package with the following commands. If this fails, try moving on to the next step - it may be resolved by the Flatcam setup_ubuntu shell script.
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
A flatcam window should launch following this final command. 

Once the proper software has been installed, configure the necessary environment variables to configure the run framework.
To do that, instantiate pointers to this software folder and to your flatcam installation by adding the following lines to your .bashrc:

~~~~
export $ETCH_SW_DIR='/PATH/TO/SW/DIR'
export $FLATCAM_DIR='/PATH/TO/FLATCAM/INSTALL'
~~~~
