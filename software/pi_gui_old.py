#!/usr/bin/env python3

import subprocess
import tkinter
import tkinter.filedialog

# Diameter (inches) of the endmill.
ENDMILL_DIAMETER = 0.125
# Diameter (inches) of the engraving bit.
ENGRAVING_DIAMETER = 0.0039

def path_run_script(bit_diameter):
    """
    Asks user to specify file path of the associated file.  
    """
    print("Path script called from GUI.")
    path =  tkinter.filedialog.askopenfilename()
    
    # Assemble appropriate script.
    script_string = ["bash pi_run.sh", path, str(bit_diameter)]
    # Call the script.
    subprocess.call(script_string, shell=True) 


gui = tkinter.Tk()

engraving_choose_file_button = tkinter.Button(gui, text="Choose File (Engraving)", command=path_run_script(ENGRAVING_DIAMETER))
milling_choose_file_button = tkinter.Button(gui, text="Choose File (Endmill)", command=path_run_script(ENDMILL_DIAMETER))

engraving_choose_file_button.pack()
milling_choose_file_button.pack()

gui.mainloop()
