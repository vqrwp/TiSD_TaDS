cmake_minimum_required(VERSION 3.10)
project(list C)

set(CMAKE_C_STANDARD 99)

add_executable(list main.c init_automat.c init_automat.h queue.c queue.h time.c time.h rand.c rand.h refresh_automat.c
        refresh_automat.h structs.h constants.h)

add_executable(listtest init_automat.c init_automat.h queue.c queue.h time.c time.h test.c refresh_automat.c refresh_automat.h
        structs.h constants.h rand.c rand.h)