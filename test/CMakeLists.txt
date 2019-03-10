project(AisdTest)

enable_testing()

add_subdirectory(googletest)

add_executable(AisdTest )

target_sources(AisdTest PRIVATE
        main.cpp
        StdInc.h
        SortTest.cpp
        SearchTest.cpp
        ContainerTest.cpp
        StackTest.cpp
        QueueTest.cpp
        )

target_include_directories(AisdTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(AisdTest PRIVATE gtest gmock aisdlib)