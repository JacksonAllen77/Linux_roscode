#include "ros/ros.h"
#include "turtlesim/Pose.h"//传入参数用到Pose信息，需要包含该头文件
#include "tf2_ros/transform_broadcaster.h"//创建动态发布对象所需包含的头文件
#include "geometry_msgs/TransformStamped.h"//组织被发布消息所需包含的头文件
#include "tf2/LinearMath/Quaternion.h"//将欧拉角转换成四元数所需包含的头文件


/*  
    动态的坐标系相对姿态发布(一个坐标系相对于另一个坐标系的相对姿态是不断变动的)

    需求: 启动 turtlesim_node,该节点中窗体有一个世界坐标系(左下角为坐标系原点)，乌龟是另一个坐标系，键盘
    控制乌龟运动，将两个坐标系的相对位置动态发布

    实现分析:
        1.乌龟本身不但可以看作坐标系，也是世界坐标系中的一个坐标点
        2.订阅 turtle1/pose,可以获取乌龟在世界坐标系的 x坐标、y坐标、偏移量以及线速度和角速度
        3.将 pose 信息转换成 坐标系相对信息并发布

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅对象
        5.回调函数处理订阅到的数据(实现TF广播)
            5-1.创建 TF 广播器
            5-2.创建 广播的数据(通过 pose 设置)
            5-3.广播器发布数据
        6.spin
*/

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
    if(argc !=2)
    {
        ROS_ERROR("请传入一个参数");
        return 1;
    }
    else
    {
        turtle_name=argv[1];
    }
   
    ros::init(argc,argv,"dynamic_p");//初始化ros对象
    ros::NodeHandle nh;//创建ros句柄
        //修改的关键点
        //关键点1.订阅的两只乌龟的话题名称是动态传入的
    ros::Subscriber sub=nh.subscribe(turtle_name+"/pose",100,doPose);//创建订阅对象（话题名称，队列长度，回调函数）
    ros::spin();

}