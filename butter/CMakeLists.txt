cmake_minimum_required(VERSION 3.5)
project(butter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES butter.cpp)
add_executable(butter ${SOURCE_FILES})
