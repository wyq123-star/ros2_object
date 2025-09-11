#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

class IMUTransform(Node):
    def __init__(self):
        super().__init__('imu_transform_node')
        
        # 声明参数
        self.declare_parameter('input_topic', '/livox/imu')
        self.declare_parameter('output_topic', '/livox/imu_transformed')
        self.declare_parameter('invert_z', True)
        self.declare_parameter('invert_x', False)
        self.declare_parameter('invert_y', False)
        self.declare_parameter('swap_xy', True)  # XY轴对调参数
        
        # 获取参数值
        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.invert_z = self.get_parameter('invert_z').value
        self.invert_x = self.get_parameter('invert_x').value
        self.invert_y = self.get_parameter('invert_y').value
        self.swap_xy = self.get_parameter('swap_xy').value
        
        # 打印配置信息
        self.get_logger().info("IMU坐标转换节点配置:")
        self.get_logger().info(f"  输入话题: {self.input_topic}")
        self.get_logger().info(f"  输出话题: {self.output_topic}")
        self.get_logger().info(f"  反转X轴: {self.invert_x}")
        self.get_logger().info(f"  反转Y轴: {self.invert_y}")
        self.get_logger().info(f"  反转Z轴: {self.invert_z}")
        self.get_logger().info(f"  XY轴对调: {self.swap_xy}")
        
        # 创建发布者和订阅者
        self.publisher_ = self.create_publisher(Imu, self.output_topic, 10)
        self.subscription = self.create_subscription(
            Imu,
            self.input_topic,
            self.imu_callback,
            10
        )
        
        # 添加调试计数器
        self.callback_count = 0
        
    def imu_callback(self, msg):
        """
        IMU数据回调函数，处理坐标转换
        """
        self.callback_count += 1
        
        # 创建新的IMU消息
        transformed_msg = Imu()
        
        # 复制头部信息
        transformed_msg.header = msg.header
        transformed_msg.header.frame_id = "imu_transformed"  # 明确标记转换后的坐标系
        
        # 处理线性加速度
        transformed_msg.linear_acceleration = self.transform_vector(
            msg.linear_acceleration
        )
        
        # 处理角速度
        transformed_msg.angular_velocity = self.transform_vector(
            msg.angular_velocity
        )
        
        # 保持方向信息不变（不处理四元数）
        transformed_msg.orientation = msg.orientation
        
        # 复制协方差矩阵
        transformed_msg.orientation_covariance = msg.orientation_covariance
        transformed_msg.angular_velocity_covariance = msg.angular_velocity_covariance
        transformed_msg.linear_acceleration_covariance = msg.linear_acceleration_covariance
        
        # 发布转换后的消息
        self.publisher_.publish(transformed_msg)
        
        # 每10次回调打印一次调试信息
        if self.callback_count % 10 == 0:
            self.get_logger().info(
                f"转换示例 - 原始: x={msg.linear_acceleration.x:.3f}, y={msg.linear_acceleration.y:.3f}, z={msg.linear_acceleration.z:.3f} | "
                f"转换后: x={transformed_msg.linear_acceleration.x:.3f}, y={transformed_msg.linear_acceleration.y:.3f}, z={transformed_msg.linear_acceleration.z:.3f}"
            )
        
    def transform_vector(self, vector):
        """
        转换向量坐标，包括XYZ反转和XY对调
        """
        transformed = Vector3()
        
        # 首先应用反转
        x_val = -vector.x if self.invert_x else vector.x
        y_val = -vector.y if self.invert_y else vector.y
        z_val = -vector.z if self.invert_z else vector.z
        
        # 然后应用XY对调（如果需要）
        if self.swap_xy:
            transformed.x = y_val  # X取原Y值
            transformed.y = x_val  # Y取原X值
            transformed.z = z_val
        else:
            transformed.x = x_val
            transformed.y = y_val
            transformed.z = z_val
        
        return transformed

def main(args=None):
    rclpy.init(args=args)
    node = IMUTransform()
    node.get_logger().info("IMU坐标转换节点已启动，支持XY轴对调")
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("键盘中断，关闭节点")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()