cmake_minimum_required(VERSION 3.27)
project(Lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1 main.c
        struct.h
        functions.c
        functions.h
        exercises.c
        exercises.h
)
