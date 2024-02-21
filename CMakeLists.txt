# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER "clang++")

# 添加子目录
add_subdirectory(array)
add_subdirectory(backtracking)
# add_subdirectory(BiTree)
# add_subdirectory(hash)
# add_subdirectory(linkedlist)
# add_subdirectory(stackqueue)
# add_subdirectory(string)
# ... 添加更多子目录
