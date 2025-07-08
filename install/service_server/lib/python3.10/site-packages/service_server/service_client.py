import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class ServiceClient(Node):
    def __init__(self, name):
        super().__init__(name)
        self.get_logger().fatal(f"我是：{name}")
        self.add_two_ints_server = self.create_client(AddTwoInts, "add")

    def result_callback(self, result_future):
        response = result_future.result()
        self.get_logger().info(f"收到返回结果：{response.sum}")

    def send_request(self, a, b):
        while rclpy.ok() and self.add_two_ints_server.wait_for_service(1) == False:
            self.get_logger().warn(f"等待服务端。。。")

        request = AddTwoInts.Request()
        request.a = a
        request.b = b
        self.add_two_ints_server.call_async(request).add_done_callback(self.result_callback)

def main(args=None):
    rclpy.init(args=args)
    node = ServiceClient("service_client_02")
    node.send_request(3, 4)
    rclpy.spin(node)
    rclpy.shutdown()
