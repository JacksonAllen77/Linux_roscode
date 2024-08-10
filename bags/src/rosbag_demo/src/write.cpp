#include "ros/ros.h"
#include "rosbag/bag.h"//创建rosbag对象所需包含的头文件
#include "std_msgs/String.h"//使用普通字符串所需包含的头文件
int main(int argc,char*argv[])
{
    ros::init(argc,argv,"write_c");//初始化ros节点
    ros::NodeHandle nh;//创建句柄
    rosbag::Bag bag;//创建rosbag对象
    bag.open("2.bag",rosbag::BagMode::Write);//打开文件流【文件路径(此处为相对路径，在Bag文件夹下)，文件操作方式】
    //写数据
    std_msgs::String msg;//创建消息对象
    msg.data="hello world";
    bag.write("/chat",ros::Time::now(),msg);//【话题名称，时间戳，消息】
    bag.close();//关闭文件流
}