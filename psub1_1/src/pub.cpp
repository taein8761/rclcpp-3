#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <chrono>

using namespace std::chrono_literals;

class TimerPublisher : public rclcpp::Node
{
public:
    TimerPublisher() : Node("node_pub1")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic_pub1", 10);
        timer_ = this->create_wall_timer(
            100ms, std::bind(&TimerPublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        std_msgs::msg::String msg;
        msg.data = "Hello world!";
        RCLCPP_INFO(this->get_logger(), "Publish: %s", msg.data.c_str());
        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimerPublisher>());
    rclcpp::shutdown();
    return 0;
}
