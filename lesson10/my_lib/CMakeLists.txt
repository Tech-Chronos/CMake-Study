# 1. 找到所有的源文件
file(GLOB SRC_LISTS "src/*.cc")

# 2. 增加库
add_library(MyMath SHARED ${SRC_LISTS})

# 3. 包含头文件
target_include_directories(MyMath PUBLIC
    "$<INSTALL_INTERFACE:include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

# 4. 设置库属性
set_target_properties(MyMath PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OUTPUT_NAME MyMath
    VERSION 1.2.3
    SOVERSION 1
    COMPILE_OPTIONS "-fPIC"
)

# 5. 安装库文件
include(GNUInstallDirs)
install(
    TARGETS MyMath
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 6. 安装头文件
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)
