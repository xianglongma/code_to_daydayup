cmake_minimum_required(VERSION 3.23)
project(code_to_daydayup)

set(CMAKE_CXX_STANDARD 14)

# 包含路径
include_directories(array)
# 源文件路径
aux_source_directory (array SRC_ARRAY)

add_executable(code_to_daydayup
        main.cpp ${SRC_ARRAY})
