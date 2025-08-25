#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RoboNewsStationNode: public rclcpp::Node
{
public:
  RobotNewsStationNode()
  : Node("robot_news_station")
  {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("news", 10);
  }

private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}