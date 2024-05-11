cmake_minimum_required(VERSION 3.19)
project(demo-gflags CXX)

include(${CMAKE_HOME_DIRECTORY}/cmake/spdlog.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-spdlog main.cpp)
target_link_libraries(demo-spdlog PRIVATE spdlog::spdlog)