cmake_minimum_required(VERSION 4.1)
project(z_h)

set(CMAKE_CXX_STANDARD 20)

add_executable(z_h main.cpp
        functions.h
        source.cpp)
