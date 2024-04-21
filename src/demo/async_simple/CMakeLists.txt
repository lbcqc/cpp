cmake_minimum_required(VERSION 3.19)
project(demo-async_simple CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fsanitize=address  -static-libasan")

include(${CMAKE_HOME_DIRECTORY}/cmake/async_simple.cmake)

add_executable(demo-async_simple main.cpp)
target_link_libraries(demo-async_simple PRIVATE async_simple aio pthread)
