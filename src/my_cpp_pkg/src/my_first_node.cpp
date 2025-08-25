#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(), "Hello world");
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
         std::bind(&MyNode::timerCallback, this));
    }
private:
    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(), "Timer callback executed");
        counter_++;
    }
    rclcpp::TimerBase::SharedPtr timer_; 
    int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // Initialize the ROS2 communication system
    auto node = std::make_shared<MyNode>(); // Create an instance of MyNode
    rclcpp::spin(node); // Spin the node to keep it active and processing callbacks
    rclcpp::shutdown(); // Shutdown the ROS2 communication system
    return 0; // Return 0 to indicate successful execution  
}