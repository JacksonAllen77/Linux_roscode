#include "ros/ros.h"

void cb(const ros::TimerEvent&event)//定时器采用的回调函数
{
    ROS_INFO("这是一段文本");//此处需求为，每隔一秒钟打印一个文本
}
int main(int argc,char *argv[])
{
    /*1.获取当前时间&设置指定时刻【头文件、初始化节点、创建节点句柄、获取当前时间、设置指定时间】
    2.使程序休眠一段时间【头文件、初始化节点、创建节点句柄、创建持续时间对象、休眠操作】
    3.已知程序开始时刻&持续时间，求程序结束时刻【头文件、初始化节点、创建节点句柄、获取开始执行时刻、模拟持续时间、计算结束时刻】
    4.每隔1秒钟，在终端输出一段文本【头文件、初始化节点、创建节点句柄、】
*/

    setlocale(LC_ALL,"");//避免中文乱码

    ros::init(argc,argv,"hello_time");//初始化对象
    ros::NodeHandle nh;//创建节点句柄【必须包含此步骤，否则会导致时间API调用失败】
    //获取当前时间
    ros::Time right_now=ros::Time::now();//now函数会将当前时刻封装并返回
        //时间参考系——1970年1月1日 08:00:00
    ROS_INFO("当前时刻：%.2f",right_now.toSec());//将逝去的时间转换成以秒为计算数据，返回值类型为double
    ROS_INFO("当前时刻：%d",right_now.sec);////将逝去的时间转换成以秒为计算数据，返回值为int
    //设置指定时刻
    ros::Time t1(20,3123121214);//左侧为秒，右侧为纳秒，两个做累加，以时间参考系为参考，过去了20.31秒的时间
    ros::Time t2(100.35);//以时间参考系为参考，过去了100.35秒
    ROS_INFO("当前时刻：%.2f",t1.toSec());
    ROS_INFO("当前时刻：%.2f",t2.toSec());
    //------------------------------------------------------
    ROS_INFO("持续时间演示如下---------");
    ROS_INFO("开始休眠的时刻:%.2f",ros::Time::now().toSec());
    ros::Duration d1(4.5);//持续4.5秒钟,参数是double类型的，以秒为单位
    d1.sleep();//按照指定的持续时间休眠
    ROS_INFO("持续时间:%.2f",d1.toSec());//将持续时间换算成秒
    ROS_INFO("结束休眠的时刻:%.2f",ros::Time::now().toSec());
     //------------------------------------------------------
    ROS_INFO("时刻&持续时间运算【可加可减】---------");
    ros::Time begin=ros::Time::now();
    ROS_INFO("开始时刻:%.2f",begin.toSec());
    ros::Duration d2(5.5);//持续10秒钟,参数是double类型的，以秒为单位
    ros::Time end=begin+d2;//进行时间运算
    ROS_INFO("计算出的结束时刻:%.2f",end.toSec());
    ROS_INFO("时刻&时刻运算【只可减不可加】---------");
    ros::Duration d3=end-begin;
    ROS_INFO("两个时刻的差值为:%.2f",d3.toSec());
    ROS_INFO("持续时间&持续时间运算【可加可减】---------");
    ros::Duration d4=d1+d2;
    ROS_INFO("两个持续时间之和为:%.2f",d4.toSec());
     //------------------------------------------------------
    ROS_INFO("定时器演示如下---------");
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();//手动启动定时器，当auto为false需要
    ros::spin();//需要回调函数
    /*参数——
        param period 时间间隔
        param callback 回调函数【const ros::TimerEvent&event时间事件】
        param oneshot 如果设置为 true,只执行一次回调函数，设置为 false,就循环执行。
        param autostart 如果为true，返回已经启动的定时器,设置为 false，需要手动启动
        定时器启动后，需要ros::spin()
    */
    return 0;
}