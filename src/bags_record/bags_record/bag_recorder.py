import rclpy
from rclpy.node import Node
from rclpy.serialization import serialize_message
# from std_msgs.msg import String
# from rclpy.qos import QoSProfile
import rosbag2_py
from sensor_msgs.msg import Imu

class SimpleBagRecorder(Node):
    def __init__(self):
        super().__init__('simple_bag_recorder')
        self.writer = rosbag2_py.SequentialWriter()

        storage_options = rosbag2_py.StorageOptions(
            uri='my_bag',
            storage_id='sqlite3')
        converter_options = rosbag2_py.ConverterOptions('', '')
        self.writer.open(storage_options, converter_options)

        topic_info = rosbag2_py.TopicMetadata(
            name='imu/data_raw',
            type='sensor_msgs/msg/Imu',
            serialization_format='cdr')
        self.writer.create_topic(topic_info)

        self.subscription = self.create_subscription(
            Imu,
            'imu/data_raw',
            self.topic_callback,
            10)
        
        self.subscription

    def topic_callback(self, msg):
        self.writer.write(
            'imu/data_raw',
            serialize_message(msg),
            self.get_clock().now().nanoseconds)


def main(args=None):
    rclpy.init(args=args)
    sbr = SimpleBagRecorder()
    rclpy.spin(sbr)
    rclpy.shutdown()


if __name__ == '__main__':
    main()