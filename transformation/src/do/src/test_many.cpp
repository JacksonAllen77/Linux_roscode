#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"//创建订阅对象所需包含的头文件
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"//创建坐标点所需包含的头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"//运用坐标系之间关系所需包含的头文件
#include "geometry_msgs/Twist.h"//创建发布对象所需包含的头文件

/*

需求:
    1.需要换算出乌龟1相对于乌龟2的关系
    2.计算角速度和线速度并发布
*/
int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"many_s");//初始化 ros 节点
    ros::NodeHandle nh;//创建 ros 句柄
    //创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    //创建发布速度对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);//需要控制的乌龟的话题名,队列长度


    //编写解析逻辑
    ros::Rate rate(10);//以1秒10次进行接收发布方的数据
    while(ros::ok())
    {
        try
        {
            //1.计算son1与son2的相对关系
            geometry_msgs::TransformStamped son1to2=buffer.lookupTransform("turtle2","turtle1",ros::Time(0));//目标坐标系，原坐标系，取两个坐标系最近一次的时间计算相对关系
            ROS_INFO("乌龟2相对于乌龟1的信息:父坐标系名称:%s,子坐标系名称:%s,偏移量信息:(%.2f,%.2f,%.2f)",son1to2.header.frame_id.c_str(),son1to2.child_frame_id.c_str(),son1to2.transform.translation.x,son1to2.transform.translation.y,son1to2.transform.translation.z);
           //2.根据相对计算并组织速度消息
            geometry_msgs::Twist twist;//创建消息对象
            //组织速度——只需要设置线速度x与角速度z
            //线速度x=系数*根号（x^2+y^2）
            //角速度z=系数*arctan(y/x)
            twist.linear.x=0.5*sqrt(pow(son1to2.transform.translation.x,2)+pow(son1to2.transform.translation.y,2));//组织速度
            twist.linear.y=0;
            twist.linear.z=0;
            twist.angular.x=0;
            twist.angular.y=0;
            twist.angular.z=4*atan2(son1to2.transform.translation.y,son1to2.transform.translation.x);
           //3.发布消息
           pub.publish(twist);
        }
        catch(const std::exception &e)
        {
            ROS_INFO("错误信息为:%s",e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }
}