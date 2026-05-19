# 1. 最低版本
cmake_minimum_required(VERSION 3.18)

# 2. 构建的项目名称
project(test VERSION 1.0)

# 设置 cpp 标准
set(CMAKE_CXX_STANDARD 17)

# 3. 项目构建
add_executable(mytest1 test.cc)
add_executable(mytest2 test2.cc)
# 4. 测试
enable_testing()
add_test(NAME test1 COMMAND mytest)
add_test(NAME test2 COMMAND mytest2)

# 5. 本地安装
include(GNUInstallDirs)
install(TARGETS mytest1)

# 6. 打包
include(CPack)



