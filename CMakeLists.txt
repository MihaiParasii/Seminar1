cmake_minimum_required(VERSION 3.27)
project(Lab5 C)

set(CMAKE_C_STANDARD 23)

add_executable(Lab5 main.c
        funcs.c
        funcs.h
        ex1_private.c
        ex1_private.h
        helpers_funcs.c
        helpers_funcs.h
        ex2_private.c
        ex2_private.h
        ex3_private.c
        ex3_private.h
        struct.h
)
