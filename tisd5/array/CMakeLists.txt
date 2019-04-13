cmake_minimum_required(VERSION 3.10)
project(array C)

set(CMAKE_C_STANDARD 99)

add_executable(array main.c init_automat.c init_automat.h queue.c queue.h time.c time.h constants.h structs.h refresh_automat.c refresh_automat.h rand.c rand.h)

add_executable(arraytest init_automat.c init_automat.h queue.c queue.h time.c time.h test.c)