cmake_minimum_required(VERSION 3.5)
project(camelot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES camelot.cpp)
add_executable(camelot ${SOURCE_FILES})
