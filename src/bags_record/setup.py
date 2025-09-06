from setuptools import find_packages, setup

package_name = 'bags_record'

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
    maintainer='yutou',
    maintainer_email='3186831775@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'imu_recorder = bags_record.imu_recorder:main',
            'lidar_recorder = bags_record.lidar_recorder:main',
            'multi_recorder = bags_record.mutli_recorder:main',
        ],
    },
)
