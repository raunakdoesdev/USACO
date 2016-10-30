cmake_minimum_required(VERSION 3.5)
project(kimbits)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES kimbits.cpp)
add_executable(kimbits ${SOURCE_FILES})
