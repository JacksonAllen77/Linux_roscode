#include "ros/ros.h"
#include "turtlesim/Spawn.h"
/*
    生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.包含头文件
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 ros 句柄
        4.创建 service 客户端
        5.等待服务启动
        6.发送请求
        7.处理响应

*/
int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"srv_spawn");//初始化 ROS 节点
    ros::NodeHandle nh;//创建节点句柄
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");//创建客户端对象<泛型>（话题名称）
    //组织请求数据
    turtlesim::Spawn spawn;//
    spawn.request.x=10.0;
    spawn.request.y=5.0;
    spawn.request.theta=3.14;
    spawn.request.name="cat";
    //等待服务器状态，并发送请求
    client.waitForExistence();//等待服务器启动
    bool flag = client.call(spawn);//将spawn对象的数据发送到服务器,falg用于接受响应状态，结果也会被设置进spawn对象
    //处理响应
    if(flag)
    {
        ROS_INFO("新乌龟生成成功！！，新乌龟名称为%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("新乌龟生成失败！！");
    }
    return 0;
}