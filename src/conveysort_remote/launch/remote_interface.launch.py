# Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
# Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
# Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
# and in some files the arm's joints and servos.

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    task_server_node = Node(
        package="conveysort_remote",
        executable="task_server_node",
    )

    alexa_interface_node = Node(
        package="conveysort_remote",
        executable="alexa_interface.py",
    )

    return LaunchDescription([
        task_server_node,
        alexa_interface_node
    ])
