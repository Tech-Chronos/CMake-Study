# # 1. 搜集源文件
# file(GLOB SRC_LISTS "src/*.cc")

# # 2. 增加库
# add_library(MyMath STATIC ${SRC_LISTS})

# # 3. 设置库的属性
# target_include_directories(MyMath INTERFACE 
#     "$<INSTALL_INTERFACE:include>" # /usr/local/include
#     "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
# )

# # 4. 设置库的输出路径
# set_target_properties(MyMath PROPERTIES 
#     ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
# )

# # 5. 安装库文件
# include(GNUInstallDirs)
# install(TARGETS MyMath 
#     EXPORT MyMathTargets # 导出目标集合的名称
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )

# # 6. 安装头文件
# install(DIRECTORY include/
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/math
#     FILES_MATCHING PATTERN "*.h"
# )

# # 7. 安装导出目标集合 到 构建树
# export(EXPORT MyMathTargets 
#     FILE ${CMAKE_CURRENT_BINARY_DIR}/MyMathTargets.cmake # 指定安装的路径和名称
# )

# # 8. 安装导出的目标集合 到 安装树
# install(EXPORT MyMathTargets
#     FILE MyMathTargets.cmake
#     NAMESPACE MyMath:: # 命名空间
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyMath
# )

# # 9. 生成 find_package 所需要的配置文件
# include(CMakePackageConfigHelpers)
# ## 根据输入模版生成配置文件
# configure_package_config_file(
#     ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in # 这个是安装模版
#     ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake # 这个是安装到哪里，文件名是什么
#     INSTALL_DESTINATION "lib/cmake/MyMath"
# )

# 10. 将配置文件安装到指定的目录
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
#     DESTINATION "lib/cmake/MyMath"
# )

# 1. 搜集源文件
file(GLOB SRC_LISTS "src/*.cc")

# 2. 添加库文件
add_library(MyMath STATIC ${SRC_LISTS})

# 3. 库依赖的头文件
target_include_directories(MyMath INTERFACE 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# 4. 设置库的输出路径
set_target_properties(MyMath PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 5. 安装库
include(GNUInstallDirs)
install(TARGETS MyMath
    EXPORT MyMathTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# 6. 安装头文件
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/math
    FILES_MATCHING PATTERN "*.h"
)

# 7. 将导出的目标集合安装到构建树
# 导出一个已经定义好的导出集
export(EXPORT MyMathTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/MyMathTargets.cmake
)

# 8. 将导出的目标集合安装到系统树
install(EXPORT MyMathTargets
    FILE MyMathTargets.cmake
    NAMESPACE mymath::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

# 9. 生成find_package()所需的 XxxConfig.cmake
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
    INSTALL_DESTINATION lib/cmake/mymath
)

# 10. 导出配置文件到系统路径
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/MyMathConfig.cmake
    DESTINATION lib/cmake/mymath
)