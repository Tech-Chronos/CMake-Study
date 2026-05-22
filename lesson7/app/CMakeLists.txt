list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

find_package(MyMath REQUIRED)

add_executable(main main.cc)

target_include_directories(main PRIVATE ${MyMath_INCLUDE_DIR})

target_link_libraries(main PRIVATE ${MyMath_LIBRARY})

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin 
                        BUILD_RPATH ${CMAKE_SOURCE_DIR}/my_lib/src)

