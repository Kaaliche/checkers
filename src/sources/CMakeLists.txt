cmake_minimum_required(VERSION 3.10)
project(checkers)

set(CMAKE_C_STANDARD 99)

add_executable(checkers boardgame.c main.c ../headers/boardgame.h)