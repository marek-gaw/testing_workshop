cmake_minimum_required(VERSION 3.10)
project(Cats_and_Mice)

set(CMAKE_CXX_STANDARD 17)

include(build/conanbuildinfo.cmake)
conan_basic_setup()
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE CATS_AND_MICE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(cats_and_mice ${CATS_AND_MICE_SRC})
target_include_directories(cats_and_mice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(app cats_and_mice)

file(GLOB_RECURSE APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${APP_TEST_SRC})
target_link_libraries(tests cats_and_mice)
target_link_libraries(tests ${CONAN_LIBS})
