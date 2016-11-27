cmake_minimum_required(VERSION 3.5)
project(race3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES race3.cpp)
add_executable(race3 ${SOURCE_FILES})
