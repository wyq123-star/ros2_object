import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16 
from std_msgs.msg import String
import random

class NodePublisher02(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().warn("大家好，我是%s!" % name)
        self.publish_ = self.create_publisher(String,"shuju",10)
        self.timer = self.create_timer(0.5,self.timer_callback)

    def timer_callback(self):
        a = random.randint(1,9)
        b = random.randint(1,9)

        msg = String()
        msg.data = f"{a}{b}"
        self.publish_.publish(msg)
        self.get_logger().warn(f'发布了指令：{msg.data}')

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy
    node = NodePublisher02("pub")  # 新建一个节点
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy
