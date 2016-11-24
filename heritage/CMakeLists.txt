cmake_minimum_required(VERSION 3.5)
project(heritage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES heritage.cpp)
add_executable(heritage ${SOURCE_FILES})
