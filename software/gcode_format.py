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
        self.savepath = "output.gcode"
        self.formatted_b = False
        self.formatted = []
        self.thread = 2 #60/127 is for mm, since flatcam defaults to inch, we should probably use inch here
        self.step = 2#00
        self.microstep = 8
        self.coefficient = self.thread * self.step * self.microstep

    def format(self):
        """ Read in the source gcode as a list and append formatted results to a list
        """
        with open(self.readpath, 'r+') as f:
            self.content = f.readlines()
            self.formatConvert(self.content)
            self.formatted_b = True
            print(self.formatted)

    def formatConvert(self, content):
        for each in content:
            X_pos = each.find('X')                       # First find the index of X
            Y_pos = each.find('Y')
            Z_pos = each.find('Z')

            """ If statement to convert and format each line of our gcode to match the actual dimension
                1. If a line begins with X, find the index of X, format and convert the number,
                    then continue on to format either Y or Z or both
                2. If a line begins with Y, find the index of Y, format and convert the number,
                    then continue on to format Z
                3. If a line begins with Z, find the index of Y, format and convert the number       
            """    
            if X_pos != -1:                                 # Format Y only when there is X before it
                if Y_pos != -1:                                # Format Z when there is Y before it   
                    each = self.insertCorrectted(each, X_pos, Y_pos)
                    Y_pos = each.find('Y')                          # Find the index of Y again because we modified the string
                    Z_pos = each.find('Z')
                    each = self.insertCorrectted(each, Y_pos, Z_pos)
                    Z_pos = each.find('Z')
                    if Z_pos != -1:
                        NL_pos = each.find('\n')
                        each = self.insertCorrectted(each, Z_pos, NL_pos)
                elif Z_pos != -1:
                    each = self.insertCorrectted(each, X_pos, Z_pos)
                    Z_pos = each.find('Z')
                    NL_pos = each.find('\n')
                    each = self.insertCorrectted(each, Z_pos, NL_pos)

            elif Y_pos != -1:                                # Format Z when there is Y before it   
                Z_pos = each.find('Z')
                each = self.insertCorrectted(each, Y_pos, Z_pos)
                if Z_pos != -1:
                    NL_pos = each.find('\n')
                    each = self.insertCorrectted(each, Z_pos, NL_pos)

            elif Z_pos != -1:               
                NL_pos = each.find('\n')
                each = self.insertCorrectted(each, Z_pos, NL_pos)
            self.formatted.append(" "+each)
        
    def insertCorrectted(self, each, start_pos, end_pos):
        num = float(each[start_pos+1:end_pos]) * self.coefficient
        return each[:start_pos+1] + str(round(num, 2)) + " " + each[end_pos:]

    def store(self):
        """ 
        Store the list of formatted gcode to the output path
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
