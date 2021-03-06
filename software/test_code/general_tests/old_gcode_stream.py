import serial, time
from optparse import OptionParser
import sys
import os

def init_opts():
    parser = OptionParser()
    parser.add_option("-s", action="store_true",
                      dest="stream", default=False,
                      help="-s sets streaming mode to be true otherwise only send one direction command")
    parser.add_option("-p", action="store",
                      dest="path", default=0, type=str,
                      help="path of the gcode file to stream")
    parser.add_option("-x", action="store",
                      dest="xmove", default=0, type=int,
                      help="Distance to move in the x direction")
    parser.add_option("-y", action="store",
                      dest="ymove", default=0, type=int,
                      help="Distance to move in the y direction")
    parser.add_option("-z", action="store",
                      dest="ymove", default=False, type=int,
                      help="Distance to move in the z direction")
    options, args = parser.parse_args()
    return options, args


class Streamer():
    def __init__(self, opts, args):
        """ Initate the streamer class
        """
        self.initialized = True
        self.opts = opts
        self.args = args
        self.lineOfData = "$"

    def config_serial(self, baudrate=115200):
        """ Set up the serial port to communicate with Arduino
        """
        try: # Try either ttyACM0 or ttyACM1 because Arduino switches around between these two
            self.arduinoComPort = "/dev/ttyACM0"
            # set baud rate
            self.baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(self.arduinoComPort, self.baudRate, timeout=1)
            print('Serial Port ttyACM0\n')
        except:
            self.arduinoComPort = "/dev/ttyUSB0"
            # set baud rate
            self.baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(self.arduinoComPort,self.baudRate, timeout=1)
            print('Serial Port ttyACM1\n')

    
        time.sleep(20)
        self.serialPort.write("!".encode())
        while (self.serialPort.readline().decode() != "?"):
            continue
        # Allow arduino to stay in relative mode unless we are streaming a gcode file
        if self.opts.stream:
            self.serialPort.write(" G90\n".encode())
            print("------------Stream Mode------------")

    def open_gcode(self):
        """ Open the gcode file
        """
        if self.opts.stream:
            # Open the gcode file
            self.readpath = self.opts.path
            self.gcodefile = open(self.readpath, 'r+')
            # Load content from gcode file
            self.gcodecontent = self.gcodefile.readlines()

    def stream_gcode(self):
        """ Stream gcode one line at a time once an ack signal is
        given for the last command
        """
        if self.opts.stream:
            for each_line in self.gcodecontent:
                print(each_line)
                self.serialPort.write(each_line.encode())
                self.lineOfData = str(self.serialPort.readline().decode())
                
                while len(self.lineOfData) == 0:
                    self.lineOfData = str(self.serialPort.readline().decode())
                # print("Data: ",self.lineOfData)
                while self.lineOfData[-1]!="$":
                    try:
                        self.lineOfData = str(self.serialPort.readline().decode())
                        # print(self.lineOfData, end=" ")
                        # print("length of the message", len(self.lineOfData))
                        if(len(self.lineOfData)==0):
                            break
                    except:
                        print("bad serial format")

                print("movement successful!")
        
    def direction(self):
        """ Move an axis in a certain direction in a given amount
        """
        if not self.opts.stream:
            if self.opts.x != 0:
                temp = " G00 X" + str(self.opts.x) + "\n"
                self.serialPort.write(temp.encode())
            elif self.opts.y != 0:
                temp = " G00 Y" + str(self.opts.y) + "\n"
                self.serialPort.write(temp.encode())
            elif self.opts.z != 0:
                temp = " G00 Z" + str(self.opts.z) + "\n"
                self.serialPort.write(temp.encode())

    def exit(self):
        """ Perform exit conditions
        """
        self.gcodefile.close()
        print("Operation complete.")
        # Question mark signals termination of program.
        termination_character = "?"
        self.serialPort.write(termination_character.encode()) 

def main():
    opts, args = init_opts()
    
    Stream = Streamer(opts, args)

    Stream.config_serial()

    Stream.open_gcode()

    Stream.direction()

    Stream.stream_gcode()

    Stream.exit()

if __name__ == "__main__":
    main()
