cmake_minimum_required(VERSION 3.22.1)
project(lab1)

# interesting fact - if you would set cxx standard below some other props,
# it`s a great possibility that you wouldn`t have some latest std features
# (like i coldn`t use std::ranges, but there was present header of it)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.inl
)

# Collect all source files
file(GLOB_RECURSE COMPILATION_UNITS_TMP CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c++
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
)

# Filter out the test files
set(COMPILATION_UNITS "")
foreach(file ${COMPILATION_UNITS_TMP})
    if (NOT file MATCHES "(_test|main)\\.(cpp|c\\+\\+|cc)$")
        list(APPEND COMPILATION_UNITS ${file})
    endif()
endforeach()

file(GLOB_RECURSE TESTS CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.c++
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*_test.cс
)

add_executable(lab1 src/main.cpp ${COMPILATION_UNITS} ${HEADERS})

set(GTESTLIBS GTest::gtest_main GTest::GTest GTest::Main)
find_package(GTest REQUIRED)

enable_testing()
add_executable(tests-all ${TESTS} ${HEADERS} ${COMPILATION_UNITS} )

target_link_libraries(tests-all ${GTESTLIBS})

include(GoogleTest)
gtest_discover_tests(tests-all)

# Add post-build command to copy the file
add_custom_command(
        TARGET lab1 tests-all
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/rsc"
        "$<TARGET_FILE_DIR:lab1>/rsc"
)