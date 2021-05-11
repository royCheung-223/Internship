# Internship
## Set up the workspace
*cd "your workspace path"*
*source devel/setup.bash*

##run the roscore before using the rosserial

##Cannot use serial print
*The port would be interrupted*

## publishing the cmd_vel
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600
*To set the same baud rate in serial and the arduino*

