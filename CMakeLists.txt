cmake_minimum_required(VERSION 3.27)
project(Lab3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab3 main.c
        struct.h
        funcs.c
        funcs.h
        BinaryTree.c
        BinaryTree.h
        Node.c
        Node.h
        Person.c
        Person.h
        includes.h
)
