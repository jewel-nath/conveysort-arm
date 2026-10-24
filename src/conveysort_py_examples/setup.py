# Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
# Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
# Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
# and in some files the arm's joints and servos.

from setuptools import setup

package_name = 'conveysort_py_examples'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Jewel Nath',
    maintainer_email='58494211+jewel-nath@users.noreply.github.com',
    description='ROS 2 Code Examples',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'simple_publisher = conveysort_py_examples.simple_publisher:main',
            'simple_subscriber = conveysort_py_examples.simple_subscriber:main',
            'simple_parameter = conveysort_py_examples.simple_parameter:main',
            'simple_moveit = conveysort_py_examples.simple_moveit_interface:main',
            'simple_service_server = conveysort_py_examples.simple_service_server:main',
            'simple_service_client = conveysort_py_examples.simple_service_client:main',
            'simple_action_server = conveysort_py_examples.simple_action_server:main',
            'simple_action_client = conveysort_py_examples.simple_action_client:main',
        ],
    },
)
