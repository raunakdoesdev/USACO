cmake_minimum_required(VERSION 3.5)
project(rockers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES rockers.cpp)
add_executable(rockers ${SOURCE_FILES})
