cmake_minimum_required(VERSION 3.5)
project(simple_agent)

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Include headers
include_directories(include)

# Executable
add_executable(agent_node
  src/main.cpp
  src/agent.cpp
)

# Link dependencies
ament_target_dependencies(agent_node
  rclcpp
  geometry_msgs
)

# Install the binary
install(TARGETS agent_node
  DESTINATION lib/${PROJECT_NAME}
)

# Package export
ament_package()
