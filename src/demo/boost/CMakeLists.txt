cmake_minimum_required(VERSION 3.19)
project(demo-boost CXX)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_HOME_DIRECTORY}/cmake/boost.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(demo-boost_multiprecision multiprecision.cpp)
target_link_libraries(demo-boost_multiprecision PRIVATE Boost::multiprecision)

add_executable(demo-boost_typeindex typeindex.cpp)
target_link_libraries(demo-boost_typeindex PRIVATE Boost::type_index)