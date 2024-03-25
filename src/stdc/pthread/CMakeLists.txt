cmake_minimum_required(VERSION 3.28)
project(stdc C)

set(CMAKE_C_STANDARD 17)

add_executable(stdc-pthread
        main.c)

target_link_libraries(stdc-pthread pthread)