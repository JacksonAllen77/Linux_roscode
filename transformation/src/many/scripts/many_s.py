#! /usr/bin/env python
import rospy
import tf2_ros#创建订阅对象所需包含的头文件
from tf2_geometry_msgs import tf2_geometry_msgs#组织被转换的坐标点所需包含的头文件
from geometry_msgs import TransformStamped
"""  
    订阅坐标系信息，生成一个相对于 子级坐标系的坐标点数据，
    转换成父级坐标系中的坐标点

    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建 TF 订阅对象
        4.创建一个 radar 坐标系中的坐标点
        5.调研订阅对象的 API 将 4 中的点坐标转换成相对于 world 的坐标
        6.spin

"""


if __name__=="__main__":
    rospy.init_node("static_sp")#初始化节点
    #创建订阅对象
    buffer=tf2_ros.Buffer()#创建缓存对象
    sub=tf2_ros.TransformListener(buffer)#创建订阅对象（将所订阅的数据传入缓存中）
    #组织被转换的坐标点
    ps=tf2_geometry_msgs.PointStamped()#组织被发布消息【参看坐标msgs消息】
    ps.header.stamp=rospy.Time.now()
    ps.header.frame_id="son1"#参考坐标点
    ps.point.x=1.0
    ps.point.y=2.0
    ps.point.z=3.0
    #转换逻辑实现，调用tf封装的算法
    # rospy.sleep(2)#通过休眠以接受完发布方的数据
    rate=rospy.Rate(10)#以1秒10次去接受发布方的数据
    while not rospy.is_shutdown():
        try:
            #计算son1相对于son2的坐标关系
            ts=buffer.lookup_transform("son2","son1",rospy.Time(0))
            rospy.lohginfo("父系坐标系名称:%s ,子系坐标系名称:%s ,偏移值:(%.2f,%.2f,%.2f)",ts.header.frame_id,ts.child_frame_id,ts.transform.translation.x,ts.transform.translation.y,ts.transform.translation.z)
            #转换实现
            ps_out=buffer.transform(ps,"son2")#被转换的坐标点、目标坐标系
            #输出结果
            rospy.loginfo("转换后的坐标值:(%.2f,%.2f,%.2f),参考坐标系:%s",ps_out.point.x,ps_out.point.y,ps_out.point.z,ps_out.header.frame_id)
        except Exception as e:
            rospy.logwarn("错误信息:%s",e)
        
        rate.sleep()


    
    
