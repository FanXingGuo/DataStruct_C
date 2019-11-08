cmake_minimum_required(VERSION 3.13)
project(dsC C)

set(CMAKE_C_STANDARD 99)

add_executable(dsC main.c stack_num.h stack_char.h expression_calculation.h)