cmake_minimum_required(VERSION 3.5)
project(ditch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES ditch.cpp)
add_executable(ditch ${SOURCE_FILES})
