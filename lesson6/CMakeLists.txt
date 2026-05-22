# 设置最低版本
cmake_minimum_required(VERSION 3.18)

# 项目名称
project(main VERSION 1.0.0 LANGUAGES CXX)

# 子目录
add_subdirectory(my_lib)
add_subdirectory(app)