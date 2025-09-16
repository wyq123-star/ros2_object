#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3
import numpy as np

class IMUTransform(Node):
    def __init__(self):
        super().__init__('imu_transform_node')
        
        # 声明参数
        self.declare_parameter('input_topic', '/livox/imu')
        self.declare_parameter('output_topic', '/livox/imu_transformed')
        
        # 获取参数值
        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        
        # 打印配置信息
        self.get_logger().info("IMU坐标转换节点已启动 (交换XY并角速度取反)")
        self.get_logger().info(f"  输入话题: {self.input_topic}")
        self.get_logger().info(f"  输出话题: {self.output_topic}")
        self.get_logger().info("  变换规则: 交换线加速度XY, 角速度XY交换且所有轴取反, 线加速度Z不变")
        
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
        变换规则:
          线加速度: 交换X和Y, Z不变
          角速度: 交换X和Y, 并且所有轴取反
        """
        self.callback_count += 1
        
        # 创建新的IMU消息
        transformed_msg = Imu()
        
        # 复制头部信息（保持时间戳一致）
        transformed_msg.header = msg.header
        transformed_msg.header.frame_id = "imu_transformed_frame"  # 更新坐标系标识
        
        # 处理线性加速度: 交换X和Y，Z保持不变
        transformed_msg.linear_acceleration.x = msg.linear_acceleration.y  # 新X = 旧Y
        transformed_msg.linear_acceleration.y = msg.linear_acceleration.x  # 新Y = 旧X
        transformed_msg.linear_acceleration.z = msg.linear_acceleration.z  # Z保持不变
        
        # 处理角速度: 交换X和Y，并且所有轴取反
        transformed_msg.angular_velocity.x = -msg.angular_velocity.y  # 新X = -旧Y
        transformed_msg.angular_velocity.y = -msg.angular_velocity.x  # 新Y = -旧X
        transformed_msg.angular_velocity.z = -msg.angular_velocity.z  # 新Z = -旧Z
        
        # 注意：由于IMU不提供有效的姿态数据，将四元数设置为单位四元数
        # 并通过协方差矩阵标记为无效数据
        transformed_msg.orientation.x = 0.0
        transformed_msg.orientation.y = 0.0
        transformed_msg.orientation.z = 0.0
        transformed_msg.orientation.w = 1.0  # 单位四元数
        
        # 设置协方差矩阵（标记姿态数据无效）
        transformed_msg.orientation_covariance = [-1.0] + [0.0] * 8
        
        # 复制其他协方差矩阵（保持原始噪声特性）
        transformed_msg.angular_velocity_covariance = msg.angular_velocity_covariance
        transformed_msg.linear_acceleration_covariance = msg.linear_acceleration_covariance
        
        # 发布转换后的消息
        self.publisher_.publish(transformed_msg)
        
        # 每10次回调打印一次调试信息
        if self.callback_count % 10 == 0:
            self.get_logger().info(
                f"转换示例 - 原始加速度: "
                f"x={msg.linear_acceleration.x:.3f}, "
                f"y={msg.linear_acceleration.y:.3f}, "
                f"z={msg.linear_acceleration.z:.3f} | "
                f"转换后加速度: "
                f"x={transformed_msg.linear_acceleration.x:.3f}, "
                f"y={transformed_msg.linear_acceleration.y:.3f}, "
                f"z={transformed_msg.linear_acceleration.z:.3f}"
            )
            self.get_logger().info(
                f"转换示例 - 原始角速度: "
                f"x={msg.angular_velocity.x:.3f}, "
                f"y={msg.angular_velocity.y:.3f}, "
                f"z={msg.angular_velocity.z:.3f} | "
                f"转换后角速度: "
                f"x={transformed_msg.angular_velocity.x:.3f}, "
                f"y={transformed_msg.angular_velocity.y:.3f}, "
                f"z={transformed_msg.angular_velocity.z:.3f}"
            )

def main(args=None):
    rclpy.init(args=args)
    node = IMUTransform()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("键盘中断，关闭节点")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()