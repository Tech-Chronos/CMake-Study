cmake_minimum_required(VERSION 3.18)

project(test)

message(STATUS "project name:" ${PROJECT_NAME})
message(STATUS "project source dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "project binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "cmake source dir: " ${CMAKE_SOURCE_DIR})
message(STATUS "cmake binary dir: " ${CMAKE_BINARY_DIR})

add_executable(main main.cc)

