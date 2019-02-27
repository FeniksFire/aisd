cmake_minimum_required(VERSION 3.13)
project(Aisd VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        ON)

add_executable(AisdSearch LinearAndBinarySearch.cpp)
add_executable(AisdSort Sort.cpp)
