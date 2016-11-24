cmake_minimum_required(VERSION 3.5)
project(fence6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES fence6.cpp)
add_executable(fence6 ${SOURCE_FILES})
