#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"//创建订阅对象所需包含的头文件
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"//创建坐标点所需包含的头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"//运用坐标系之间关系所需包含的头文件

/*

需求:
    现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，
    son1 相对于 world，以及 son2 相对于 world 的关系是已知的，
    求 son1 与 son2中的坐标关系，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin
*/
int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"many_s");//初始化 ros 节点
    ros::NodeHandle nh();//创建 ros 句柄
    //创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    //创建坐标点
    geometry_msgs::PointStamped psSon1;
    psSon1.header.stamp=ros::Time::now();//编写该坐标点具体信息
    psSon1.header.frame_id="son1";
    psSon1.point.x=1.0;
    psSon1.point.y=2.0;
    psSon1.point.z=3.0;
    //编写解析逻辑
    ros::Rate rate(10);//以1秒10次进行接收发布方的数据
    while(ros::ok())
    {
        try
        {
            //计算son1与son2的相对关系
            geometry_msgs::TransformStamped son1to2=buffer.lookupTransform("son2","son1",ros::Time(0));//目标坐标系，原坐标系，取两个坐标系最近一次的时间计算相对关系
            ROS_INFO("son1相对于son2的信息:父坐标系名称:%s,子坐标系名称:%s,偏移量信息:(%.2f,%.2f,%.2f)",son1to2.header.frame_id.c_str(),son1to2.child_frame_id.c_str(),son1to2.transform.translation.x,son1to2.transform.translation.y,son1to2.transform.translation.z);
            //计算son1中的某个坐标点在son2的坐标值
            geometry_msgs::PointStamped psSon2=buffer.transform(psSon1,"son2");//被转换的坐标点，目标坐标系
            ROS_INFO("坐标点在son2中的值:(%.2f,%.2f,%.2f)",psSon2.point.x,psSon2.point.y,psSon2.point.z);
        }
        catch(const std::exception &e)
        {
            ROS_INFO("错误信息为:%s",e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }
}