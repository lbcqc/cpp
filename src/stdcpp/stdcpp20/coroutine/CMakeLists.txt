cmake_minimum_required(VERSION 3.26)
project(stdcpp20 CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(stdcpp20-coroutine main.cpp)
target_link_libraries(stdcpp20-coroutine pthread)