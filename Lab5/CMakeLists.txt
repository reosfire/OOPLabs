cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

file(GLOB libFiles
        "../lib/*.h"
        "../lib/*.cpp")

add_executable(Lab5 main.cpp ${libFiles})