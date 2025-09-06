import rclpy
from rclpy.node import Node
from rclpy.serialization import serialize_message
import rosbag2_py
from sensor_msgs.msg import Imu
from sensor_msgs.msg import PointCloud2

class MultiBagRecorder(Node):
    def __init__(self):
        super().__init__('multi_bag_recorder')
        
        # 1. 声明节点参数，提供默认值
        self.declare_parameter('bag_file_path', 'bag')  # 默认值为'my_bag'
        
        # 2. 获取参数值
        bag_file_path = self.get_parameter('bag_file_path').get_parameter_value().string_value
        
        self.get_logger().info(f"Bag file will be saved to: {bag_file_path}")  # 打印路径以便调试
        
        # 3. 使用参数值初始化bag写入器
        self.writer = rosbag2_py.SequentialWriter()
        storage_options = rosbag2_py.StorageOptions(
            uri= bag_file_path,  # 使用参数值，而非硬编码的'my_bag'
            storage_id='sqlite3')
        converter_options = rosbag2_py.ConverterOptions('', '')
        self.writer.open(storage_options, converter_options)

        imu_topic_info = rosbag2_py.TopicMetadata(
            name='imu/data_raw',
            type='sensor_msgs/msg/Imu',
            serialization_format='cdr')
        self.writer.create_topic(imu_topic_info)

        lidar_topic_info = rosbag2_py.TopicMetadata(
            name='livox/lidar',
            type='sensor_msgs/msg/PointCloud2',
            serialization_format='cdr')
        self.writer.create_topic(lidar_topic_info)

        self.imu_subscription = self.create_subscription(
            Imu,
            'imu/data_raw',
            self.imu_callback,
            10)
        
        self.lidar_subscription = self.create_subscription(
            PointCloud2,
            'livox/lidar',
            self.lidar_callback,
            10)
        
        self.imu_subscription  # prevent unused variable warning
        self.lidar_subscription  # prevent unused variable warning

    def imu_callback(self, msg):
        self.writer.write(
            'imu/data_raw',
            serialize_message(msg),
            self.get_clock().now().nanoseconds)

    def lidar_callback(self, msg):
        self.writer.write(
            'livox/lidar',
            serialize_message(msg),
            self.get_clock().now().nanoseconds)
        
def main(args=None):
    rclpy.init(args=args)
    mbr = MultiBagRecorder()
    rclpy.spin(mbr)
    rclpy.destroy_node(mbr)
    rclpy.shutdown()

if __name__ == '__main__':
    main()