# 收集 .cc 文件
file(GLOB SOURCE_LISTS "src/*.cc")

# 生成静态库
# 库名称 + 库类型 + 依赖源文件
add_library(MyMath STATIC ${SOURCE_LISTS})

# 头文件
target_include_directories(MyMath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 静态库在 顶级构建目录中 的 路径
# 库名称 + 属性 + 类型（动态/静态/可执行） + 路径
set_target_properties(MyMath PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)