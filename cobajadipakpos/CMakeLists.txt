cmake_minimum_required(VERSION 2.8.3)
project(cobajadipakpos)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


add_message_files(
  FILES
  Num.msg
)

add_service_files(
  FILES
  AddTwoInts.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES beginner_tutorials
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
  DEPENDS system_lib
)



###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pakpos src/pakpos.cpp)
target_link_libraries(pakpos ${catkin_LIBRARIES})
add_dependencies(pakpos cobajadipakpos_generate_messages_cpp)

add_executable(customers src/customers.cpp)
target_link_libraries(customers ${catkin_LIBRARIES})
add_dependencies(customers cobajadipakpos_generate_messages_cpp)


