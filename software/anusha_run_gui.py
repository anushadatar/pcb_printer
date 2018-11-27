#!/usr/bin/env python3

import tkinter
import tkinter.simpledialog

# Diameter (inches) of the endmill.
ENDMILL_DIAMETER = 0.125
# Diameter (inches) of the engraving bit.
ENGRAVING_DIAMETER = 0.0039

def usb_etch_run_script():
    """
    Searches for file on USB drive.
    """
    print("USB script called from GUI.")
    
    # TODO Write code to query USB devices for path or set up auto-mount
           # and write instructions for it accordingly.
    script_string = "./anusha_run.sh " + path + str(ENGRAVING_DIAMETER)

    # Call the script.
    subprocess.call(script_string)


def path_run_script():
    """
    Asks user to specify file path of the associated file.  
    """
    print("Path script called from GUI.")
    path = tkinter.simpledialog.askstring("Title", "Prompt")
    script_string = "./anusha_run.sh " + path + str(ENGRAVING_DIAMETER)
    # Call the script.
    subprocess.call(script_string) 



gui = tkinter.Tk()

usb_etch_button = tkinter.Button(gui, text="USB File Input (Etch)", command=usb_etch_run_script)
specify_path_button = tkinter.Button(gui, text="Specify Path", command=path_run_script)

usb_etch_button.pack()
specify_path_button.pack()

gui.mainloop()
