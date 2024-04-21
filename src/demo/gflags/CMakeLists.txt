cmake_minimum_required(VERSION 3.19)
project(demo-gflags CXX)

include(${CMAKE_HOME_DIRECTORY}/cmake/gflags.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-gflags gflags.cpp)
target_link_libraries(demo-gflags PRIVATE gflags::gflags)