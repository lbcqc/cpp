cmake_minimum_required(VERSION 3.28)
project(stdcpp CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(stdcpp
        main.cpp)

# stdcpp11
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/array/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/forward_list/)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/unordered_map/)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/unordered_set/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/tuple)