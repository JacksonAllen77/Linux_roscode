#!/usr/bin/env python3
import rospy
import rosbag#创建rosbag所需包含的头文件
from std_msgs.msg import String#使用字符串所需包含的头文件

if __name__ == "__main__":
    rospy.init_node("write_p")#初始化ros节点
    bag=rosbag.Bag("3.bag","w")#创建rosbag对象并打开文件流（文件输出路径[此处采用相对路径]，操作模式）
    #写数据
    msg=String()
    msg.data="hellobag"
    bag.write("/liaotian",msg)#话题名称，消息，时间（采用默认值）
    #关闭文件流
    bag.close()
    