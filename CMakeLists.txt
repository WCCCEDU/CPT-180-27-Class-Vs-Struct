cmake_minimum_required(VERSION 3.4)
project(cookie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cookie.cpp cookie.h)
#add_library(cookie ${SOURCE_FILES})
add_executable(cookie ${SOURCE_FILES})
