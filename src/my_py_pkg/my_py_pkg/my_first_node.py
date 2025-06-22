#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__('py_test')  ## Initialize the node with a name
        self.counter_ = 0  ## Initialize a counter variable
        self.get_logger().info("Hello, once again, ROS 2 from Python!")  ## Log a message
        self.create_timer(1.0, self.timer_callback)
        
    def timer_callback(self):
        self.get_logger().info('Hello, from timer_callback! '+str(self.counter_))
        self.counter_ += 1

def main(args=None):
    rclpy.init(args=args) ## Initialize the ROS 2 Python client library
    ## need to do this for every ros program
    # your node here
    node = MyNode()  ## Log a message
    rclpy.spin(node)  ## Spin the node to keep it alive (optional, not used here)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()  ## Call the main function
    # rclpy.spin(node)  ## Spin the node to keep it alive (optional, not used here)
# This is a simple ROS 2 Python node that logs a message when run.
# It initializes the ROS 2 Python client library, creates a node, logs a message, and then shuts down.
# To run this node, you would typically use the command:
# ros2 run my_py_pkg my_first_node
# Note: Ensure that the package is built and sourced correctly before running the node.
# This code is part of a ROS 2 package named 'my_py_pkg'.
# Make sure to have the necessary dependencies installed and the package built.
# This code is a simple example of a ROS 2 Python node that logs a message.
# It serves as a starting point for creating more complex ROS 2 applications in Python.