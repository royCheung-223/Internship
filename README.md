# Internship
## Set up the workspace
*cd "your workspace path"*
*source devel/setup.bash*

##run the roscore before using the rosserial
![Screenshot from 2021-05-12 11-50-46](https://user-images.githubusercontent.com/83933967/117915798-92e4fe80-b318-11eb-8571-bfa4f1892d72.png)

## publishing the cmd_vel
Step1:
reduce publishing rate from python to arduino
Step2:
simple_controller.sh published the velocity 
![Screenshot from 2021-05-12 11-58-25](https://user-images.githubusercontent.com/83933967/117916321-87de9e00-b319-11eb-91e2-ac5cb8ac3498.png)
Step3:
rosserial_python serial_node.py send the cmd_vel to audrino
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600
*To set the same baud rate in serial and the arduino*
![Screenshot from 2021-05-12 12-01-38](https://user-images.githubusercontent.com/83933967/117916506-dee47300-b319-11eb-9953-760d2e1f2c4a.png)


## Ubuntu terminal
tmux
ctrl+b shift+" a horizontal line
ctrl+b shift+% a vertical line
ctrl+b ->      change window on terminal

## Quick start of program(same as type in terminal)
echo "Start"
source devel/setup.bash
rosrun demo_python demo.py
python src/demo_2.py
echo "Done"

## change executable of program
intial white colour
## sudo chmod a+x "file name.sh" 
after would become green 
