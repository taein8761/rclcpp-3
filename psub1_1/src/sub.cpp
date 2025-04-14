#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>

class SimpleSubscriber : public rclcpp::Node
{
public:
    SimpleSubscriber() : Node("node_sub1")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic_pub1", 10,
            [this](std_msgs::msg::String::UniquePtr msg) {
                RCLCPP_INFO(this->get_logger(), "Received message: %s", msg->data.c_str());
            });
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleSubscriber>());
    rclcpp::shutdown();
    return 0;
}
