from setuptools import find_packages
from setuptools import setup

setup(
    name='greenstory_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('greenstory_interfaces', 'greenstory_interfaces.*')),
)
