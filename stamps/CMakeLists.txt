cmake_minimum_required(VERSION 3.5)
project(USACO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES stamps.cpp)
add_executable(USACO ${SOURCE_FILES})
