cmake_minimum_required(VERSION 3.26)
project(stdcpp11 CXX)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(stdcpp11-array main.cpp)
target_link_libraries(stdcpp11-array PRIVATE fmt)