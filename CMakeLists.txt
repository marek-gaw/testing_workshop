cmake_minimum_required(VERSION 3.10)
project(coding_challenges)

set(CMAKE_CXX_STANDARD 14)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

# https://stackoverflow.com/questions/7724569/debug-vs-release-in-cmake
add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)
#set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE MY_APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(my_app_src ${MY_APP_SRC})
target_include_directories(my_app_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# HackerRank
file(GLOB_RECURSE HACKERRANK_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(hackerrank_src ${HACKERRANK_SRC})
target_include_directories(hackerrank_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(my_app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(my_app hackerrank_src fmt)

file(GLOB_RECURSE MY_APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${MY_APP_TEST_SRC})
target_link_libraries(tests my_app_src)
target_link_libraries(tests hackerrank_src)
target_link_libraries(tests ${CONAN_LIBS})
