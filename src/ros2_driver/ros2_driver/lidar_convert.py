#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
import numpy as np

from sensor_msgs.msg import PointCloud2
import sensor_msgs_py.point_cloud2 as pc2


class PointCloudYawFlipper(Node):
    def __init__(self):
        super().__init__('pointcloud_yaw_flipper')

        # 输入话题和输出话题
        self.sub = self.create_subscription(
            PointCloud2,
            '/livox/lidar',        # 输入点云话题
            self.cloud_callback,
            10
        )
        self.pub = self.create_publisher(
            PointCloud2,
            '/lidar_points_flipped',  # 输出点云话题
            10
        )

        self.get_logger().info("✅ PointCloudYawFlipper 已启动，正在翻转 yaw 方向 (y 取负)")

    def cloud_callback(self, msg: PointCloud2):
        # 读取点云
        points = np.array([
            [p[0], p[1], p[2]] for p in pc2.read_points(
                msg, field_names=("x", "y", "z"), skip_nans=True
            )
        ])

        if points.shape[0] == 0:
            return

        # 翻转 y 坐标，相当于 yaw 正方向取反
        flipped_points = points.copy()
        flipped_points[:, 1] *= -1

        # 重新打包 PointCloud2
        flipped_msg = pc2.create_cloud_xyz32(msg.header, flipped_points.tolist())

        # 发布
        self.pub.publish(flipped_msg)


def main(args=None):
    rclpy.init(args=args)
    node = PointCloudYawFlipper()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
