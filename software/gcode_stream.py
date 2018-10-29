import serial, time

class Streamer():
    def __init__(self):
        """ Initate the streamer class
        """
        self.initialized = True

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

    def stream_gcode(self):
        """ Stream gcode one line at a time once an ack signal is
        given for the last command
        """
        print('ToDo\n')


# if __name__ == "__main__":
