#include "ros/ros.h"
#include "head_body_cpp/head.h"


int main(int argc,char*argv[])
{
    setlocale(LC_ALL, "");//防止中文乱码所需要的代码
    ros::init(argc,argv,"hello_src");
    head_my::Myhello hello;
    hello.run();

    return 0;
}