# Internship
## Virtual robot in GazeBo and real robot move at the same time
## 1. Setup of ROS
## 1.1 Installing ROS in Ubuntu
Version: Melodic 
<br />
sudo apt update 
<br />
sudo apt install ros-melodic-desktop-full

## 1.2 Creating a workspace
source /opt/ros/melodic/setup.bash
<br />
*creating a folder of workspace*
<br />
mkdir -p ~/catkin_ws/src
<br />
*change directory to your workspace*
<br />
cd ~/catkin_ws/
<br />
*creating CmakeList.txt to the src folder*
<br />
catkin_make
## 1.3 Set up the workspace (In this project, workspace = Digital_Twins_IC382_old)
cd "your workspace path"
<br />
source devel/setup.bash
## 2. Robot control
## 2.1 Change the physics of the virtual robot
*Change the directory to urdf*
<br />
cd ~/Internship/Digital_Twins_IC382_old/src/robot_description/urdf/
<br />
*change the mass and inertia in URDF/robot.xacro*
<br />
Adjust the value in mass and inertia to let the virtual robot similar to the real robot
Inertia formula can be found in
<br />
https://en.wikipedia.org/wiki/List_of_moments_of_inertia

## 2.2 reading the encoder value
Step1:
<br />
Set the encoder pin as input
<br />
Step2:
<br />
attachInterrupt(digitalPinToInterrupt(3), countL, RISING); //count the rising pulse
<br />
*digitalPinToInterrupt("the encoder pin")*
<br />
*countL the function of counting pulses*
<br />
*RISING:counting the rising pulse*

## 2.3 Publishing the encoder value from arduino and subscribing from ROS
*Publishing the encoder value from arduino*
<br />
refer to Internship/control_WithEncode/control_WithEncode.ino
<br />
*subscribing from ROS*
<br />
refer to Internship/Digital_Twins_IC382_old/src/robot_control/src/control_WithEnodeValue.py



![Screenshot from 2021-05-14 17-07-13](https://user-images.githubusercontent.com/83933967/118248521-f74dbc80-b4d6-11eb-8903-31fd2c62882b.png)
*left motor encoder value*
![Screenshot from 2021-05-14 17-11-30](https://user-images.githubusercontent.com/83933967/118249000-82c74d80-b4d7-11eb-84f2-c4532be04435.png)
*right motor encoder value*
![Screenshot from 2021-05-14 17-12-51](https://user-images.githubusercontent.com/83933967/118249102-9ffc1c00-b4d7-11eb-80b8-7790b35e3474.png)
*rostopic info*
![Screenshot from 2021-05-14 17-13-35](https://user-images.githubusercontent.com/83933967/118249224-c326cb80-b4d7-11eb-92b7-ef2d84f805f8.png)
![Screenshot from 2021-05-14 17-15-06](https://user-images.githubusercontent.com/83933967/118249372-f23d3d00-b4d7-11eb-89b3-7d07e1198b76.png)



## 2.4 Step of controlling the two robot
Step 1:
<br />
*Change directory to workspace*
cd ~/Internship/Digital_Twins_IC382_old
<br />
Step 2:
<br />
Open a new terminal
<br />
*Loading the world*
<br />
./run_gazebo.sh
<br />
Step 3:
<br />
Open a new terminal
<br />
*Open the serial node*
<br />
./control_WithEncode.sh

## 3. Some useful remark
## 3.1 run the roscore before using the rosserial (if you have run the gazebo, no need to open the roscore again)
![Screenshot from 2021-05-12 11-50-46](https://user-images.githubusercontent.com/83933967/117915798-92e4fe80-b318-11eb-8571-bfa4f1892d72.png)

## 3.2 publishing the cmd_vel
Step1:
<br />
reduce publishing rate from python to arduino
<br />
Step2:
<br />
simple_controller.sh published the velocity 
<br />
![Screenshot from 2021-05-12 11-58-25](https://user-images.githubusercontent.com/83933967/117916321-87de9e00-b319-11eb-91e2-ac5cb8ac3498.png)
Step3:
<br />
rosserial_python serial_node.py send the cmd_vel to audrino
<br />
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600
<br />
*To set the same baud rate in serial and the arduino*
![Screenshot from 2021-05-12 12-01-38](https://user-images.githubusercontent.com/83933967/117916506-dee47300-b319-11eb-9953-760d2e1f2c4a.png)


## 3.3 Ubuntu terminal
tmux
<br />
ctrl+b shift+" a horizontal line
<br />
ctrl+b shift+% a vertical line
<br />
ctrl+b ->      change window on terminal

## 3.4 Quick start of program(same as type in terminal)
echo "Start"
<br />
source devel/setup.bash
<br />
rosrun demo_python demo.py
<br />
python src/demo_2.py
<br />
echo "Done"

## 3.5 change executable of program
intial white colour
<br />
*sudo chmod a+x "file name.sh"* 
<br />
after would become green 

## 3.6 waitfortransform

## 3.7 threading
python library, can run two python script in parallel.
https://blog.gtwang.org/programming/python-threading-multithreaded-programming-tutorial/

 







