# 1. 找到所有的源文件
file(GLOB SRC_LISTS "src/*.cc")

# 2. 增加库
add_library(MyMath SHARED ${SRC_LISTS})

# 3. 设置动态库头文件
target_include_directories(MyMath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 4. 构建时动态库的目录
set_target_properties(MyMath PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)   