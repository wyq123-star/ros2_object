#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

class IMUZTransform(Node):
    def __init__(self):
        super().__init__('imu_z_transform_node')
        
        # 声明参数
        self.declare_parameter('input_topic', '/livox/imu')
        self.declare_parameter('output_topic', '/livox/imu_transformed')
        self.declare_parameter('invert_z', True)
        self.declare_parameter('invert_x', False)
        self.declare_parameter('invert_y', False)
        
        # 获取参数值
        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.invert_z = self.get_parameter('invert_z').value
        self.invert_x = self.get_parameter('invert_x').value
        self.invert_y = self.get_parameter('invert_y').value
        
        # 打印配置信息
        self.get_logger().info("IMU Z轴转换节点配置:")
        self.get_logger().info(f"  输入话题: {self.input_topic}")
        self.get_logger().info(f"  输出话题: {self.output_topic}")
        self.get_logger().info(f"  反转X轴: {self.invert_x}")
        self.get_logger().info(f"  反转Y轴: {self.invert_y}")
        self.get_logger().info(f"  反转Z轴: {self.invert_z}")
        
        # 创建发布者和订阅者
        self.pub = self.create_publisher(Imu, self.output_topic, 10)
        self.sub = self.create_subscription(
            Imu,
            self.input_topic,
            self.imu_callback,
            10
        )
        
    def imu_callback(self, msg):
        """
        IMU数据回调函数，处理坐标转换
        """
        # 创建新的IMU消息
        transformed_msg = Imu()
        
        # 复制头部信息
        transformed_msg.header = msg.header
        
        # 处理线性加速度
        transformed_msg.linear_acceleration = self.transform_vector(
            msg.linear_acceleration, 
            self.invert_x, 
            self.invert_y, 
            self.invert_z
        )
        
        # 处理角速度
        transformed_msg.angular_velocity = self.transform_vector(
            msg.angular_velocity, 
            self.invert_x, 
            self.invert_y, 
            self.invert_z
        )
        
        # 复制方向信息（注意：四元数转换更复杂，这里保持原样）
        transformed_msg.orientation = msg.orientation
        
        # 复制协方差矩阵
        transformed_msg.orientation_covariance = msg.orientation_covariance
        transformed_msg.angular_velocity_covariance = msg.angular_velocity_covariance
        transformed_msg.linear_acceleration_covariance = msg.linear_acceleration_covariance
        
        # 发布转换后的消息
        self.pub.publish(transformed_msg)
        
    def transform_vector(self, vector, invert_x, invert_y, invert_z):
        """
        转换向量坐标
        """
        transformed = Vector3()
        transformed.x = -vector.x if invert_x else vector.x
        transformed.y = -vector.y if invert_y else vector.y
        transformed.z = -vector.z if invert_z else vector.z
        return transformed

def main(args=None):
    rclpy.init(args=args)
    node = IMUZTransform()
    node.get_logger().info("IMU Z轴转换节点已启动")
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()