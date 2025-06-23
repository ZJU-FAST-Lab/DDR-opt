cmake_minimum_required(VERSION 3.0.2)
project(to_real_cmd)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  carstatemsgs
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(real_cmd src/to_real_cmd_node.cpp)

target_link_libraries(real_cmd
  ${catkin_LIBRARIES}
)


