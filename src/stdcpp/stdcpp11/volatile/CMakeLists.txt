cmake_minimum_required(VERSION 3.26)
project(stdcpp11 CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
add_executable(stdcpp11-volatile main.cpp)
target_link_libraries(stdcpp11-volatile pthread)