cmake_minimum_required(VERSION 3.13)
project(AisdClient)

add_executable(AisdSearch Search.cpp)
add_executable(AisdSort Sort.cpp)
add_executable(AisdFlags Segregate.cpp)

target_include_directories(AisdSearch PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})
target_include_directories(AisdSort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})
target_include_directories(AisdFlags PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

target_link_libraries(AisdSearch PUBLIC aisdlib)
target_link_libraries(AisdSort PUBLIC aisdlib)
target_link_libraries(AisdFlags PUBLIC aisdlib)