#include "ros/ros.h"
/*
    需求：修改参数服务器中turtlesim 背景色相关的参数
    1.初始化节点
    2.用于采用param接口，因此不需要创建节点句柄
    2.修改参数
*/
int main(int argc,char*argv[])
{
    ros::init(argc,argv,"param_colour");//初始化ros节点
    //由于采用param接口，因此不需要创建节点句柄
    ros::param::set("/turtlesim/background_r",0);
    ros::param::set("/turtlesim/background_g",125);
    ros::param::set("/turtlesim/background_b",125);
    return 0;
}