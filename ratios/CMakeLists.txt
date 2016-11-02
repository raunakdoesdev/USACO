cmake_minimum_required(VERSION 3.5)
project(ratios)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES ratios.cpp)
add_executable(ratios ${SOURCE_FILES})
