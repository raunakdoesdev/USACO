cmake_minimum_required(VERSION 3.5)
project(spin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES spin.cpp)
add_executable(spin ${SOURCE_FILES})
