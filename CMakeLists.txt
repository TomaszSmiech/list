cmake_minimum_required(VERSION 3.10)
project(list)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE LIST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(list_src ${LIST_SRC})
target_include_directories(list_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(list ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(list list_src)

file(GLOB_RECURSE LIST_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${LIST_TEST_SRC})

target_link_libraries(tests list_src)
target_link_libraries(tests ${CONAN_LIBS})
