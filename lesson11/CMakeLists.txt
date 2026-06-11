cmake_minimum_required(VERSION 3.18)

project(Proto_Test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)

add_executable(demo main.cc proto/person.proto)

target_link_libraries(demo PRIVATE protobuf::libprotobuf)
target_include_directories(demo PRIVATE ${CMAKE_BINARY_DIR})

protobuf_generate(
    TARGET demo
    LANGUAGE cpp
    PROTOC_OUT_DIR ${CMAKE_BINARY_DIR}
)

set_target_properties(
    demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)




