// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


using std::placeholders::_1;

class SimpleSubscriber : public rclcpp::Node
{
public:
  SimpleSubscriber() : Node("simple_subscriber")
  {
    sub_ = create_subscription<std_msgs::msg::String>(
        "chatter", 10, std::bind(&SimpleSubscriber::msgCallback, this, _1));
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  void msgCallback(const std_msgs::msg::String &msg) const
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: " << msg.data.c_str());
  }
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleSubscriber>());
  rclcpp::shutdown();
  return 0;
}
