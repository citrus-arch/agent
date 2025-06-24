#ifndef AGENT_HPP
#define AGENT_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"

class Agent : public rclcpp::Node
{
public:
    Agent();
private:
    void goal_callback(const geometry_msgs::msg::Pose::SharedPtr msg);
    void publish_pose();

    rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr pose_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr goal_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
    geometry_msgs::msg::Pose current_pose_;
};

#endif // AGENT_HPP
