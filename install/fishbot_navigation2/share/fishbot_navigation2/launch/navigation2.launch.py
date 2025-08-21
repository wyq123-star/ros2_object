import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    
    fishbot_navigation2_dir = get_package_share_directory('fishbot_navigation2')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')

    use_sin_time = LaunchConfiguration('use_sim_time', default='true')
    map_yaml_path = os.path.join(fishbot_navigation2_dir, 'maps', 'fishbot_map.yaml')
    nav2_params_file = os.path.join(fishbot_navigation2_dir, 'param', 'fishbot_nav2.yaml')
    rviz_config_dir = os.path.join(fishbot_navigation2_dir, 'rviz', 'nav2_default_view.rviz')

    nav2_bringup_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([fishbot_navigation2_dir,'/launch', '/bringup.launch.py']),
    
    launch_arguments={
            'use_sim_time': use_sin_time,
            'map': map_yaml_path,
            'params_file': nav2_params_file,
            'rviz_config': rviz_config_dir
        }.items(),
)
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_dir],
        parameters=[{'use_sim_time': use_sin_time}],
    )



    return LaunchDescription([
        nav2_bringup_launch,
        # rviz_node,
        # mao_to_odom_node
    ])