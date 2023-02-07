cmake_minimum_required(VERSION 3.24)
project(ch15multiplefileprogram C)

set(CMAKE_C_STANDARD 11)

add_executable(ch15multiplefileprogram word.h line.h justify.c word.c line.c)
