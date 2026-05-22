# 找包含头文件的路径，放到 MyMath_INCLUDE_DIR 中
find_path(MyMath_INCLUDE_DIR NAME math.h PATHS ${CMAKE_CURRENT_LIST_DIR}/../my_lib/include NO_DEFAULT_PATH)

# 找库的路径，放到 MyMath_LIBRARY 中
find_library(MyMath_LIBRARY NAME MyMath PATHS ${CMAKE_CURRENT_LIST_DIR}/../my_lib/src NO_DEFAULT_PATH)

#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(MyMath
#   REQUIRED_VARS MyMath_LIBRARY MyMath_INCLUDE_DIR
#)