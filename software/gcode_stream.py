import serial, time


def init_opts():
    parser = OptionParser()
    parser.add_option("-s", action="store_true",
                      dest="stream", default=False,
                      help="-s sets streaming mode to be true otherwise only send one direction command")
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

    def config_serial(self, baudrate=115520):
        """ Set up the serial port to communicate with Arduino
        """
        try: # Try either ttyACM0 or ttyACM1 because Arduino switches around between these two
            self.arduinoComPort = "/dev/ttyACM0"
            # set baud rate
            self.baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(self.arduinoComPort, self.baudRate, timeout=1)
            print('Serial Port ttyACM0')
        except:
            self.arduinoComPort = "/dev/ttyACM1"
            # set baud rate
            self.baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(self.arduinoComPort,self.baudRate, timeout=1)
            print('Serial Port ttyACM1\n')

        # Allow arduino to stay in relative mode unless we are streaming a gcode file
        if self.opts.stream:
            self.serialPort.write(" G90")

    def open_gcode(self, readpath):
        """ Open the gcode file
        """
        self.readpath = readpath
        self.gcodefile = open(self.readpath, 'r+')
        self.gcodecontent = self.gcodefile.readlines()

    # def stream_gcode(self):
    #     """ Stream gcode one line at a time once an ack signal is
    #     given for the last command
    #     """
        
    def direction(self):
        """
        """
        if not self.opts.stream:
            if self.opts.x != 0:
                temp = " G00 X" + str(self.opts.x) + "\n"
                self.serialPort.write(temp)
            elif self.opts.y != 0:
                temp = " G00 Y" + str(self.opts.y) + "\n"
                self.serialPort.write(temp)
            elif self.opts.z != 0:
                temp = " G00 Z" + str(self.opts.z) + "\n"
                self.serialPort.write(temp)



    def exit(self):
        """ Perform exit conditions
        """
        self.gcodefile.close()


def main():
    opts, args = init_opts()

# if __name__ == "__main__":
