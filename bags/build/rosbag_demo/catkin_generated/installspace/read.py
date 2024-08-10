#!/usr/bin/env python3
import rospy
import rosbag#创建rosbag所需包含的头文件
from std_msgs.msg import String#使用字符串所需包含的头文件

if __name__ == "__main__":
    rospy.init_node("write_p")#初始化ros节点
    bag=rosbag.Bag("3.bag","r")#创建rosbag对象并打开文件流（文件输出路径[此处采用相对路径]，操作模式）
    #读取数据
    msgs=bag.read_messages("/liaotian")
    for topic,msg,time in msgs:
        rospy.loginfo(f"话题名称{topic},消息{msg.data},时间戳{time}")
    #关闭文件流
    bag.close()
    