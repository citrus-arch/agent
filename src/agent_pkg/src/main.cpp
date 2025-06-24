#include "agent_pkg/agent.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Agent>());
    rclcpp::shutdown();
    return 0;
}
