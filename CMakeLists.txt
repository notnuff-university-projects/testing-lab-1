cmake_minimum_required(VERSION 3.22.1)
project(lab1)

# interesting fact - if you would set cxx standard below some other props,
# it`s a great possibility that you wouldn`t have some latest std features
# (like i coldn`t use std::ranges, but there was present header of it)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE COMPILATION_UNITS CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c++
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cс
)

file(GLOB_RECURSE TESTS CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.c++
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.cс
)

set(GTESTLIBS GTest::gtest_main GTest::GTest GTest::Main)
find_package(GTest REQUIRED)

enable_testing()

add_executable(lab1 ${COMPILATION_UNITS})
add_executable(tests-all ${TESTS})
target_link_libraries(lab1 ${GTESTLIBS})
target_link_libraries(tests-all ${GTESTLIBS})

include(GoogleTest)
gtest_discover_tests(lab1)
gtest_discover_tests(tests-all)