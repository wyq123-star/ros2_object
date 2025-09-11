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
        
        # 定义旋转矩阵: 先绕Z轴顺时针90度，再绕X轴旋转180度
        # 绕Z轴旋转-90度 (顺时针)
        theta_z = -np.pi / 2  # -90度
        R_z = np.array([
            [np.cos(theta_z), -np.sin(theta_z), 0],
            [np.sin(theta_z), np.cos(theta_z), 0],
            [0, 0, 1]
        ])
        
        # 绕X轴旋转180度
        theta_x = np.pi  # 180度
        R_x = np.array([
            [1, 0, 0],
            [0, np.cos(theta_x), -np.sin(theta_x)],
            [0, np.sin(theta_x), np.cos(theta_x)]
        ])
        
        # 组合旋转矩阵: R_total = R_x * R_z
        self.R_total = np.dot(R_x, R_z)
        
        # 打印配置信息
        self.get_logger().info("IMU坐标转换节点已启动 (仅处理加速度和角速度)")
        self.get_logger().info(f"  输入话题: {self.input_topic}")
        self.get_logger().info(f"  输出话题: {self.output_topic}")
        self.get_logger().info(f"  旋转矩阵: \n{self.R_total}")
        
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
        IMU数据回调函数，处理坐标转换 (仅处理加速度和角速度)
        """
        self.callback_count += 1
        
        # 创建新的IMU消息
        transformed_msg = Imu()
        
        # 复制头部信息
        transformed_msg.header = msg.header
        transformed_msg.header.frame_id = "imu_lidar_frame"  # 明确标记转换后的坐标系
        
        # 处理线性加速度 (应用旋转矩阵)
        transformed_msg.linear_acceleration = self.transform_vector(
            msg.linear_acceleration
        )
        
        # 处理角速度 (应用旋转矩阵)
        transformed_msg.angular_velocity = self.transform_vector(
            msg.angular_velocity
        )
        
        # 注意：移除了四元数处理部分
        # 由于IMU不提供姿态数据，将四元数设置为无效值（通常协方差矩阵第一个元素设为-1）
        transformed_msg.orientation.x = 0.0
        transformed_msg.orientation.y = 0.0
        transformed_msg.orientation.z = 0.0
        transformed_msg.orientation.w = 1.0  # 单位四元数（无效或默认值）
        
        # 复制协方差矩阵
        transformed_msg.orientation_covariance = [-1.0] + [0.0] * 8  # 标记姿态数据无效[1](@ref)
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
                f"转换后: "
                f"x={transformed_msg.linear_acceleration.x:.3f}, "
                f"y={transformed_msg.linear_acceleration.y:.3f}, "
                f"z={transformed_msg.linear_acceleration.z:.3f}"
            )
        
    def transform_vector(self, vector):
        """
        应用旋转矩阵转换向量 (加速度和角速度)
        """
        # 创建原始向量数组
        original_vec = np.array([vector.x, vector.y, vector.z])
        
        # 应用旋转矩阵
        transformed_vec = np.dot(self.R_total, original_vec)
        
        # 创建新的Vector3消息
        transformed = Vector3()
        transformed.x = transformed_vec[0]
        transformed.y = transformed_vec[1]
        transformed.z = transformed_vec[2]
        
        return transformed

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