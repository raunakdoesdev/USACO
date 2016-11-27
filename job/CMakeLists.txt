cmake_minimum_required(VERSION 3.5)
project(job)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES job.cpp)
add_executable(job ${SOURCE_FILES})
