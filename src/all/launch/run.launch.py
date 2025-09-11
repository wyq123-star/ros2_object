from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python import get_package_share_directory
import os

def generate_launch_description():



    ros1_bridge_node = Node(
        package='ros1_bridge',        # 包名
        executable='dynamic_bridge',   # 可执行文件名
        name='ros1_bridge_node',      # 节点名
        arguments=['--bridge-all-topics'],  # 在此处添加命令行参数
        # 如果你的 bridge 需要其他参数，也可以一并加入，例如：
        # arguments=['--bridge-all-topics', '--some-other-arg', 'value'],
    )

    airy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('rslidar_sdk'),
                'launch',
                'humble_start.py',
            )
        )
    )

    imu_transformed_node = Node(
        package='ros2_driver',
        executable='imu_transformed',
        name='imu_transformed_node',
    )

    return LaunchDescription(
        [
            imu_transformed_node,
            ros1_bridge_node,
            airy_launch,
        ]
    )