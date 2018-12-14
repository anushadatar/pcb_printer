#!/usr/bin/env python3

import glob
import os
import subprocess
import tkinter
import tkinter.filedialog

# Diameter (inches) of the endmill.
ENDMILL_DIAMETER = 0.125
# Diameter (inches) of the engraving bit.
ENGRAVING_DIAMETER = 0.0039

def engraving_ask_path(bit_diameter=ENGRAVING_DIAMETER):
    """
    Asks user to specify file path of the associated file.  
    Runs engraving based on specification.
    """
    print("Path script called from GUI.")
    path =  tkinter.filedialog.askopenfilename()
    
    # Assemble appropriate script.
    script_string = "bash anusha_run.sh " + str(path) + " " + str(bit_diameter)
    print(script_string)
    # Call the script.
    subprocess.call(script_string, shell=True) 

def engraving_choose_recent(bit_diameter=ENGRAVING_DIAMETER, drive_path="/home/anusha/test"):
    """
    Grabs most recent file off of flash drive or other mounted folder.
    """
    # Get most recent file on USB stick.
    print("Recent file script called from GUI?")
    files_path = os.path.join(drive_path, "*")
    files = sorted(glob.iglob(files_path), key=os.path.getctime, reverse=True)
    path = files[0]

    # Assemble the script.
    script_string = "bash anusha_run.sh " + str(path) + " " + str(bit_diameter) 
    print(script_string) 
   # Call the script.
    subprocess.call(script_string, shell=True)


def create_gui():
    """
    Runs gui using tkinter.
    """ 
    gui = tkinter.Tk()

    engraving_choose_file_button = tkinter.Button(gui, text="Choose File", command=engraving_ask_path)
    engraving_choose_recent_button = tkinter.Button(gui, text="Use most recent file on USB flash drive", command=engraving_choose_recent)

    engraving_choose_recent_button.pack()
    engraving_choose_file_button.pack()
    gui.mainloop()



create_gui()
