/*
    初始化ROS节点——作用：ROS初始化函数
    参数——ros::init(argc,agrv,"play"，ros::init_options::AnonymousName)
        argc------封装实参个数（程序调用参数+1）【1为文件自身参数】
        argv------封装参数的数组
        name------自定义的节点名称【需要具有唯一性】
        options------节点启动选项
        返回值：void [无返回值]
    使用：1.argc&agrv的使用
            如果按照ROS的特定格式传入实参，则ROS可以加以使用【例如：可用于全局参数、给节点重命名等】
         2.options的使用
            节点名称需要保证唯一性，因此会导致一个问题：一个节点不能重复启动【重名节点启动时，之前运行的节点会被关闭】
            特定场景下需要一个节点多次启动且能正常运行，需要使用options给每次启动添加一个随机数，避免重名问题[ros::init_options::AnonymousName]

    

*/
#include "ros/ros.h"
#include "std_msgs/String.h"//普通文本类型的消息所需的头文件 
#include <sstream>//字符串拼接所需的头文件

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");//防止中文乱码所需的代码

    ros::init(argc,argv,"talker",ros::init_options::AnonymousName);//初始化ROS节点
    ros::NodeHandle nh;//创建ROS句柄
    ros::Publisher pub=nh.advertise<std_msgs::String>("fang",10);//创建实例化对象，话题名称为fang,队列中最大保存数为10
    //要求以10HZ频率发布数据，并且文本后添加编号
    std_msgs::String msg;//创建被发布的消息
    ros::Rate rate(1);//设定发布频率为10HZ，需要配合循环中的sleep函数
    int count=0;//设定消息计数器初值
    ros::Duration(2).sleep();//休眠2秒钟，等待提交注册信息给master，从而使订阅者能接收到第一条数据
    while(ros::ok())//编写循环，循环中发布数据
    {
        count++;
        std::stringstream ss;//使用stringstream拼接字符串与编号
        ss<<"hello--->"<<count;
        msg.data=ss.str();
        pub.publish(msg);//发布消息
        ROS_INFO("发送的消息:%s",msg.data.c_str());//加入调试，打印发送的消息
        rate.sleep();
    }
    //编写发布逻辑并发布数据
    return 0;
}