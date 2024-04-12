cmake_minimum_required(VERSION 3.28)
project(stdcpp CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(stdcpp main.cpp)

# basic
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/basic/string)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/basic/typename)

# stdcpp98
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp98/list)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp98/set)

# stdcpp11
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/array/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/forward_list/)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/unordered_map/)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/unordered_set/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/tuple)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/transform)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/enumclass)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/initializer_list)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/rvo)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/ref)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/async)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/decltype)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/constexpr)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/for_range)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/lrvalue)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp11/function)

#stdcpp14
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp14/decltype_auto)

# stdcpp17
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp17/fold_expressions)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp17/structured_binding)

# stdcpp20
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stdcpp20/strong_ordering)