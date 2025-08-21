cmake_minimum_required(VERSION 3.26)
project(remove_duplicates CXX)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode-remove_duplicates main.cpp)
target_link_libraries(leetcode-remove_duplicates PRIVATE spdlog::spdlog)