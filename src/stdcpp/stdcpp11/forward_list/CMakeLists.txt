CMAKE_MINIMUM_REQUIRED(VERSION 3.19)
project(stdcpp11 CXX)

include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(stdcpp11-forward_list main.cpp)
target_link_libraries(stdcpp11-forward_list PRIVATE fmt::fmt)