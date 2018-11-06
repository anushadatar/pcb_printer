# Rapsberry Pi Setup

The raspberry pi should be a git pull away from running all of the code in a pretty straightforward way - note that this requires that all shell scripts be at least moderately Debian-compatible, which I am trying to be mindful of.

## Accessing the Raspsi
Accessing the Raspberry Pi is easiest over SSH - you can launch a client such as [putty](https://www.putty.org/) and type in the IP address, hostname, and password.
Note that getting the IP address of the Pi is not always easy : while the olin.edu assigned ip will last a couple of days, it will not be universal or stable.
If you are really attached to having a GUI, you can also use VNC viewer to access the Pi - this feels more like a full virtual machine and you have alot more freedom, but it is pretty slow (and SSH is already slow!).

### Finding the IP Address
There are a few ways to find the IP address of the raspi in order to SSH into it. The easiest way is probably just to go to the computer lab, plug in the power cable, and connect to a monitor/keyboard/mouse. 
Then, power on the pi, ensure it is connected to wireless, open up a terminal, and type in ```ipconfig``` to print out the wireless network information. 
On 11/5, I got the ip ```192.168.33.154```.
You can also just use a network ip scanner; the raspi is called "pi" and probably has a 192 address. 

### Logging In
I've kept the default login and password, you can google it if needed. Might be worth changing that (11/06).

## GPIO, Running Scripts, etc.
The raspi is super user friendly - here's a nice [tutorial](https://learn.sparkfun.com/tutorials/raspberry-gpio/gpio-pinout) on how to use their straightforward pinouts. 
For now, the serial connection one is probably the one that's more interesting to us.
To run a script, literally just launch the terminal and use it as you would any other device. It's pretty wild.
