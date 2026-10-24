// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

#include <rclcpp/rclcpp.hpp>
#include "conveysort_msgs/srv/euler_to_quaternion.hpp"
#include "conveysort_msgs/srv/quaternion_to_euler.hpp"
#include <tf2/utils.h>

#include <memory>


using namespace std::placeholders;

class AnglesConverter : public rclcpp::Node
{
public:
    AnglesConverter() : Node("simple_service_server")
    {
        euler_to_quaternion_ = create_service<conveysort_msgs::srv::EulerToQuaternion>("euler_to_quaternion", 
            std::bind(&AnglesConverter::eulerToQuaternionCallback, this, _1, _2));
        quaternion_to_euler_ = create_service<conveysort_msgs::srv::QuaternionToEuler>("quaternion_to_euler", 
            std::bind(&AnglesConverter::quaternionToEulerCallback, this, _1, _2));
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Angles conversion services are ready");
    }


private:
    rclcpp::Service<conveysort_msgs::srv::EulerToQuaternion>::SharedPtr euler_to_quaternion_;
    rclcpp::Service<conveysort_msgs::srv::QuaternionToEuler>::SharedPtr quaternion_to_euler_;

    void eulerToQuaternionCallback(const std::shared_ptr<conveysort_msgs::srv::EulerToQuaternion::Request> req,
                                   const std::shared_ptr<conveysort_msgs::srv::EulerToQuaternion::Response> res)
    {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Requested to convert euler angles roll: " << req->roll << 
                                                         ", pitch: " << req->pitch << ", yaw: " << req->yaw <<
                                                         ", into a quaternion.");
        // Calculate quaternion from euler
        tf2::Quaternion q;
        q.setRPY(req->roll, req->pitch, req->yaw);
        res->x = q.getX();
        res->y = q.getY();
        res->z = q.getZ();
        res->w = q.getW();
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Corresponding quaternion x: " << res->x << 
                                                         ", y: " << res->y << ", z: " << res->z << 
                                                         ", w: " << res->w);
    }

    void quaternionToEulerCallback(const std::shared_ptr<conveysort_msgs::srv::QuaternionToEuler::Request> req,
                                   const std::shared_ptr<conveysort_msgs::srv::QuaternionToEuler::Response> res)
    {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Requested to convert quaternion x: " << req->x << 
                                                         ", y: " << req->y << ", z: " << req->z << 
                                                         ", w: " << req->w << ", into euler angles.");
        // Calculate euler from quaternion
        tf2::Quaternion q(req->x, req->y, req->z, req->w);
        tf2::Matrix3x3 m(q);
        m.getRPY(res->roll, res->pitch, res->yaw);
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Corresponding euler angles roll: " << res->roll << 
                                                         ", pitch: " << res->pitch << ", yaw: " << res->yaw);
    }

};


int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<AnglesConverter>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
