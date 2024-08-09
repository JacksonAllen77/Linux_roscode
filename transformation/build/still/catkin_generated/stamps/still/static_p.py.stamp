#! /usr/bin/env python
import rospy
import tf.transformations
import tf2_ros #创建发布对象所需包含的头文件
from geometry_msgs.msg import TransformStamped#组织被发布消息所需包含的头文件
import tf#运用欧拉角转换成四元数所需包含的头文件
"""  
    静态坐标变换发布方:
        发布关于 laser 坐标系的位置信息 
    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建 静态坐标广播器
        4.创建并组织被广播的消息
        5.广播器发送消息
        6.spin
"""
if __name__=="__main__":
    rospy.init_node("static_pp")#初始化节点
    pub=tf2_ros.StaticTransformBroadcaster()#创建发布对象
    ts=TransformStamped()#组织被发布消息【参看坐标msg消息】
    ts.header.stamp=rospy.Time.now()
    ts.header.frame_id="base_link"
    ts.child_frame_id="laser"
    ts.transform.translation.x=0.2
    ts.transform.translation.y=0.0
    ts.transform.translation.z=0.5
    #从欧拉角转换成四元数
    qtn=tf.transformations.quaternion_from_euler(0.0,0.0,0.0)
    #再设置四元数
    ts.transform.rotation.x=qtn[0]
    ts.transform.rotation.y=qtn[1]
    ts.transform.rotation.z=qtn[2]
    ts.transform.rotation.w=qtn[3]

    #发布数据
    pub.sendTransform(ts)
    #spin()
    rospy.spin()


