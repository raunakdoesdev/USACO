cmake_minimum_required(VERSION 3.5)
project(milk6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES milk6.cpp)
add_executable(milk6 ${SOURCE_FILES})
