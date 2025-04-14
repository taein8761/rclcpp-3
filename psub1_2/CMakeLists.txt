cmake_minimum_required(VERSION 3.16)
project(psub1_2)  # 'psub1_1' -> 'psub1_2'

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# build
add_executable(pub1_2 src/pub.cpp)  # 'pub1_1' -> 'pub1_2'
ament_target_dependencies(pub1_2 rclcpp std_msgs)

add_executable(sub1_2 src/sub.cpp)  # 'sub1_1' -> 'sub1_2'
ament_target_dependencies(sub1_2 rclcpp std_msgs)

# install
install(TARGETS
  pub1_2  # 'pub1_1' -> 'pub1_2'
  sub1_2  # 'sub1_1' -> 'sub1_2'
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
