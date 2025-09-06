from launch import LaunchDescription
from launch.actions import ExecuteProcess, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
import os
from launch_ros.actions import Node

def generate_launch_description():
    # 声明启动参数
    message_arg = DeclareLaunchArgument(
        'message_data',
        default_value='hello_world',
        description='要发布的消息内容'
    )
    
    ld = LaunchDescription()
    ld.add_action(message_arg)

    # 获取启动参数的值
    message_data_config = LaunchConfiguration('message_data')


    publisher_cmd = ExecuteProcess(

        cmd=[
            'xterm', 
            '-e',
            'ros2', 'run', 'base_cpp', 'publisher', '--ros-args',
            '-p', ['message_data:=', message_data_config] 
        ],
        output='screen'
    )
    
    subscribe_node = Node(
        package='base',
        executable='subscriber',
        name='py_subscriber',
        output='screen'
    )

    ld.add_action(publisher_cmd)
    ld.add_action(subscribe_node)

    return ld