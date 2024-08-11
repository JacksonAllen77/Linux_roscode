#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"srv_spawn");//初始化 ROS 节点
    ros::NodeHandle nh;//创建节点句柄
    ros::ServiceClient client=nh.serviceClient<turtlesim::Spawn>("/spawn");//创建客户端对象<泛型>（话题名称）
    //组织请求数据
    turtlesim::Spawn spawn;//
    spawn.request.x=1.0;
    spawn.request.y=4.0;
    spawn.request.theta=1.57;
    spawn.request.name="turtle2";
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