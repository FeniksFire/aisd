add_library(aisdlib "")

target_include_directories(aisdlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(aisdlib PUBLIC
        Container.h
        PatternFinder.h
        Queue.h
        SearchContainer.h
        SortContainer.h
        Stack.h
        )

set_target_properties(aisdlib PROPERTIES LINKER_LANGUAGE CXX)
