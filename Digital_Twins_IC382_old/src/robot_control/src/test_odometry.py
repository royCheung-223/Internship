#!/usr/bin/env python2.7

"""
This is a very simple control script to test the robot.
q : turn the robot to left  (angular z += basic left)
e : turn the robot to right (angular z += basic right)
w : add forward power
x : reset
"""
import time
import rospy
import roslib
import os
import tf
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3
from std_msgs.msg import Int64
from pynput import keyboard
from math import pi, sin, cos
from nav_msgs.msg import Odometry
from tf.broadcaster import TransformBroadcaster
    
wheeltrack = 0.295
wheelradius = 0.0325
left_ticks = 0
right_ticks = 0
last_left_ticks = 0
last_right_ticks = 0
TPR = 1000


x = 0.0
y = 0.0
th = 0.0
    
vx =  0.0
vy =  0.0
vth =  0.0



basic_velocity_x = -0.05

x_step = -0.05
left_step = 0.05
right_step = -0.05

adjust = 0
power = basic_velocity_x


def ros_setup():
    #starts a new node
    rospy.init_node('robot', anonymous=True)
    velocity_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    vel_msg = Twist()
    return vel_msg,velocity_publisher
    
def on_press (key):
    global adjust,power
    try:
        if(key.char=='q'):
            #Turn Left
            adjust += left_step
        if(key.char=='e'):
            #Turn Right
            adjust += right_step
        if(key.char=='w'):
            #Forward (increase the speed)
            power += x_step
            adjust = 0
        if(key.char=='x'):
            #Stop
            power = 0
            adjust = 0         
    except AttributeError:
        print('special key {0} pressed'.format(key))

def on_release(key):
    #print('{0} released'.format(key))
    if key == keyboard.Key.esc:
        # Stop listener
        return False

def callbackL(data):
   # print("encoderL:")
    global right_ticks
    right_ticks = data.data
   # print(right_ticks)                                #print the received message from rostopic

def callbackR(data):
   # print("encoderR:")
   # print(data.data)                                #print the received message from rostopic
    global left_ticks
    left_ticks = data.data
    
    
def main():

    speed_msg,ros_publisher = ros_setup()
    print("ROS node initialization is done!")
    #This script supported keyboard control
    listener = keyboard.Listener(on_press=on_press,on_release=on_release)
    rospy.Subscriber("chatter", Int64, callbackL)    #subscribe the rostopic "chatter"
    rospy.Subscriber("chatterR", Int64, callbackR)
    odom_pub = rospy.Publisher("testodom", Odometry, queue_size=50)
    odom_broadcaster = tf.TransformBroadcaster()
    last_time = rospy.Time(secs=1, nsecs=1)
    r = rospy.Rate(10)
    listener.start()
    while not rospy.is_shutdown():
        speed_msg.linear.x = power
        speed_msg.linear.y = 0
        speed_msg.linear.z = 0
        speed_msg.angular.x = 0
        speed_msg.angular.y = 0
        global adjust
        speed_msg.angular.z = adjust
        print(speed_msg)
        global last_left_ticks
        global last_right_ticks
        global x
        global y
        global th
        global vx
        global vy
        global vth
        ros_publisher.publish(speed_msg)
        current_time = rospy.Time.now()
        delta_L = left_ticks - last_left_ticks
        delta_R = right_ticks - last_right_ticks
        dt = (current_time - last_time).to_sec()
        print(current_time)
        dl = 2 * pi * wheelradius * delta_L / TPR / dt
        dr = 2 * pi * wheelradius * delta_R / TPR / dt
        vl = dl * wheelradius 
        vr = dr * wheelradius 
        vx = (vl + vr) / 2
        vy = 0
        vth = (vr-vl)/wheeltrack

        
        dx = vx * cos(th) * dt
        dy = vx * sin(th) * dt
        dth = vth * dt
        print(dx)
        x += dx  
        y += dy 
        th += dth

        odom_quat = tf.transformations.quaternion_from_euler(0, 0, th)

        odom_broadcaster.sendTransform(
           (x, y, 0.),
           odom_quat,
           current_time,
           "chassis",
           "odom"
        )


        odom = Odometry()
        odom.header.stamp = current_time
        odom.header.frame_id = "odom"
        odom.pose.pose = Pose(Point(x, y, 0.), Quaternion(*odom_quat))

        if dt>0:
            vx=dx/dt
            vy=dy/dt
            vth=dth/dt

        odom.child_frame_id = "chassis"
        odom.twist.twist = Twist(Vector3(vx, vy, 0), Vector3(0, 0, vth))

        odom_pub.publish(odom)

        last_left_ticks = left_ticks
        last_right_ticks = right_ticks
        last_time = current_time
        time.sleep(1)
    
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException: pass


