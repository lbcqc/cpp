cmake_minimum_required(VERSION 3.26)
project(leetcode CXX)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)

add_executable(leetcode-demo_template ./demo_template/main.cpp)

add_executable(leetcode-array-binary_search ./array/binary_search.cpp)
add_executable(leetcode-array-remove_duplicates ./array/remove_duplicates.cpp)
target_link_libraries(leetcode-array-remove_duplicates PRIVATE spdlog::spdlog)
add_executable(leetcode-array-variable_array ./array/variable_array.cpp)
add_executable(leetcode-array-plus_one ./array/plus_one.cpp)

add_executable(leetcode-list-reverse_list ./list/reverse_list.cpp)
add_executable(leetcode-list-k_group_reverse_list ./list/k_group_reverse_list.cpp)
add_executable(leetcode-list-find_neighbor_value ./list/find_neighbor_value.cpp)
add_executable(leetcode-list-linked_list_cycle ./list/linked_list_cycle.cpp)
add_executable(leetcode-list-linked_list_cycle_ii ./list/linked_list_cycle_ii.cpp)
add_executable(leetcode-list-merge_two_list ./list/merge_two_list.cpp)

add_executable(leetcode-stack-valid_bracket ./stack/valid_bracket.cpp)