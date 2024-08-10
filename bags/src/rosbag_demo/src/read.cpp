#include "ros/ros.h"
#include "rosbag/bag.h"//创建rosbag对象所需包含的头文件
#include "rosbag/view.h"//获取消息集合所需包含的头文件
#include "std_msgs/String.h"//使用普通字符串所需包含的头文件

int main(int argc,char*argv[])
{
    ros::init(argc,argv,"read_c");//初始化ros节点
    ros::NodeHandle nh;//创建句柄
    rosbag::Bag bag;//创建rosbag对象
    //打开文件流【文件路径(此处为相对路径，在Bag文件夹下)，文件操作方式】
    bag.open("2.bag",rosbag::BagMode::Read);
    //读取数据——由于写入数据包含，因此取出数据包含【话题名称，时间戳，消息】
        //可以先获取消息的集合，再迭代取出消息的字段
    for(auto &&m:rosbag::View(bag))
    {
        setlocale(LC_ALL,"");//避免中文乱码
        std::string topic=m.getTopic();//获取话题名称
        ros::Time time=m.getTime();//获取时间
        std_msgs::StringPtr p=m.instantiate<std_msgs::String>();//获取具体消息
        ROS_INFO("解析的内容:话题名称:%s,时间戳:%.2f,消息内容:%s",topic.c_str(),time.toSec(),p->data.c_str());//输出上述信息
    }   
    
    //关闭文件流    
    bag.close();
    return 0;
}