cmake_minimum_required(VERSION 3.5)
project(shuttle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES shuttle.cpp)
add_executable(shuttle ${SOURCE_FILES})
