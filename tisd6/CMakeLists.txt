cmake_minimum_required(VERSION 3.10)
project(tisd6 C)

set(CMAKE_C_STANDARD 99)

add_executable(tisd6 main.c tree.c tree.h hash.c hash.h export.c export.h balance.c balance.h
        read_file.c read_file.h search.c search.h efficiency.c efficiency.h)