from optparse import OptionParser
import sys
import os
import serial, time

def init_opts():
    parser = OptionParser()
    parser.add_option("-t", "--type", action="store_true",
                      dest="type", default=False,
                      help="Type in the message rather than use a file")
    parser.add_option("-f", "--file", action="store_true",
                      dest="file", default=False,
                      help="Use a file rather than type in the message")
    parser.add_option("-e", "--encrypt", action="store_true",
                      dest="encrypt", default=False,
                      help="Encrypt the message")
    parser.add_option("-d", "--decrypt", action="store_true",
                      dest="decrypt", default=False,
                      help="Decrypt the message")
    parser.add_option("-s", "--shift", action="store",
                      dest="shift", default=0, type='int',
                      help="Th number to shift the letters by")
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
    Format = Formatter("test_data/rectangle/test.gcode")
    Format.format()
    Format.store()