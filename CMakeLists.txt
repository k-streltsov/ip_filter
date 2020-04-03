cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(ip_filter VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(ip_filter VERSION 1)
ENDIF()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory(test)