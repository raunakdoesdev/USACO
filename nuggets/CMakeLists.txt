cmake_minimum_required(VERSION 3.5)
project(nuggets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES nuggets.cpp)
add_executable(nuggets ${SOURCE_FILES})
