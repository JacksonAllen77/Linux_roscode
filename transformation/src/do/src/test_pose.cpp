#include "ros/ros.h"
#include "turtlesim/Pose.h"//传入参数用到Pose信息，需要包含该头文件
#include "tf2_ros/transform_broadcaster.h"//创建动态发布对象所需包含的头文件
#include "geometry_msgs/TransformStamped.h"//组织被发布消息所需包含的头文件
#include "tf2/LinearMath/Quaternion.h"//将欧拉角转换成四元数所需包含的头文件

//声明变量来接受传入的参数
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    //获取位姿信息，转换成坐标系相对关系，并发布
    static tf2_ros::TransformBroadcaster pub;//创建发布对象[通过static使得每次创建发布对象均采用同一个对象]
    geometry_msgs::TransformStamped ts;//组织被发布的数据
    ts.header.frame_id="world";//参考坐标系
        //关键点2. 此处的frame_id也是动态传入的 
    ts.child_frame_id=turtle_name;//小乌龟的坐标系名称
    ts.header.stamp=ros::Time::now();//时间戳
    //坐标系偏移量设置
    ts.transform.translation.x=pose->x;//从pose获取x,y,z的偏移量
    ts.transform.translation.y=pose->y;
    ts.transform.translation.z=0;
    //坐标系四元数设置
    //位姿信息中没有四元数，但小乌龟有偏航信息，又已知乌龟是2D的，因此没有翻滚和俯仰角度，
    //所以可以得出乌龟的欧拉角——0,0,theta
    tf2::Quaternion qtn;//创建四元数对象
    qtn.setRPY(0,0,pose->theta);//设置其欧拉角信息
    ts.transform.rotation.x=qtn.getX();//四元数
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();
    //发布
    pub.sendTransform(ts);

}

int main(int argc,char*argv[])
{
    setlocale(LC_ALL,"");//避免中文乱码问题
    ros::init(argc,argv,"dynamic_p");//初始化ros对象
    ros::NodeHandle nh;//创建ros句柄
    if(argc !=2)
    {
        ROS_ERROR("请传入一个参数");
        return 1;
    }
    else
    {
        turtle_name=argv[1];
    }
   
   
        //修改的关键点
        //关键点1.订阅的两只乌龟的话题名称是动态传入的
    ros::Subscriber sub=nh.subscribe(turtle_name+"/pose",100,doPose);//创建订阅对象（话题名称，队列长度，回调函数）
    ros::spin();

}