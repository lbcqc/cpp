cmake_minimum_required(VERSION 3.26)
project(cpptest)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# 添加子工程
#add_subdirectory(src/demo)
#add_subdirectory(src/stdc)
add_subdirectory(src/stdcpp)
add_subdirectory(src/leetcode)

#############################################################
## PACK
#############################################################
## 设置生成的安装包名字
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
## 设置支持指定安装目录的控制为 ON
#set(CPACK_SET_DESTDIR ON)
## 设置安装到的目录路径
#set(CPACK_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install/)
## 这是生成的安装的版本号信息
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
## 设置 group 名字
#set(CPACK_RPM_PACKAGE_GROUP "cpptest")
## 设置 vendor 名字
#set(CPACK_PACKAGE_VENDOR "cpptest")
## 设置 license 信息
#set(CPACK_RPM_PACKAGE_LICENSE "Apache 2.0 + Common Clause 1.0")
## Binaries
#install (TARGETS stdcpp
#        DESTINATION bin)
## Config
#install (FILES .clang-format
#        DESTINATION etc)
#include(CPack)