#include "ros/ros.h"
int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");//避免中文乱码
    ros::init(argc,argv,"log");
    ros::NodeHandle nh;
    //日志输出
    ROS_DEBUG("调试信息，不输出");
    ROS_INFO("一般信息，输出为白色");
    ROS_WARN("警告信息，输出为黄色");
    ROS_ERROR("错误信息，输出为红色，程序不会终端");
    ROS_FATAL("严重错误信息，输出为红色，程序会终端");
    return 0;
}