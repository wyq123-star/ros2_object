from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    bag_save_path = DeclareLaunchArgument(
        'bag_save_path',
        default_value='my_bag1',
        description='Path to save the recorded bag files'
    )

    bag_path_value = LaunchConfiguration('bag_save_path')

    imu_recorder_node = Node(
        package='bags_record',
        executable='imu_recorder',
        name='imu_recorder',
        output='screen',
        parameters=[{'bag_file_path': bag_path_value}] 
    )
    lidar_recorder_node = Node(
        package='bags_record',
        executable='lidar_recorder',
        name='lidar_recorder',
        output='screen',
        parameters=[{'bag_file_path': bag_path_value}]
    )

    return LaunchDescription([
        bag_save_path,
        imu_recorder_node,
        lidar_recorder_node
    ])