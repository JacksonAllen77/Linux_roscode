
#include "ros/ros.h"
#include "std_msgs/String.h"//普通文本类型的消息所需的头文件 
#include <sstream>//字符串拼接所需的头文件

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");//防止中文乱码所需的代码

    ros::init(argc,argv,"talker",ros::init_options::AnonymousName);//初始化ROS节点
    ros::NodeHandle nh;//创建ROS句柄
    ros::Publisher pub=nh.advertise<std_msgs::String>("fang",10,true);//创建实例化对象，话题名称为fang,队列中最大保存数为10

    /*
    话题服务对象
    作用：创建发布者对象
    模版——被发布的消息的类型
    参数——ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<std_msgs::String>("fang",10)
        advertise("fang",10)
        话题名称——自定义的话题名称
        队列长度——
        latch(可选)——布尔值。如果为真，会保存发布方的最后一条消息，新的订阅对象连接发布方时，发布方会将这条消息发送给订阅者
        如果为假，则不会保存，则将不会发送任何消息【默认为真】
    使用——1.latch设置为真的作用？【以静态地图发布为例，方案1：可以以固定频率发送地图数据，但效率低；
    方案2：将latch设置为true，每当新的订阅者连接时，将地图信息只发送一次数据给订阅者，提高了运行效率】
*/
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
        if(count<=10)
        {
            pub.publish(msg);//发布消息
            ROS_INFO("发送的消息:%s",msg.data.c_str());//加入调试，打印发送的消息
        }
        rate.sleep();
    }
    //编写发布逻辑并发布数据
    return 0;
}