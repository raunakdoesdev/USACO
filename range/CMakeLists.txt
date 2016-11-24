cmake_minimum_required(VERSION 3.5)
project(range)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES range.cpp)
add_executable(range ${SOURCE_FILES})
