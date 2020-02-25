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
                #srcs/solver.c
                srcs/solver_bfs.c
                #srcs/solver_algorithm.c
                #srcs/solver_dfs.c
                #srcs/writer_main.c
                #srcs/solver_algorithm_cleaning.c
                srcs/solver_ek.c
        srcs/solver_dijkstra.c
        libft/srcs/binary_heap/binary_init.c
        libft/srcs/binary_heap/bin_swap.c
        libft/srcs/binary_heap/bin_remove_root.c
        libft/srcs/binary_heap/bin_free.c
        libft/srcs/binary_heap/bin_insert.c
        libft/srcs/binary_heap/bin_inc_key.c
        libft/srcs/binary_heap/bin_get_root.c
        srcs/solver_tools.c
        srcs/deque2.c
        srcs/deque.c
        srcs/writer_main_new.c
        srcs/solver_ek2.c
        srcs/writer_push_ants.c)

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)

