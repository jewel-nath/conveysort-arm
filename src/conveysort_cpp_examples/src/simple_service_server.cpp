// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

#include <rclcpp/rclcpp.hpp>
#include "conveysort_msgs/srv/add_two_ints.hpp"

#include <memory>


using namespace std::placeholders;

class SimpleServiceServer : public rclcpp::Node
{
public:
    SimpleServiceServer() : Node("simple_service_server")
    {
        service_ = create_service<conveysort_msgs::srv::AddTwoInts>("add_two_ints", std::bind(&SimpleServiceServer::serviceCallback, this, _1, _2));
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service add_two_ints Ready");
    }


private:
    rclcpp::Service<conveysort_msgs::srv::AddTwoInts>::SharedPtr service_;

    void serviceCallback(const std::shared_ptr<conveysort_msgs::srv::AddTwoInts::Request> req,
                         const std::shared_ptr<conveysort_msgs::srv::AddTwoInts::Response> res)
    {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "New Request Received a: " << req->a << " b: " << req->b);
        res->sum = req->a + req->b;
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Returning sum: " << res->sum);
    }

};


int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleServiceServer>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
