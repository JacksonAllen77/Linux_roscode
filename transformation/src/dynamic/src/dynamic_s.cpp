#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"//创建订阅对象所需包含的头文件
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"//组织坐标点数据所需包含的头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"//转换坐标系时所需包含的头文件

int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");//避免中文乱码问题
    ros::init(argc,argv,"dynamic_s");//初始化节点
    ros::NodeHandle nh;//创建节点句柄
    //创建订阅对象
    tf2_ros::Buffer buffer; //创建一个buffer缓存
    tf2_ros::TransformListener listenen(buffer);//再创建一个订阅对象【订阅对象可以将收到的数据放入缓存中】
    geometry_msgs::PointStamped ps;//组织一个坐标系数据【具体下方的消息设置参看坐标msgs消息】
    //参考坐标系
    ps.header.frame_id="turtle1";//小乌龟坐标系名称
    ps.header.stamp=ros::Time(0.0);
    ps.point.x=2.0;
    ps.point.y=3.0;
    ps.point.z=5.0;
    //转换算法，需要调用TF内置实现
    // ros::Duration(2).sleep();//添加休眠，以保证接收到发布方的消息
    ros::Rate rate(10);//1秒10次接受
    while(ros::ok())
    {   //核心代码——将ps转换成相对于base_link的坐标点
        geometry_msgs::PointStamped ps_out;
        try
        {
            ps_out=buffer.transform(ps,"world");//被转换坐标系点、转换的参考坐标系
            //输出
            ROS_INFO("转换后的坐标值:(%.2f,%.2f,%.2f),参考坐标系:%s",ps_out.point.x,ps_out.point.y,ps_out.point.z,ps_out.header.frame_id.c_str());
            
        }
        catch(const std::exception& e)
        {
            ROS_INFO("异常消息为:%s",e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}