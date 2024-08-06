#include "ros/ros.h"
/*
    需求：修改参数服务器中turtlesim 背景色相关的参数
    1.初始化节点
    2.用于采用NodeHandle接口，因此需要创建节点句柄等
    2.修改参数
*/
int main(int argc,char*argv[])
{
    ros::init(argc,argv,"param_colour");//初始化ros节点
    ros::NodeHandle nh("turtlesim");//创建节点句柄
    nh.setParam("background_r",125);//设置参数
    nh.setParam("background_g",125);
    nh.setParam("background_b",0);
    return 0;
}