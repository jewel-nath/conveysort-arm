# Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
# Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
# Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
# and in some files the arm's joints and servos.

cmake_minimum_required(VERSION 3.8)
project(conveysort_utils)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(conveysort_msgs REQUIRED)
find_package(tf2 REQUIRED)

add_executable(angle_conversion src/angle_conversion.cpp)
ament_target_dependencies(angle_conversion rclcpp conveysort_msgs tf2)

ament_python_install_package(${PROJECT_NAME})

install(TARGETS
  angle_conversion
  DESTINATION lib/${PROJECT_NAME}
)

install(PROGRAMS
  ${PROJECT_NAME}/angle_conversion.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
