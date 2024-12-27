cmake_minimum_required(VERSION 3.28)
project(wet)

set(CMAKE_CXX_STANDARD 17)

add_executable(wet
        OurMain.cpp
        Utilities.h
        Utilities.cpp
        Matrix.h
        Matrix.cpp
        MataMvidia.h
        MataMvidia.cpp)
