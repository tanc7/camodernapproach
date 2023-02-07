cmake_minimum_required(VERSION 3.24)
project(Chapter16Inventory C)

set(CMAKE_C_STANDARD 11)

add_executable(Chapter16Inventory main.c readline.h readline.c)
