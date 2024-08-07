#! /usr/bin/env python
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("talker",anonymous=True)#初始化ROS节点，talker是设定的节点名
    pub=rospy.Publisher("che",String,queue_size=10,latch=True)#创建发布者对象
    """
        rospy.Publisher("che",String,queue_size=10)
        latch(可选值)------布尔值。如果为真，会保存发布方的最后一条消息，新的订阅对象连接发布方时，发布方会将这条消息发送给订阅者
    
    """
    #编写发布逻辑病发布数据
    msg=String()#创建数据
    rate=rospy.Rate(2)#设置发布频率为1秒2次
    count=0#设定计数器初值
    rospy.sleep(2)#休眠2秒钟，等待提交注册信息给master，从而使订阅者能接收到第一条数据
    while not rospy.is_shutdown():
        count+=1
        #发布数据
        if(count<=10):
            msg.data="hello"+str(count)
            pub.publish(msg)
            rospy.loginfo("写出的数据:%s",msg.data)
        rate.sleep()



