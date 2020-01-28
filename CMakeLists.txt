cmake_minimum_required(VERSION 3.10)
project(GTest_Workshop)

set(CMAKE_CXX_STANDARD 17)

include(build/conanbuildinfo.cmake)
conan_basic_setup()
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE CATS_AND_MICE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/cats_and_mice/*.cpp)
add_library(cats_and_mice ${CATS_AND_MICE_SRC})
target_include_directories(cats_and_mice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cats_and_mice/src)

file(GLOB_RECURSE POSITION_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/position/*.cpp)
add_library(position ${POSITION_SRC})
target_include_directories(position PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/position)

file(GLOB_RECURSE MUX_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/mux/*.cpp)
add_library(mux ${MUX_SRC})
target_include_directories(mux PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/mux)

add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(app cats_and_mice position mux)

file(GLOB_RECURSE APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${APP_TEST_SRC})
target_link_libraries(tests cats_and_mice position mux)
target_link_libraries(tests ${CONAN_LIBS})
