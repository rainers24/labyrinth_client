cmake_minimum_required(VERSION 3.15)
project(labyrinth_server C)


set(CMAKE_C_STANDARD 90 )
SET(CMAKE_C_FLAGS -pthread)

add_executable(labyrinth_client main.c constants.h )