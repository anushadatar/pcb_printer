import serial, time

class Formatter():
    def __init__(self, readpath, savepath="results.gcode"):
        self.readpath = readpath
        self.savepath = time.strftime("%Y%m%d-%H%M%S")+".gcode"
        self.formatted_b = False
        self.formatted = []

    def format(self):
        with open(self.readpath, 'r+') as f:
            self.content = f.readlines()
            for each in self.content:
                if each.find('X') != -1: #Format Y when there is X before it
                    Y_pos = each.find('Y')
                    each = each[:Y_pos] + " " + each[Y_pos:]
                    if Y_pos != -1: # Format Z when there are both X and Y before it
                        Z_pos = each.find('Z')
                        each = each[:Z_pos] + " " + each[Z_pos:]
                self.formatted.append(each)
            self.formatted_b = True
            print(self.formatted)

    def store(self):
        if(self.formatted_b):
            with open(self.savepath, 'w+') as f:
                f.writelines(self.formatted)
                f.close()
        else:
            print("Formatting not completed, not saving.\n")

    def config_serial(self, baudrate=115520):
        """ Set up the serial port to communicate with Arduino
        """
        try: # Try either ttyACM0 or ttyACM1 because Arduino switches around between these two
            arduinoComPort = "/dev/ttyACM0"
            # set baud rate
            baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)
            print('Serial Port ttyACM0')
        except:
            arduinoComPort = "/dev/ttyACM1"
            # set baud rate
            baudRate = baudrate
            # open serial port
            self.serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)
            print('Serial Port ttyACM1\n')


# filepath = "test_data/rectangle/test.gcode"

# with open(filepath, 'r+') as f:
#     formatted = []
#     content = f.readlines()
#     for each in content:
#         if each.find('X') != -1:
#             Y_pos = each.find('Y')
#             each = each[:Y_pos] + " " + each[Y_pos:]
#             if Y_pos != -1:
#                 Z_pos = each.find('Z')
#                 each = each[:Z_pos] + " " + each[Z_pos:]
#         formatted.append(each)
#     print(formatted)

#     f.close()

if __name__ == "__main__":
    Format = Formatter("test_data/rectangle/test.gcode")
    Format.format()
    Format.store()