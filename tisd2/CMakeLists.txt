cmake_minimum_required(VERSION 3.10)
project(tisd2 C)

set(CMAKE_C_STANDARD 99)

add_executable(tisd2 main.c add_flat.c structs.h structs.c show.c filling_table.c renew_table.c insert_sort.c
        bubble_sort.c table.h delete.c read_int.h read_int.c)