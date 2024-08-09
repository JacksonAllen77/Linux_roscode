#!/usr/bin/env python3
import rospy
import tf.transformations
from turtlesim.msg import Pose#由于需要用到Pose信息，Pose消息所需包含的头文件
import tf2_ros#创建发布对象所需包含的头文件
from geometry_msgs.msg import TransformStamped#转换相对位置关系消息所需包含的头文件
import tf#欧拉角转换成四元数所需包含的头文件

"""  
    动态的坐标系相对姿态发布(一个坐标系相对于另一个坐标系的相对姿态是不断变动的)

    需求: 启动 turtlesim_node,该节点中窗体有一个世界坐标系(左下角为坐标系原点)，乌龟是另一个坐标系，键盘
    控制乌龟运动，将两个坐标系的相对位置动态发布

    实现分析:
        1.乌龟本身不但可以看作坐标系，也是世界坐标系中的一个坐标点
        2.订阅 turtle1/pose,可以获取乌龟在世界坐标系的 x坐标、y坐标、偏移量以及线速度和角速度
        3.将 pose 信息转换成 坐标系相对信息并发布
    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.订阅 /turtle1/pose 话题消息
        4.回调函数处理
            4-1.创建 TF 广播器
            4-2.创建 广播的数据(通过 pose 设置)
            4-3.广播器发布数据
        5.spin
"""
def doPose(pose):
    pub=tf2_ros.TransformBroadcaster()#创建发布坐标系相对关系的对象
    ts=TransformStamped()#将Pose位姿信息转换成坐标系相对关系消息
    ts.header.frame_id="world"
    ts.header.stamp=rospy.Time.now()
    ts.child_frame_id="turtle1"
    #子集坐标系相对于父系坐标系的偏移量
    ts.transform.translation.x=pose.x
    ts.transform.translation.y=pose.y
    ts.transform.translation.z=0
    #四元数
    #从欧拉角转换四元数
    qtn=tf.transformations.quaternion_from_euler(0,0,pose.theta)
    ts.transform.rotation.x=qtn[0]
    ts.transform.rotation.y=qtn[1]
    ts.transform.rotation.z=qtn[2]
    ts.transform.rotation.w=qtn[3]
    #发布
    pub.sendTransform(ts)

if __name__ == "__main__":
    rospy.init_node("dynamic_pp")#初始化 ROS 节点
    sub = rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=100)#创建订阅对象（话题名称，数据类型,回调函数，队列长度）
    rospy.spin()