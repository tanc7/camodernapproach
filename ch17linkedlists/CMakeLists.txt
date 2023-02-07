cmake_minimum_required(VERSION 3.24)
project(ch17linkedlists C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
SET(CMAKE_C_FLAGS_DEBUG "-O0")
add_executable(ch17linkedlists main.c readline.c)
