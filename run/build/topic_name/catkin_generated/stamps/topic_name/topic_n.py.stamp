#! /usr/bin/env python
import rospy
from std_msgs.msg import String

if __name__ =="__main__":
    rospy.init_node("topic_namep")#初始化ROS节点
    # 核心操作——设置不同类型的话题
    #1.全局话题设置
    pub1=rospy.Publisher("/chatter_g",String,queue_size=10)
    pub2=rospy.Publisher("/yyy/chatter_g",String,queue_size=10)
    #2.相对话题设置
    pub3=rospy.Publisher("chatter_c",String,queue_size=10)
    pub4=rospy.Publisher("zzz/chatter_c",String,queue_size=10)
    #3.私有话题设置
    pub5=rospy.Publisher("~chatter_p",String,queue_size=10)
    pub6=rospy.Publisher("~aaa/chatter_p",String,queue_size=10)

    while not rospy.is_shutdown():
        pass