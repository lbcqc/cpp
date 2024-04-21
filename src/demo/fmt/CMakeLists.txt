cmake_minimum_required(VERSION 3.19)
project(demo-fmt CXX)

include(${CMAKE_HOME_DIRECTORY}/cmake/fmtlib.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-fmt fmt.cpp)
target_link_libraries(demo-fmt PRIVATE fmt::fmt)