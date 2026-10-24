// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>

#include <libserial/SerialPort.h>

using namespace std::chrono_literals;


class SimpleSerialReceiver : public rclcpp::Node
{
public:
  SimpleSerialReceiver() : Node("simple_serial_receiver")
  {
    declare_parameter<std::string>("port", "/dev/ttyUSB0");

    port_ = get_parameter("port").as_string();

    arduino_.Open(port_);
    arduino_.SetBaudRate(LibSerial::BaudRate::BAUD_115200);

    pub_ = create_publisher<std_msgs::msg::String>("serial_receiver", 10);
    timer_ = create_wall_timer(0.01s, std::bind(&SimpleSerialReceiver::timerCallback, this));
  }

  ~SimpleSerialReceiver()
  {
    arduino_.Close();
  }

  void timerCallback()
  {
    if(rclcpp::ok() && arduino_.IsDataAvailable())
    {
      auto message = std_msgs::msg::String();
      arduino_.ReadLine(message.data);
      pub_->publish(message);
    }
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::string port_;
  LibSerial::SerialPort arduino_;
};


int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleSerialReceiver>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
