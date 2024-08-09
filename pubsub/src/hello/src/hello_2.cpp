#include "ros/ros.h"
int main(int argc,char*argv[])
{
    setlocale(LC_ALL, "");//防止中文乱码所需要的代码
    ros::init(argc,argv,"hello2");
    ROS_INFO("这是hellovscode的hello1");
    return 0;
}