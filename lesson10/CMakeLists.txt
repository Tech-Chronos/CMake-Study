cmake_minimum_required(VERSION 3.18)

project(TestLib LANGUAGES CXX)

include(GNUInstallDirs)

add_subdirectory(my_lib)
add_subdirectory(app)

include(CPack)
set(CPACK_PACKAGE_NAME "MyApp")
set(CPACK_PACKAGE_VERSION "1.1.1")
set(CPACK_GENERATOR "TGZ")

