cmake_minimum_required(VERSION 3.15)
project(labyrinth_client C)


set(CMAKE_C_STANDARD 90 )

SET(CMAKE_C_FLAGS -pthread)

set(CMAKE_C_FLAGS -lncurses)


add_executable(labyrinth_client main.c constants.h drawing.c )
