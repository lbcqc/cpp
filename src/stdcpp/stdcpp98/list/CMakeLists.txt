cmake_minimum_required(VERSION 3.26)
project(stdcpp98 CXX)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(stdcpp98-list main.cpp)
target_link_libraries(stdcpp98-list PRIVATE fmt)