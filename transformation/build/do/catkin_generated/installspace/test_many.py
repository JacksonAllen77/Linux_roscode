#!/usr/bin/env python3
import rospy
import tf2_ros#创建订阅对象所需包含的头文件
from tf2_geometry_msgs import tf2_geometry_msgs#组织被转换的坐标点所需包含的头文件
from geometry_msgs import Twist#创建发布消息Twist所需包含的头文件
import math#数学计算所需包含的头文件


if __name__=="__main__":
    rospy.init_node("static_sp")#初始化节点
    #创建订阅对象
    buffer=tf2_ros.Buffer()#创建缓存对象
    sub=tf2_ros.TransformListener(buffer)#创建订阅对象（将所订阅的数据传入缓存中）
    
    #创建速度消息发布对象
    pub=rospy.Publisher("/turtle2/cmd_vel",Twist,queue_size=100)

    #转换逻辑实现，调用tf封装的算法
    # rospy.sleep(2)#通过休眠以接受完发布方的数据
    rate=rospy.Rate(10)#以1秒10次去接受发布方的数据
    while not rospy.is_shutdown():
        try:
            #计算son1相对于son2的坐标关系
            ts=buffer.lookup_transform("turtle2","trutle1",rospy.Time(0))#目标坐标系，源坐标系，两者最近一次更新的时间差
            rospy.lohginfo("父系坐标系名称:%s ,子系坐标系名称:%s ,偏移值:(%.2f,%.2f,%.2f)",ts.header.frame_id,ts.child_frame_id,ts.transform.translation.x,ts.transform.translation.y,ts.transform.translation.z)
            #组织Twist消息并发布
            twist=Twist()
            twist.linear.x=0.5*math.sqrt(math.pow(ts.transform.translation.x,2)+math.pow(ts.transform.translation.y,2))#线速度只需要设置x其余为0,线速度=系数*根号（x^2+y^2）
            twist.linear.y=0
            twist.linear.z=0
            twist.angular.x=0
            twist.angular.y=0
            twist.angular.z=0.5*math.atan2(ts.transform.translation.y,ts.transform.translation.x)#角速度只需设置z其余为0，角速度=arctan(y/x)
            

            #发布消息
            pub.publish(twist)
        except Exception as e:
            rospy.logwarn("错误信息:%s",e)
        
        rate.sleep()


    
    
