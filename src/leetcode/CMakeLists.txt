cmake_minimum_required(VERSION 3.26)
project(leetcode CXX)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)

add_executable(leetcode-demo_template ./demo_template/main.cpp)

# array
add_executable(leetcode-array-binary_search ./array/binary_search.cpp)
add_executable(leetcode-array-remove_duplicates ./array/remove_duplicates.cpp)
target_link_libraries(leetcode-array-remove_duplicates PRIVATE spdlog::spdlog)
add_executable(leetcode-array-variable_array ./array/variable_array.cpp)
add_executable(leetcode-array-plus_one ./array/plus_one.cpp)

# heap
add_executable(leetcode-heap-max_sliding_windwos ./heap/max_sliding_windwos.cpp)

# list
add_executable(leetcode-list-reverse_list ./list/reverse_list.cpp)
add_executable(leetcode-list-k_group_reverse_list ./list/k_group_reverse_list.cpp)
add_executable(leetcode-list-find_neighbor_value ./list/find_neighbor_value.cpp)
add_executable(leetcode-list-linked_list_cycle ./list/linked_list_cycle.cpp)
add_executable(leetcode-list-linked_list_cycle_ii ./list/linked_list_cycle_ii.cpp)
add_executable(leetcode-list-merge_two_list ./list/merge_two_list.cpp)

# point
add_executable(leetcode-point-trap point/trap.cpp)
add_executable(leetcode-point-two_sum point/two_sum.cpp)
add_executable(leetcode-point-two_sum_ii point/two_sum_ii.cpp)
add_executable(leetcode-point-three_sum point/three_sum.cpp)
add_executable(leetcode-point-max_area point/max_area.cpp)

# prefixsum-diff
add_executable(leetcode-prefixsum-diff-number_of_subarrays ./prefixsum-diff/number_of_subarrays.cpp)
add_executable(leetcode-prefixsum-diff-max_sub_array ./prefixsum-diff/max_sub_array.cpp)
add_executable(leetcode-prefixsum-diff-range_sum_query_2d_immutable ./prefixsum-diff/range_sum_query_2d_immutable.cpp)
add_executable(leetcode-prefixsum-diff-corp_fligh_bookings ./prefixsum-diff/corp_fligh_bookings.cpp)

# queue
add_executable(leetcode-queue-max_sliding_windwos ./queue/max_sliding_windows.cpp)
add_executable(leetcode-queue-double_queue ./queue/double_queue.cpp)

# recursion
add_executable(leetcode-recursion-subsets ./recursion/subsets.cpp)
add_executable(leetcode-recursion-combinations ./recursion/combinations.cpp)
add_executable(leetcode-recursion-premute ./recursion/premute.cpp)

# stack
add_executable(leetcode-stack-valid_bracket ./stack/valid_bracket.cpp)
add_executable(leetcode-stack-min_stack ./stack/min_stack.cpp)
add_executable(leetcode-stack-reverse_polish_notation ./stack/reverse_polish_notation.cpp)
add_executable(leetcode-stack-largest_rectangle_area ./stack/largest_rectangle_area.cpp)
add_executable(leetcode-stack-largest_rectangle ./stack/largest_rectangle.cpp)

# tree
add_executable(leetcode-tree-invert_tree ./tree/invert_tree.cpp)
add_executable(leetcode-tree-check_bst ./tree/check_bst.cpp)
add_executable(leetcode-tree-min_depth ./tree/min_depth.cpp)

# recursion
add_executable(leetcode-recusion-calculate stack/calculate.cpp)