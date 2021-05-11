# Internship
## Set up the workspace
*cd "your workspace path"*
*source devel/setup.bash*

##run the roscore before using the rosserial

##Cannot use serial print
*The port would be interrupted*

## publishing the cmd_vel
Step1:
reduce publishing rate from python to arduino
Step2:
simple_controller.sh published the velocity 
Step3:
rosserial_python serial_node.py send the cmd_vel to audrino
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600
*To set the same baud rate in serial and the arduino*


