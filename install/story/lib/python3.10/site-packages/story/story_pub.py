import rclpy
from rclpy.node import Node
from greenstory_interfaces.msg import ListenStory

class StoryPub(Node):
    def __init__(self, serial_number):
        super().__init__('story_pub')
        self.story_array = [
            "Once upon a time in a land far, far away...",
            "In a small village nestled between the mountains...",
            "Long ago, in a kingdom ruled by a wise king...",
            "In the depths of an enchanted forest...",
            "On a distant planet where strange creatures roam...",
        ]
        self.received_serial_number = serial_number
        self.get_logger().info(f'Receive Request to Tell Story : {self.received_serial_number}')
        self.publisher_ = self.create_publisher(ListenStory, 'listen_story', 10)
        timer_period = 5.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = ListenStory()
        # 获取 story_array 中的内容
        story = self.story_array[self.received_serial_number % len(self.story_array)]
        msg.story = f'This is story number {self.received_serial_number}: {story}'
        
        self.get_logger().info(f'Start to Tell Story: {self.received_serial_number}')
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.story}"')
        
def main(args=None):
    rclpy.init(args=args)

    story_serial_number = 1  # Example serial number, can be modified as needed
    story_pub = StoryPub(story_serial_number)

    rclpy.spin(story_pub)

    story_pub.destroy_node()
    rclpy.shutdown()
import rclpy
from rclpy.node import Node
from greenstory_interfaces.msg import ListenStory

class StoryPub(Node):
    def __init__(self, serial_number):
        super().__init__('story_pub')
        self.story_array = [
            "Once upon a time in a land far, far away...",
            "In a small village nestled between the mountains...",
            "Long ago, in a kingdom ruled by a wise king...",
            "In the depths of an enchanted forest...",
            "On a distant planet where strange creatures roam...",
        ]
        self.received_serial_number = serial_number
        self.get_logger().info(f'Receive Request to Tell Story : {self.received_serial_number}')
        self.publisher_ = self.create_publisher(ListenStory, 'listen_story', 10)
        timer_period = 5.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = ListenStory()
        # 获取 story_array 中的内容
        story = self.story_array[self.received_serial_number % len(self.story_array)]
        msg.story = f'This is story number {self.received_serial_number}: {story}'
        
        self.get_logger().info(f'Start to Tell Story: {self.received_serial_number}')
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.story}"')
        
def main(args=None):
    rclpy.init(args=args)

    story_serial_number = 1  # Example serial number, can be modified as needed
    story_pub = StoryPub(story_serial_number)

    rclpy.spin(story_pub)

    story_pub.destroy_node()
    rclpy.shutdown()
