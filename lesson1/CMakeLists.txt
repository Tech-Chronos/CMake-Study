# 设置 cmake 最低 版本
cmake_minimum_required(VERSION 3.18)

# 设置项目名称
project(hello VERSION 1.0 LANGUAGES CXX)
message(STATUS"PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")

# 项目构建
set(ProjName hello)
add_executable(${ProjName} hello.cc)