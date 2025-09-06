import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Py_subscriber(Node):
    def __init__(self):
        super().__init__('py_subscriber')
        self.subscriber_ = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)
        self.get_logger().info("Subscriber has been started.")

    def listener_callback(self, msg):
        # if msg.data == "Hello, world! ":
            self.get_logger().info("up70")

        # self.get_logger().info('I heard: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)

    py_subscriber = Py_subscriber()

    rclpy.spin(py_subscriber)

    py_subscriber.destroy_node()
    rclpy.shutdown()