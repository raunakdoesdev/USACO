cmake_minimum_required(VERSION 3.5)
project(msquare)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES msquare.cpp)
add_executable(msquare ${SOURCE_FILES})
