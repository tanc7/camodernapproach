cmake_minimum_required(VERSION 3.24)
project(ch19stackADT C)

set(CMAKE_C_STANDARD 11)

add_executable(ch19stackADT main.c stackADT.h stackclient.c stackADT.c)
