import rclpy
from launch import LaunchDescription
from launch.actions import ExecuteProcess  # 导入 ExecuteProcess
import os
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    # 方案一：使用 ExecuteProcess 和 xterm 启动节点（提供独立终端）
    # 获取当前功能包的共享目录路径（更规范的方式）
    pkg_share_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')
    pkg_share_dir = os.path.abspath(pkg_share_dir)  # 获取绝对路径

    # 构造启动节点的命令
    # 使用 xterm 创建一个新终端来运行节点，-e 参数表示在终端中执行后续命令
    # 注意：需要系统已安装 xterm (`sudo apt-get install xterm`)
    publisher_cmd = ExecuteProcess(
        cmd=[
            'xterm',  # 终端模拟器
            '-e',     # 在终端中执行后续命令
            'ros2', 'run', 'base_cpp', 'publisher'  # 原本在命令行中执行的命令
        ],
        output='screen'  # 将过程输出到屏幕
    )
    subscribe_node = Node(
        package='base',
        executable='subscriber',
        name='py_subscriber',
        output='screen'
    )

    # 方案二（备选）：直接使用 Node 动作，并尝试启用 emulate_tty（效果可能有限）
    # publisher_node = Node(
    #     package='base_cpp',
    #     executable='publisher',
    #     name='cpp_publisher',
    #     output='screen',
    #     emulate_tty=True,  # 尝试模拟一个 TTY，但对复杂键盘输入可能仍无效
    # )

    ld.add_action(publisher_cmd)  # 使用方案一
    ld.add_action(subscribe_node)
    # ld.add_action(publisher_node) # 使用方案二

    return ld