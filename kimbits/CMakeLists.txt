cmake_minimum_required(VERSION 3.5)
project(fact4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES fact4.cpp)
add_executable(fact4 ${SOURCE_FILES})
