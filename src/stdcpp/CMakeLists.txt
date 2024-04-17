cmake_minimum_required(VERSION 3.28)
project(stdcpp CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(stdcpp main.cpp)

# basic
add_subdirectory(basic/string)
add_subdirectory(basic/typename)

# stdcpp98
add_subdirectory(stdcpp98/list)
add_subdirectory(stdcpp98/set)

# stdcpp11
add_subdirectory(stdcpp11/array/)
add_subdirectory(stdcpp11/forward_list/)
#add_subdirectory(stdcpp11/unordered_map/)
#add_subdirectory(stdcpp11/unordered_set/)
add_subdirectory(stdcpp11/tuple)
add_subdirectory(stdcpp11/transform)
add_subdirectory(stdcpp11/enumclass)
add_subdirectory(stdcpp11/initializer_list)
add_subdirectory(stdcpp11/rvo)
add_subdirectory(stdcpp11/ref)
add_subdirectory(stdcpp11/async)
add_subdirectory(stdcpp11/decltype)
add_subdirectory(stdcpp11/constexpr)
add_subdirectory(stdcpp11/for_range)
add_subdirectory(stdcpp11/lrvalue)
add_subdirectory(stdcpp11/function)
add_subdirectory(stdcpp11/unique_ptr)
add_subdirectory(stdcpp11/weak_ptr)

#stdcpp14
add_subdirectory(stdcpp14/decltype_auto)


# stdcpp17
add_subdirectory(stdcpp17/fold_expressions)
add_subdirectory(stdcpp17/structured_binding)

# stdcpp20
add_subdirectory(stdcpp20/strong_ordering)