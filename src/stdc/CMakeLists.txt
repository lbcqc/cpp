cmake_minimum_required(VERSION 3.26)
project(stdc C)

set(CMAKE_C_STANDARD 17)

add_executable(stdc-test main.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/jmpbuf)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pthread)