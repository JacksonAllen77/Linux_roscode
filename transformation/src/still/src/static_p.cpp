#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"//创建发布对象所需的头文件
#include "geometry_msgs/TransformStamped.h"//使用TransformStamped坐标关系所需的头文件
#include "tf2/LinearMath/Quaternion.h"//通过欧拉角转换四元数对象
/* 
    静态坐标变换发布方:
        发布关于 laser 坐标系的位置信息 
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建发布对象
        4.组织被发布的消息
        5.发布消息
        6.spin()
*/
int main(int argc,char*argv[])
{   
    setlocale(LC_ALL,"");//避免中文出现乱码
    ros::init(argc,argv,"static_p");//初始化ros节点
    ros::NodeHandle nh;//创建节点句柄
    tf2_ros::StaticTransformBroadcaster pub;//创建发布对象
    geometry_msgs::TransformStamped tfs;//组织被发布的消息
    tfs.header.stamp=ros::Time::now();//时间戳
    tfs.header.frame_id="base_link";//参考坐标系命名
    tfs.child_frame_id="laser";//另一个坐标系
    tfs.transform.translation.x=0.2;//X偏移量
    tfs.transform.translation.y=0.0;//X偏移量
    tfs.transform.translation.z=0.5;//X偏移量
    //需要根据欧拉角转换
    tf2::Quaternion qtn;//创建四元数对象
    //向该对象设置欧拉角，这个对象可以将欧拉角转换成四元数
    qtn.setRPY(0.0,0.0,0.0);//欧拉角的单位为弧度制【180°写3.14】
    tfs.transform.rotation.x=qtn.getX();//四元数
    tfs.transform.rotation.y=qtn.getY();
    tfs.transform.rotation.z=qtn.getZ();
    tfs.transform.rotation.w=qtn.getW();
    pub.sendTransform(tfs); //发布数据
    ros::spin();//spin
    return 0;
}
