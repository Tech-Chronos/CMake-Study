# 增加可执行文件
add_executable(main main.cc)

# 链接哪个库
target_link_libraries(main PRIVATE MyMath)

# 设置属性
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)