# Internship

## Installing ROS in Ubuntu
Version: Melodic
sudo apt update
sudo apt install ros-melodic-desktop-full

##Creating a workspace
source /opt/ros/melodic/setup.bash
*creating a folder of workspace*
mkdir -p ~/catkin_ws/src
*change directory to your workspace*
cd ~/catkin_ws/
*creating CmakeList.txt to the src folder*
catkin_make
## Set up the workspace
cd "your workspace path"
source devel/setup.bash

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

## reading the encoder value
Step1:
Set the encoder pin as input
Step2:
attachInterrupt(digitalPinToInterrupt(3), countL, RISING); //count the rising pulse
*digitalPinToInterrupt("the encoder pin")*
*countL the function of counting pulses*
*RISING:counting the rising pulse*

## Publishing the encoder value from arduino and subscribing from ROS
![Screenshot from 2021-05-14 17-07-13](https://user-images.githubusercontent.com/83933967/118248521-f74dbc80-b4d6-11eb-8903-31fd2c62882b.png)
*left motor encoder value*
![Screenshot from 2021-05-14 17-11-30](https://user-images.githubusercontent.com/83933967/118249000-82c74d80-b4d7-11eb-84f2-c4532be04435.png)
*right motor encoder value*
![Screenshot from 2021-05-14 17-12-51](https://user-images.githubusercontent.com/83933967/118249102-9ffc1c00-b4d7-11eb-80b8-7790b35e3474.png)
*rostopic info*
![Screenshot from 2021-05-14 17-13-35](https://user-images.githubusercontent.com/83933967/118249224-c326cb80-b4d7-11eb-92b7-ef2d84f805f8.png)
![Screenshot from 2021-05-14 17-15-06](https://user-images.githubusercontent.com/83933967/118249372-f23d3d00-b4d7-11eb-89b3-7d07e1198b76.png)




