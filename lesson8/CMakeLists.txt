cmake_minimum_required(VERSION 3.18)

project(TestJsonCpp VERSION 1.0.0 LANGUAGES CXX)

find_package(jsoncpp REQUIRED)

add_subdirectory(app)