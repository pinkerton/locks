cmake_minimum_required(VERSION 2.8)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
# Tests will currently build by default. Consider changing.
option(test "Build all tests." ON)
enable_testing()

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME mutex)
project(${PROJECT_NAME})

#set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Glob everything except for main.c, which we don't want to link in
# libproject nor the tests (which have their own main()).
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)
list(REMOVE_ITEM SOURCES ${PROJECT_SOURCE_DIR}/src/main.c)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(src)

if (test)
  add_subdirectory(vendor/googletest)
  add_subdirectory(tests)
endif()
