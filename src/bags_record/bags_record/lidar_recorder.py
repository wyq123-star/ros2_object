import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2
import rosbag2_py
from rclpy.serialization import serialize_message

class LidarRecorder(Node):
    def __init__(self):

        
        super().__init__('lidar_recorder')
        self.declare_parameter('bag_file_path', 'bag')
        bag_file_path = self.get_parameter('bag_file_path').get_parameter_value().string_value
        self.get_logger().info(f"Bag file will be saved to: {bag_file_path}")
        self.writer = rosbag2_py.SequentialWriter()
        storage_options = rosbag2_py.StorageOptions(
            uri=bag_file_path,
            storage_id='sqlite3')
        
        converter_options = rosbag2_py.ConverterOptions('', '')
        self.writer.open(storage_options, converter_options)
        topic_info = rosbag2_py.TopicMetadata(
            name='livox/lidar',
            type='sensor_msgs/msg/PointCloud2',
            serialization_format='cdr')
        self.writer.create_topic(topic_info)

        self.subscription = self.create_subscription(
            PointCloud2,
            'livox/lidar',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.writer.write(
            'livox/lidar',
            serialize_message(msg),
            self.get_clock().now().nanoseconds)
        
def main(args=None):
        rclpy.init(args=args)
        lidar_recorder = LidarRecorder()
        rclpy.spin(lidar_recorder)
        rclpy.destroy_node(lidar_recorder)
        rclpy.shutdown()

if __name__ == '__main__':
    main()  