#! /usr/bin/env python
import rospy
import tf.transformations
from turtlesim.msg import Pose#由于需要用到Pose信息，Pose消息所需包含的头文件
import tf2_ros#创建发布对象所需包含的头文件
from geometry_msgs.msg import TransformStamped#转换相对位置关系消息所需包含的头文件
import tf#欧拉角转换成四元数所需包含的头文件
import sys#解析参数所需包含的头文件

turtle_name=""#通过变量接受乌龟名称
def doPose(pose):
    pub=tf2_ros.TransformBroadcaster()#创建发布坐标系相对关系的对象
    ts=TransformStamped()#将Pose位姿信息转换成坐标系相对关系消息
    ts.header.frame_id="world"
    ts.header.stamp=rospy.Time.now()
    #修改2——子集坐标系名称
    ts.child_frame_id=turtle_name
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
    if len(sys.argv)!=4:#解析传入的参数（一共4个参数——文件全路径+传入的参数+节点名称+日志文件路径）
    
        rospy.loginfo("参数个数不对")
        sys.exit(1)
    else:
        turtle_name=sys.argv[1]

    #修改1——话题名称采用动态传入的方式
    sub = rospy.Subscriber(turtle_name+"/pose",Pose,doPose,queue_size=100)#创建订阅对象（话题名称，数据类型,回调函数，队列长度）
    rospy.spin()