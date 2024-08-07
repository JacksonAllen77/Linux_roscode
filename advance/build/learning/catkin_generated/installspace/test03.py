#!/usr/bin/env python3
import rospy
"""
    1.获取当前时间&设置指定时刻【头文件、初始化节点、获取当前时间、设置指定时间】
    2.使程序休眠一段时间【头文件、初始化节点、创建持续时间对象、休眠操作】
    3.已知程序开始时刻&持续时间，求程序结束时刻【头文件、初始化节点、获取开始执行时刻、模拟持续时间、计算结束时刻】
    4.每隔1秒钟，在终端输出一段文本【头文件、初始化节点、调用定时器函数、编写回调函数、ros：：spin回调】
"""
def cb(event):
    rospy.loginfo("这是一段文本----")

if __name__ == "__main__":
    rospy.init_node("hello_time")#初始化节点
    #获取当前时刻
    right_now=rospy.Time.now()#获取当前时刻
    rospy.loginfo(f"当前时刻相对于时间参考系过去了{right_now.to_sec()}秒")#输出结果为float
    rospy.loginfo(f"当前时刻相对于时间参考系过去了{right_now.secs}秒")#输出结果为int
    #设置指定时刻
    time1=rospy.Time(100.5)#将时间封装成time对象，距离时间参考系过去了100.5秒
    time2=rospy.Time(100,31211221)#将时间封装成time对象，距离时间参考系过去了100秒311212纳秒
    rospy.loginfo(f"当前时刻相对于时间参考系过去了{time1.to_sec()}秒")
    rospy.loginfo(f"当前时刻相对于时间参考系过去了{time2.to_sec()}秒")
    #从某个时间值获取时间对象
    time3=rospy.Time.from_sec(210.12)
    rospy.loginfo(f"当前时刻相对于时间参考系过去了{time3.to_sec()}秒")
    #----------------------------------------------------------
    rospy.loginfo("持续时间演示如下--------------")
    rospy.loginfo("休眠开始")
    d1=rospy.Duration(3.2)#创建持续时间对象
    rospy.sleep(d1)#休眠操作
    rospy.loginfo(f"持续时间{d1.to_sec()}秒")
    rospy.loginfo("休眠结束")
     #----------------------------------------------------------
    rospy.loginfo("时间&持续时间运算【可加可减】--------------")
    t1=rospy.Time.now()#获取一个时间
    d2=rospy.Duration(3.5)#设置一个持续时间
    t2=t1+d1
    rospy.loginfo(f"开始时刻{t1.to_sec()}")
    rospy.loginfo(f"结束时刻{t2.to_sec()}")
    rospy.loginfo("时刻&时刻运算【只可减不可加】--------------")
    t3=t1-right_now
    rospy.loginfo(f"时刻相减{t3.to_sec()}")
    rospy.loginfo("持续时间&持续时间运算【可减可加】--------------")
    d3=d1+d2
    rospy.loginfo(f"持续时间相加{d3.to_sec()}")
     #----------------------------------------------------------
    rospy.loginfo("定时器演示如下--------------")
    timer=rospy.Timer(rospy.Duration(1),cb,oneshot=True)#创建一个定时器对象
    rospy.spin()#有回调函数时采用
    """    
    def __init__(self, period, callback, oneshot=False, reset=False):
    Constructor.
    @param period: 回调函数的时间间隔
    @type  period: rospy.Duration
    @param callback: 回调函数
    @type  callback: function taking rospy.TimerEvent
    @param oneshot: 设置为True，就只执行一次，否则循环执行
    @type  oneshot: bool
    @param reset: if True, timer is reset when rostime moved backward. [default: False]
    @type  reset: bool
"""


