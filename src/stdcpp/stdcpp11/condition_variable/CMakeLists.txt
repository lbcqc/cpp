cmake_minimum_required(VERSION 3.26)
project(stdcpp11 CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(stdcpp11-condition_variable main.cpp)
target_link_libraries(stdcpp11-condition_variable PRIVATE pthread)