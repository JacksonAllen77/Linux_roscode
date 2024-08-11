#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__ =="__main__":
    rospy.init_node("topic_namep")#初始化ROS节点
    #1.全局
    rospy.set_param("/radius1",100)
    #2.相对
    rospy.set_param("radius2",100)
    #3.私有
    rospy.set_param("~radius3",100)

    while not rospy.is_shutdown():
        pass