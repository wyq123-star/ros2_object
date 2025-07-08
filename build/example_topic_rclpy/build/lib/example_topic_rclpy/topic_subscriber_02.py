import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16
from std_msgs.msg import String

class NodeScribe(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().fatal("%s" % name)
        self.subscribe = self.create_subscription(String,"shuju",self.sub_callback,10)
        # self.timer = self.create_timer(0.5,self.timer_callback)

    def add(self,x,y):
        return x + y 
    
    def sub_callback(self, msg):
        # 实际处理订阅收到的消息
        self.get_logger().info("Received: {%s}" % msg.data)
        x = int(msg.data[0])
        y = int(msg.data[1])
        self.get_logger().info("x : %d" % x)
        self.get_logger().info("y : %d" % y)       
        z = self.add(x,y)
        self.get_logger().info("z : %d" % z)          

    # def timer_callback(self):
                       
    #     msg = String()
    #     self.get_logger().info("{%s}" % msg.data)

    
def main(args=None):
    rclpy.init(args=args)
    node2 = NodeScribe("qwer")
    z = node2.add(1,2)
    node2.get_logger().info("%d" % z)
    rclpy.spin(node2)
    rclpy.shutdown()
