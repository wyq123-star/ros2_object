from setuptools import find_packages, setup

package_name = 'example_topic_rclpy'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fishros',
    maintainer_email='yutouxiaozhuang@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "topic_subscriber_02 = example_topic_rclpy.topic_subscriber_02:main",
            "topic_publisher_02 = example_topic_rclpy.topic_publisher_02:main",
            "server = example_topic_rclpy.server:main",
        ],
    },
)
