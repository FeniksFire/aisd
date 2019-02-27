cmake_minimum_required(VERSION 3.13)
project(Aisd)

add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        ON)

add_executable(AisdSearch LinearAndBinarySearch.cpp main.cpp StdInc.h)
add_executable(AisdSort Sort.cpp)

add_executable(AisdTest main.cpp StdInc.h)

target_include_directories(AisdTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(AisdTest PRIVATE gtest gmock)