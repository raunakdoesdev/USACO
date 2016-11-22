cmake_minimum_required(VERSION 3.5)
project(shopping)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES shopping.cpp)
add_executable(shopping ${SOURCE_FILES})
