#! /usr/bin/env python
import rospy

if __name__ == "__main__":
    rospy.init_node("hello_log")
    rospy.logdebug("调试信息，不输出")
    rospy.loginfo("一般信息，输出为白色")
    rospy.logwarn("警告信息，输出为黄色")
    rospy.logerr("错误信息，输出为红色，程序不会中断")
    rospy.logfatal("严重错误信息，输出为红色，程序会中断")