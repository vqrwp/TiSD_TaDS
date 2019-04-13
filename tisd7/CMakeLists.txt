cmake_minimum_required(VERSION 3.10)
project(tisd7 C)

set(CMAKE_C_STANDARD 99)

add_executable(tisd7 main.c time_search.c time_search.h gvedit.c gvedit.h
        scan_int.c scan_int.h mtr_funcs.c mtr_funcs.h)