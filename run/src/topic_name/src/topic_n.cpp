#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc,char*argv[])
{
    ros::init(argc,argv,"topic_name");//初始化ros节点
    // ros::NodeHandle nh;//创建句柄
    //核心操作——设置不同类型的话题
    //1.全局话题设置【全局话题——以/开头且可通过【/命令空间/话题名称】设置话题自己的命名空间；与节点名称无关】
    // ros::Publisher pub1=nh.advertise<std_msgs::String>("/topic_g",100);//话题名称，队列长度
    // ros::Publisher pub2=nh.advertise<std_msgs::String>("/yyy/topic_g",100);//话题名称，队列长度
    // //2.相对话题设置【相对话题——无/且可通过【/yyy/话题名称】做累加,与节点的命名空间有关】
    // ros::Publisher pub3=nh.advertise<std_msgs::String>("topic_c",100);//话题名称，队列长度
    // ros::Publisher pub4=nh.advertise<std_msgs::String>("zzz/topic_c",100);//话题名称，队列长度
    // 3.私有话题设置【私有话题——需要创建特定NodeHandle且可通过【命名空间/话题名称】做累加，与节点名称有关】
    ros::NodeHandle nh("~");
    ros::Publisher pub5=nh.advertise<std_msgs::String>("topic_c",100);//话题名称，队列长度
    ros::Publisher pub6=nh.advertise<std_msgs::String>("aaa/topic_c",100);//话题名称，队列长度
   while(ros::ok())
   {

   }
   return 0;

}//全局话题与私有话题同时存在时，全局话题优先级更高