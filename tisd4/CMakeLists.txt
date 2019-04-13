cmake_minimum_required(VERSION 3.10)
project(tisd4 C)

set(CMAKE_C_STANDARD 99)

add_executable(tisd4 main.c scanf.c scanf.h structs.h list_funcs.c list_funcs.h arr_funcs.c arr_funcs.h is_pal.c is_pal.h efficience.c efficience.h)