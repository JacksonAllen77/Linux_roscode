#! /usr/bin/env python
"""
    订阅小乌龟的位姿: 时时获取小乌龟在窗体中的坐标并打印
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点

    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建订阅者对象
        4.回调函数处理订阅的数据
        5.spin

"""

import rospy
from turtlesim.msg import Pose

def doPose(pose):
    rospy.loginfo("乌龟的位姿信息：坐标（%.2f,%.2f),朝向: %.2f,线速度:%.2f ,角速度:%.2f",
                  pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)
if __name__=="__main__":
    rospy.init_node("sub_pose_p")#初始化ROS节点
    sub=rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=10)#创建订阅对象
    rospy.spin()#处理订阅到的数据（回调函数）

    