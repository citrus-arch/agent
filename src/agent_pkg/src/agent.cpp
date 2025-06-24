#include "agent_pkg/agent.hpp"

Agent::Agent() : Node("agent_node")
{
    pose_pub_ = this->create_publisher<geometry_msgs::msg::Pose>("agent_pose", 10);
    goal_sub_ = this->create_subscription<geometry_msgs::msg::Pose>(
        "agent_goal", 10,
        std::bind(&Agent::goal_callback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&Agent::publish_pose, this));
}

void Agent::goal_callback(const geometry_msgs::msg::Pose::SharedPtr msg)
{
    current_pose_ = *msg;
}

void Agent::publish_pose()
{
    pose_pub_->publish(current_pose_);
}
