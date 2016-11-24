cmake_minimum_required(VERSION 3.5)
project(fence9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES fence9.cpp)
add_executable(fence9 ${SOURCE_FILES})
