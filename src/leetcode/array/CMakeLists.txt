cmake_minimum_required(VERSION 3.26)
project(leetcode-array CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode-array-binary_search binary_search.cpp)

add_executable(leetcode-array-remove_duplicates remove_duplicates.cpp)
target_link_libraries(leetcode-array-remove_duplicates PRIVATE spdlog::spdlog)