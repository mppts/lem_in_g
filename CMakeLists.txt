cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories( libft/includes includes)

add_executable(lem_in main.c
        includes/lem_in.h
        libft/includes/libft.h solver.c man_err.c deque.c)