cmake_minimum_required(VERSION 3.5)
project(lgame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES lgame.cpp)
add_executable(lgame ${SOURCE_FILES})
