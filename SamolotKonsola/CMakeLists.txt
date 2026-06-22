cmake_minimum_required(VERSION 3.20)
project(SamolotKonsola)

set(CMAKE_CXX_STANDARD 17)


add_executable(SamolotKonsola main.cpp Airplane.cpp ConsoleUI.cpp
        ConsoleUI.cpp
        ConsoleUI.h)