cmake_minimum_required(VERSION 3.13)
project(AisdTest)

add_subdirectory(googletest)

add_executable(AisdTest main.cpp StdInc.h)

target_include_directories(AisdTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(AisdTest PRIVATE gtest gmock)