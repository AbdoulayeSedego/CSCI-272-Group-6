cmake_minimum_required(VERSION 4.0)
project(assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(header)

add_executable(assignment_3
        header/Course.h
        header/Student.h
        Course.cpp
        main.cpp
        Student.cpp)
