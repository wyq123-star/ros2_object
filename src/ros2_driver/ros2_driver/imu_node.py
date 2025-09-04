#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, MagneticField, Temperature
from std_msgs.msg import Float32, Header
import serial
import struct
import threading
import queue
import time
from serial import EIGHTBITS, PARITY_NONE, STOPBITS_ONE

# 使用你提供的协议宏定义
PI = 3.1415926
FRAME_HEAD = str('fc')
TYPE_IMU = str('40')
IMU_LEN = str('38')  # 56 bytes
g = 9.79849 # m/s^2 南京

class IMUROS2Bridge(Node):
    def __init__(self):
        super().__init__('imu_ros2_bridge')
        
        # 声明节点参数，提供灵活性
        self.declare_parameter('port', '/dev/ttyUSB0')
        self.declare_parameter('baudrate', 921600)
        self.declare_parameter('frame_id', 'imu_link')
        
        port = self.get_parameter('port').value
        baudrate = self.get_parameter('baudrate').value
        self.frame_id = self.get_parameter('frame_id').value

        # 创建线程安全队列用于线程间通信[6,8](@ref)
        self.data_queue = queue.Queue(maxsize=100)  # 设置适当容量防止内存溢出

        # 创建多个发布者来发布不同类型的数据
        self.imu_raw_pub = self.create_publisher(Imu, 'imu/data_raw', 10)
        self.imu_transformed_pub = self.create_publisher(Imu, 'imu/data_transformed', 10)
        # self.mag_pub = self.create_publisher(MagneticField, 'imu/mag', 10)
        # self.temp_pub = self.create_publisher(Temperature, 'imu/temp', 10)
        # self.pressure_pub = self.create_publisher(Float32, 'imu/pressure', 10)

        # 初始化串口连接
        try:
            self.ser = serial.Serial(
                port=port,
                baudrate=baudrate,
                bytesize=EIGHTBITS,
                parity=PARITY_NONE,
                stopbits=STOPBITS_ONE,
                timeout=5  # 减少超时时间以提高响应速度[1](@ref)
            )
            if self.ser.is_open:
                self.get_logger().info(f"成功打开串口: {port}, 波特率: {baudrate}")
            else:
                self.get_logger().error(f"无法打开串口: {port}")
                raise RuntimeError(f"无法打开串口: {port}")
        except Exception as e:
            self.get_logger().error(f"打开串口时发生错误: {e}")
            raise

        # 创建并启动串口读取线程[1,6,8](@ref)
        self.serial_thread = threading.Thread(target=self.serial_read_loop)
        self.serial_thread.daemon = True  # 设置为守护线程，主线程退出时自动退出
        self.serial_thread.start()
        self.get_logger().info("串口读取线程已启动")

        # 创建定时器，周期性地从队列中取出数据并发布[1](@ref)
        self.timer = self.create_timer(0.001, self.publish_callback)  # 1000Hz

    def serial_read_loop(self):
        """在独立线程中持续读取和解析串口数据[6,8](@ref)"""
        while rclpy.ok() and self.ser.is_open:
            try:
                # 以下是你的协议解析逻辑
                check_head = self.ser.read().hex()
                if check_head != FRAME_HEAD:
                    continue
                
                head_type = self.ser.read().hex()
                if head_type != TYPE_IMU:
                    continue
                
                check_len = self.ser.read().hex()
                if check_len != IMU_LEN:
                    continue
                
                # 跳过SN和CRC字段（你原有的代码中没有校验）
                check_sn = self.ser.read().hex()
                head_crc8 = self.ser.read().hex()
                crc16_H_s = self.ser.read().hex()
                crc16_L_s = self.ser.read().hex()
                
                # 读取IMU数据主体
                data_s = self.ser.read(int(IMU_LEN, 16))
                if len(data_s) != 56:
                    self.get_logger().warn(f"收到数据长度异常: {len(data_s)}")
                    continue
                
                # 使用你原有的解析方法
                IMU_DATA = struct.unpack('12f ii', data_s[0:56])
                
                # 将解析好的数据放入队列，供发布线程使用[6](@ref)
                try:
                    self.data_queue.put(IMU_DATA, block=False, timeout=0.01)
                except queue.Full:
                    self.get_logger().warn("数据队列已满，丢弃最新数据", throttle_duration_sec=1.0)
                
            except Exception as e:
                self.get_logger().error(f"在读取或解析数据时发生错误: {e}", throttle_duration_sec=5.0)
                time.sleep(0.01)  # 发生错误时短暂休眠，避免疯狂循环

    def publish_callback(self):
        """定时器回调函数：从队列中取出数据并发布到ROS话题[1](@ref)"""
        try:
            # 检查队列中是否有数据
            if not self.data_queue.empty():
                # 获取所有可用数据，避免多次发布
                while not self.data_queue.empty():
                    try:
                        imu_data = self.data_queue.get_nowait()
                        self.publish_imu_data(imu_data)
                        self.data_queue.task_done()
                    except queue.Empty:
                        break
        except Exception as e:
            self.get_logger().error(f"发布数据时发生错误: {e}")

    def publish_imu_data(self, imu_data):
        """将解析后的数据发布到ROS话题"""
        current_time = self.get_clock().now().to_msg()
        
        # 1. 发布IMU数据 (陀螺仪和加速度计)
        imu_msg = Imu()
        imu_msg.header = Header()
        imu_msg.header.stamp = current_time
        imu_msg.header.frame_id = self.frame_id
        
        # 陀螺仪数据 (rad/s)
        imu_msg.angular_velocity.x = float(imu_data[0])
        imu_msg.angular_velocity.y = float(imu_data[1])
        imu_msg.angular_velocity.z = float(imu_data[2])
        
        # 加速度计数据 (m/s^2)
        imu_msg.linear_acceleration.x = float(imu_data[3])
        imu_msg.linear_acceleration.y = float(imu_data[4])
        imu_msg.linear_acceleration.z = float(imu_data[5])
        # 注意：协方差矩阵通常需要根据传感器性能填写
        imu_msg.angular_velocity_covariance[0] = -1  # 表示数据未定义
        imu_msg.linear_acceleration_covariance[0] = -1 # 表示数据未定义
        
        self.imu_raw_pub.publish(imu_msg)

        imu_msg_transformed = Imu()
        imu_msg_transformed.header = Header()
        imu_msg_transformed.header.stamp = current_time
        imu_msg_transformed.header.frame_id = self.frame_id

        imu_msg_transformed.angular_velocity.x = float(imu_data[0])
        imu_msg_transformed.angular_velocity.y = float(imu_data[1])
        imu_msg_transformed.angular_velocity.z = float(imu_data[2])

        imu_msg_transformed.linear_acceleration.x = float(imu_data[3]) / g
        imu_msg_transformed.linear_acceleration.y = float(imu_data[4]) / g
        imu_msg_transformed.linear_acceleration.z = float(imu_data[5]) / g

        self.imu_transformed_pub.publish(imu_msg_transformed)
        
        # 2. 发布磁力计数据 (需要从mG转换为特斯拉Tesla)
        # mag_msg = MagneticField()
        # mag_msg.header = Header()
        # mag_msg.header.stamp = current_time
        # mag_msg.header.frame_id = self.frame_id
        
        # 1 mG = 1e-7 Tesla
        # conversion_factor = 1e-7
        # mag_msg.magnetic_field.x = float(imu_data[6]) * conversion_factor
        # mag_msg.magnetic_field.y = float(imu_data[7]) * conversion_factor
        # mag_msg.magnetic_field.z = float(imu_data[8]) * conversion_factor
        
        # self.mag_pub.publish(mag_msg)
        
        # 3. 发布温度数据
        # temp_msg = Temperature()
        # temp_msg.header = Header()
        # temp_msg.header.stamp = current_time
        # temp_msg.header.frame_id = self.frame_id
        # temp_msg.temperature = float(imu_data[9])
        # self.temp_pub.publish(temp_msg)
        
        # 4. 发布压力数据
        # pressure_msg = Float32()
        # pressure_msg.data = float(imu_data[10])
        # self.pressure_pub.publish(pressure_msg)
        
        # 可选：记录日志，便于调试
        self.get_logger().info(
            f"IMU数据已发布: 陀螺仪({imu_data[0]:.3f}, {imu_data[1]:.3f}, {imu_data[2]:.3f})",
            throttle_duration_sec=1.0  # 限流，每秒最多打印一次
        )

    def destroy_node(self):
        """确保节点销毁时正确关闭串口"""
        if hasattr(self, 'ser') and self.ser.is_open:
            self.ser.close()
            self.get_logger().info("串口已关闭")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    imu_bridge_node = IMUROS2Bridge()
    try:
        rclpy.spin(imu_bridge_node)
    except KeyboardInterrupt:
        pass
    finally:
        imu_bridge_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()