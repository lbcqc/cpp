cmake_minimum_required(VERSION 3.19)
project(demo-gflags CXX)

include(FetchContent)
FetchContent_Declare(flag
        GIT_REPOSITORY https://github.com/gflags/gflags.git
        GIT_TAG v2.2.2
)
FetchContent_MakeAvailable(flag)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-gflags gflags.cpp)
target_link_libraries(demo-gflags PRIVATE gflags::gflags)