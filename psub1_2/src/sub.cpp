#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <memory>

class IntSubscriber : public rclcpp::Node
{
public:
    IntSubscriber() : Node("node_sub2")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "topic_pub2", 10,
            [this](std_msgs::msg::Int32::UniquePtr msg) {
                RCLCPP_INFO(this->get_logger(), "Received: %d", msg->data);
            });
    }

private:
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<IntSubscriber>());
    rclcpp::shutdown();
    return 0;
}
