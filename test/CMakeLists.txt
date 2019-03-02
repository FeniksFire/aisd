project(AisdTest)

enable_testing()

add_subdirectory(googletest)

add_executable(AisdTest main.cpp StdInc.h SortTest.cpp SearchTest.cpp ContainerTest.cpp)

target_include_directories(AisdTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(AisdTest PRIVATE gtest gmock aisdlib)