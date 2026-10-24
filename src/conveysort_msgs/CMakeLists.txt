# Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
# Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
# Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
# and in some files the arm's joints and servos.

cmake_minimum_required(VERSION 3.8)
project(conveysort_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/AddTwoInts.srv"
  "srv/EulerToQuaternion.srv"
  "srv/QuaternionToEuler.srv"
  "action/Fibonacci.action"
  "action/ConveysortTask.action"
)

ament_package()
