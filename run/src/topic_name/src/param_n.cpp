#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc,char*argv[])
{
    ros::init(argc,argv,"param_name");//初始化ros节点
    ros::NodeHandle nh;//创建句柄
    //1.全局
    ros::param::set("/radius1",100);
    //2.全局
    ros::param::set("radius2",100);
    //3.私有
    ros::param::set("~radius3",100);
   while(ros::ok())
   {

   }
   return 0;

}//全局话题与私有话题同时存在时，全局话题优先级更高