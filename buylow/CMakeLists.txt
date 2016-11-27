cmake_minimum_required(VERSION 3.5)
project(buylow)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES buylow.cpp)
add_executable(buylow ${SOURCE_FILES})
