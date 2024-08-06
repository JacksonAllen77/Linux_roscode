#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist  # 导入 Twist 消息类型

"""
    编写 ROS 节点，控制小乌龟画圆

    准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建发布者对象
        4.循环发布运动控制消息
"""

if __name__ == "__main__":  
    rospy.init_node("my_control_p")  # 初始化节点
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)  # 创建发布者对象（话题名称，消息类型，队列长度）
    
    # 创建速度消息
    twist = Twist()
    twist.linear.x = 1.0  # 前后移动
    twist.linear.y = 0.0  # 左右移动
    twist.linear.z = 0.0  # 上下移动
    twist.angular.x = 0.0  # 偏航
    twist.angular.y = 0.0  # 俯仰
    twist.angular.z = 0.5  # 翻滚
    
    rate = rospy.Rate(10)  # 设置发布频率
    
    # 循环发布
    while not rospy.is_shutdown():
        pub.publish(twist)  # 发布消息
        rate.sleep()  # 休眠
    
