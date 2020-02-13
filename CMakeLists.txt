cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories( libft/includes includes libbinheap libbinheap/includes fibonacci_heap fibonacci_heap/includes)

add_executable(lem_in
                srcs/main.c
                includes/lem_in.h
                libft/includes/libft.h
                libft/includes/get_next_line.h
                libft/includes/dstr.h
                srcs/man_err.c
                libft/srcs/dstr/dstr.c
                srcs/parse_map.c
                srcs/parse_room.c
                srcs/parse_utils.c
                srcs/parse_links.c
                srcs/parse_hash.c
                srcs/parse_room2.c
                srcs/solver.c
                srcs/solver_bfs.c
                srcs/solver_algorithm.c
                srcs/solver_dfs.c
                srcs/writer_main.c
                srcs/solver_algorithm_cleaning.c)

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)

