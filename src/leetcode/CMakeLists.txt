cmake_minimum_required(VERSION 3.26)
project(leetcode CXX)

set(CMAKE_CXX_STANDARD 23)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)
include(${CMAKE_HOME_DIRECTORY}/cmake/fmtlib.cmake)

add_executable(leetcode-demo_template ./demo_template/main.cpp)
target_link_libraries(leetcode-demo_template PRIVATE spdlog::spdlog)

# array
add_executable(leetcode-array-binary_search ./array/binary_search.cpp)
add_executable(leetcode-array-remove_duplicates ./array/remove_duplicates.cpp)
target_link_libraries(leetcode-array-remove_duplicates PRIVATE spdlog::spdlog)
add_executable(leetcode-array-variable_array ./array/variable_array.cpp)
add_library(leetcode-array-plus_one ./array/plus_one.cpp)

# heap
add_executable(leetcode-heap-max_sliding_windwos ./heap/max_sliding_windwos.cpp)
target_link_libraries(leetcode-heap-max_sliding_windwos PRIVATE fmt::fmt)

# list
add_executable(leetcode-list-reverse_list ./list/reverse_list.cpp)
add_executable(leetcode-list-k_group_reverse_list ./list/k_group_reverse_list.cpp)
add_executable(leetcode-list-find_neighbor_value ./list/find_neighbor_value.cpp)
add_executable(leetcode-list-linked_list_cycle ./list/linked_list_cycle.cpp)
add_executable(leetcode-list-linked_list_cycle_ii ./list/linked_list_cycle_ii.cpp)
add_library(leetcode-list-merge_two_list ./list/merge_two_list.cpp)
add_executable(leetcode-list-palindrome_list ./list/palindrome_list.cpp)

# point
add_executable(leetcode-point-trap point/trap.cpp)
add_library(leetcode-point-two_sum point/two_sum.cpp)
add_library(leetcode-point-two_sum_ii point/two_sum_ii.cpp)
add_library(leetcode-point-three_sum point/three_sum.cpp)
add_library(leetcode-point-max_area point/max_area.cpp)

# prefixsum-diff
add_library(leetcode-prefixsum-diff-number_of_subarrays ./prefixsum-diff/number_of_subarrays.cpp)
add_library(leetcode-prefixsum-diff-max_sub_array ./prefixsum-diff/max_sub_array.cpp)
add_library(leetcode-prefixsum-diff-range_sum_query_2d_immutable ./prefixsum-diff/range_sum_query_2d_immutable.cpp)
add_library(leetcode-prefixsum-diff-corp_fligh_bookings ./prefixsum-diff/corp_fligh_bookings.cpp)

# queue
add_executable(leetcode-queue-max_sliding_windwos ./queue/max_sliding_windows.cpp)
add_library(leetcode-queue-double_queue ./queue/double_queue.cpp)

# recursion
add_library(leetcode-recursion-subsets ./recursion/subsets.cpp)
add_library(leetcode-recursion-combinations ./recursion/combinations.cpp)
add_library(leetcode-recursion-premute ./recursion/premute.cpp)

# stack
add_library(leetcode-stack-valid_bracket ./stack/valid_bracket.cpp)
add_executable(leetcode-stack-min_stack ./stack/min_stack.cpp)
add_executable(leetcode-stack-reverse_polish_notation ./stack/reverse_polish_notation.cpp)
add_executable(leetcode-stack-largest_rectangle_area ./stack/largest_rectangle_area.cpp)
add_library(leetcode-stack-largest_rectangle ./stack/largest_rectangle.cpp)
add_executable(leetcode-stack-calculator-iii ./stack/basic_calculator_iii.cpp)
add_executable(leetcode-stack-asteroids ./stack/asteroids.cpp)
target_link_libraries(leetcode-stack-asteroids PRIVATE spdlog::spdlog)
add_library(leetcode-stack_daily_temperatures ./stack/daily_temperatures.cpp)

# tree
add_library(leetcode-tree-invert_tree ./tree/invert_tree.cpp)
add_library(leetcode-tree-check_bst ./tree/check_bst.cpp)
add_library(leetcode-tree-min_depth ./tree/min_depth.cpp)
add_library(leetcode-tree-lowest_common_ancestor ./tree/lowest_common_ancestor.cpp)

# recursion
add_executable(leetcode-recusion-calculate stack/calculate.cpp)

# dp
add_library(leetcode-dp-climbing_stairs dp/climbing_stairs.cpp)
add_library(leetcode-dp-min_cost_climbing_stairs dp/min_cost_climbing_stairs.cpp)
add_executable(leetcode-dp-climbing_stairs_ii dp/climbing_stairs_ii.cpp)
add_executable(leetcode-dp-bag01 dp/bag01.cpp)
add_executable(leetcode-dp-bagfull dp/bagfull.cpp)
add_executable(leetcpde-dp-maximal_square dp/maximal_square.cpp)

# bitmap
add_executable(leetcode-bitmap_longest_consecutive ./bitmap/longest_consecutive.cpp)
add_library(leetcode-bitmap_intersection_node ./bitmap/intersection_node.cpp)

# greedy
add_executable(leetcodt-greedy_wiggle_max_length greedy/wiggle_max_length.cpp)
add_executable(leetcode-greedy_max_sub_array greedy/max_sub_array.cpp)
add_executable(leetcode-greedy_erase_overlap_intervals greedy/erase_overlap_intervals.cpp)
add_executable(leetcode-greedy_min_meeting_rooms greedy/min_meeting_rooms.cpp)
add_executable(leetcode-greedy_partitional_labels greedy/partitional_labels.cpp)
target_link_libraries(leetcode-greedy_partitional_labels PRIVATE spdlog::spdlog)