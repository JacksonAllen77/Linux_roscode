#! /usr/bin/env python
"""
    生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.导包
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 service 客户端
        4.等待服务启动
        5.发送请求
        6.处理响应

"""
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
if __name__=="__main__":
    rospy.init_node("srv_spawn_p")#初始化节点
    client=rospy.ServiceProxy("/spawn",Spawn)#c创建服务的客户端对象
    #组织数据并发送请求
    request=SpawnRequest()
    request.x=3
    request.y=5
    request.theta=1.61
    request.name="duck"
    #判断服务器状态并发送
    client.wait_for_service()#等待服务器启动
    try:
        response = client.call(request)
        # 处理响应
        rospy.loginfo("新乌龟名称为 %s", response.name)
    except Exception as e:
        rospy.loginfo("服务调用失败: %s", e)