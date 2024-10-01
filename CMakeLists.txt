cmake_minimum_required(VERSION 3.30)
project(binarytree C)

set(CMAKE_C_STANDARD 11)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(binarytree main.c binarytree.c avltree.c)
else ()
    add_library(binarytree STATIC binarytree.c avltree.c)
endif ()
