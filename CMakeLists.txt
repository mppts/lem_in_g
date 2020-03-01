cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories( libft/includes includes libbinheap libbinheap/includes fibonacci_heap fibonacci_heap/includes)

add_executable(lem_in
                srcs/main.c
                includes/lem_in.h
                libft/includes/libft.h
        libft/srcs/2_get_next_line/includes/get_next_line.h
        libft/srcs/3_dstr/includes/dstr.h
                srcs/man_err.c
        libft/srcs/3_dstr/srcs/dstr.c
                srcs/parse_map.c
                srcs/parse_room.c
                srcs/parse_utils.c
                srcs/parse_links.c
                srcs/parse_hash.c
                srcs/parse_room2.c
                srcs/solver.c
        srcs/solver_bellman_ford_start_end.c
                srcs/solver_algorithm.c
        srcs/writer_main.c
        srcs/solver_find_best_current_way.c srcs/solver_bellman_ford_end_start.c srcs/solver_bf_es_find_way.c srcs/solver_bf_find_way.c srcs/solver_auxiliary_works_algo.c srcs/solver_auxiliary_works_algo_2.c srcs/solver_sufficienty_c.c srcs/solver_sufficienty_c_common_rooms_calc.c srcs/solver_algo_separation.c srcs/solver_find_way.c srcs/solver_initialization.c srcs/writer_main2.c libft/srcs/3_dstr/srcs/dstr2.c)

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)

