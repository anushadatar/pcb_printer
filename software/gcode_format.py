import serial, time
from optparse import OptionParser
import sys
import os

def init_opts():
    parser = OptionParser()
    parser.add_option("-p", action="store",
                      dest="path", default=0, type=str,
                      help="path of the gcode file to stream")
    options, args = parser.parse_args()
    return options, args

class Formatter():
    def __init__(self, readpath, savepath=time.strftime("%Y%m%d-%H%M%S")+".gcode"):
        """ Initate the class with the path to source gcode and the output gcode 
        """
        self.readpath = readpath
        self.savepath = savepath
        self.formatted_b = False
        self.formatted = []

    def format(self):
        """ Read in the source gcode as a list and append formatted results to a list
        """
        with open(self.readpath, 'r+') as f:
            self.content = f.readlines()
            for each in self.content:
                if each.find('X') != -1: #Format Y when there is X before it
                    Y_pos = each.find('Y')
                    each = each[:Y_pos] + " " + each[Y_pos:]
                    if Y_pos != -1: # Format Z when there are both X and Y before it
                        Z_pos = each.find('Z')
                        each = each[:Z_pos] + " " + each[Z_pos:]
                self.formatted.append(" "+each)
            self.formatted_b = True
            print(self.formatted)

    def store(self):
        """ Store the list of formatted gcode to the output path
        """
        if(self.formatted_b):
            with open(self.savepath, 'w+') as f:
                f.writelines(self.formatted)
                f.close()
        else:
            print("Formatting not completed, not saving.\n")

if __name__ == "__main__":
    opts, args = init_opts()
    Format = Formatter(opts.path)
    Format.format()
    Format.store()