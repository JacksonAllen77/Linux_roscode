#! /usr/bin/env python
import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("talker",anonymous=True)#初始化ROS节点，talker是设定的节点名
    """
        作用：ROS初始化函数
        参数——rospy.init_node(argc,agrv,"play",anonymous)
            argc------封装实参个数（程序调用参数+1）【1为文件自身参数】
            argv------默认为None(空)，封装节点调用时传递的参数
            anonymous=False------节点名称生成随机后缀，可以解决重名问题
            
        使用——1.agrv的使用
            如果按照ROS的特定格式传入实参，则ROS可以加以使用【例如：可用于全局参数、给节点重命名等】
         2.anonymous的使用
            节点名称需要保证唯一性，因此会导致一个问题：一个节点不能重复启动【重名节点启动时，之前运行的节点会被关闭】
            特定场景下需要一个节点多次启动且能正常运行，需要使用options给每次启动添加一个随机数，避免重名问题[anonymous=True]


    """
    pub=rospy.Publisher("che",String,queue_size=10)#创建发布者对象
    #编写发布逻辑病发布数据
    msg=String()#创建数据
    rate=rospy.Rate(2)#设置发布频率为1秒2次
    count=0#设定计数器初值
    rospy.sleep(2)#休眠2秒钟，等待提交注册信息给master，从而使订阅者能接收到第一条数据
    while not rospy.is_shutdown():
        count+=1
        msg.data="hello"+str(count)
        #发布数据
        pub.publish(msg)
        rospy.loginfo("写出的数据:%s",msg.data)
        rate.sleep()



