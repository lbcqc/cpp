cmake_minimum_required(VERSION 3.26)
project(stdcpp11 CXX)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11 -fno-elide-constructors")

add_executable(stdcpp11-rvo main.cpp)