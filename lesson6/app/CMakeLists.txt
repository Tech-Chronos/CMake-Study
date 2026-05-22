# 添加可执行
add_executable(main main.cc)

# 可执行依赖的库
target_link_libraries(main PRIVATE MyMath)

# 设置属性 
# $ORIGIN 表示当前可执行程序所在的目录
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin 
                        INSTALL_RPATH "$ORIGIN/../lib")
