cmake_minimum_required(VERSION 3.28)
project(stdcpp11 CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(stdcpp11-future main.cpp)
target_link_libraries(stdcpp11-future pthread)