#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/*
    编写 ROS 节点，控制小乌龟画圆

    准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建发布者对象
        4.循环发布运动控制消息
*/
int main(int agrc,char*agrv[])
{
    ros::init(agrc,agrv,"my_control");//初始化节点
    ros::NodeHandle nh;//创建节点句柄
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);//创建发布对象<泛型>（话题名称，队列长度）
    //5.发布逻辑
    ros::Rate rate(10);//设置发布频率,需要配合循环中的休眠一起使用
    //组织被发布的消息
    geometry_msgs::Twist twist;
    twist.linear.x=1.0;//前后移动
    twist.linear.y=0.0;//左右移动
    twist.linear.z=0.0;//上下移动
    twist.angular.x=0.0;//偏航
    twist.angular.y=0.0;//俯仰
    twist.angular.z=0.5;//翻滚
    //循环发布
    while (ros::ok())
    {
        pub.publish(twist);//发布消息
        rate.sleep();//休眠
        ros::spinOnce();//回头
    }

    return 0;
}