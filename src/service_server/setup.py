from setuptools import find_packages, setup

package_name = 'service_server'

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
    maintainer_email='yutouxiaozhuang@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "service_client = service_server.service_client:main",
            "service = service_server.service_server:main",
            "server = service_server.server:main",
        ],
    },
)
