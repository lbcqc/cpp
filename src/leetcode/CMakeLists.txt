cmake_minimum_required(VERSION 3.26)
project(leetcode CXX)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)

add_subdirectory(demo_template)
add_subdirectory(array)