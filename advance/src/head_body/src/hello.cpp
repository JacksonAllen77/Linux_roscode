#include "ros/ros.h"
#include "head_body/head.h"
namespace head_my
{
    void Myhello::run()
    {
        ROS_INFO("run函数执行---");
    }
}

int main(int argc,char*argv[])
{
    setlocale(LC_ALL, "");//防止中文乱码所需要的代码
    ros::init(argc,argv,"hello_head");
    head_my::Myhello hello;
    hello.run();
    return 0;
}