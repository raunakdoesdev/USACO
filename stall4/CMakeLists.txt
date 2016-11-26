cmake_minimum_required(VERSION 3.5)
project(stall4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES stall4.cpp)
add_executable(stall4 ${SOURCE_FILES})
