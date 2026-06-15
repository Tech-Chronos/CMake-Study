cmake_minimum_required(VERSION 3.18)

project(ProtoBuf_Demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)

# 收集所有的 .proto 文件
file(GLOB Proto_Lists ${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/proto)

# 设置源文件和头文件的列表
set(SRCS "")
set(HEADS "")

# 对每个proto文件生成对应的 xxx.pb.h & xxx.pb.cc
foreach(PROTO ${Proto_Lists})
    get_filename_component(PREFIX_NAME ${PROTO} NAME_WE) # 没有后缀名 without extension

    list(APPEND SRCS ${CMAKE_BINARY_DIR}/proto/${PREFIX_NAME}.pb.cc)
    list(APPEND HEADS ${CMAKE_BINARY_DIR}/proto/${PREFIX_NAME}.pb.h)

    # 通常就是为了生成 pb.cc 和 pb.h
    add_custom_command(
        OUTPUT
            ${CMAKE_BINARY_DIR}/proto/${PREFIX_NAME}.pb.h
            ${CMAKE_BINARY_DIR}/proto/${PREFIX_NAME}.pb.cc
        COMMAND
            protobuf::protoc 
        ARGS
            --cpp_out=${CMAKE_BINARY_DIR}/proto
            -I ${CMAKE_CURRENT_SOURCE_DIR}/proto # 告诉 protoc，import从哪里找
            ${PROTO} # 依赖这个文件生成 pb.h 和 pb.cc
        DEPENDS # 如果这个文件变化，需要重新执行 protoc
            ${PROTO}
        VERBATIM
    )
endforeach()

# 必须要有目标依赖生成的 pb.h 和 pb.cc文件，如果没有目标依赖，就不会生成 pb.h 和 pb.cc文件
add_custom_target(
    generate_proto
    DEPENDS
        ${SRCS} ${HEADS}
)

# 将 生成的proto源文件构建成动态库
add_library(MyProto SHARED ${SRCS})
# 但是这个时候并没有生成 srcs，要依赖于 generate_proto 这个目标先去生成 srcs
add_dependencies(MyProto generate_proto)
# 编译这个动态库依赖于 libprotobuf
target_link_libraries(MyProto PUBLIC protobuf::libprotobuf)
target_include_directories(MyProto INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(
    MyProto PROPERTIES 
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 添加可执行文件
add_executable(demo main.cc)
target_link_libraries(demo PRIVATE MyProto)

set_target_properties(
    demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)







