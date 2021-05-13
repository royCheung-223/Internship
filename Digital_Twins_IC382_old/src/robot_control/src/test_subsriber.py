#!/usr/bin/env python2.7

import rospy
from std_msgs.msg import Int64
def callback(data):
 print(data.data)                                #print the received message from rostopic
def listener_new():
 rospy.init_node('listener', anonymous=True)     #initial the node called "listener"
 rospy.Subscriber("chatter", Int64, callback)    #subscribe the rostopic "chatter"
 rospy.spin()                                    
if __name__ == '__main__':
 listener_new()
