cmake_minimum_required(VERSION 3.19)
project(demo-fmt CXX)

include(FetchContent)
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-fmt fmt.cpp)
target_link_libraries(demo-fmt PRIVATE fmt::fmt)