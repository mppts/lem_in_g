cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories( libft/includes includes libbinheap libbinheap/includes fibonacci_heap fibonacci_heap/includes)

add_executable(lem_in
                srcs/main.c
                includes/lem_in.h
                libft/includes/libft.h
                #srcs/solver.c
                #srcs/deque.c
                srcs/man_err.c
                #libbinheap/srcs/binary_init.c
                #libbinheap/includes/binary_heap.h
                #fibonacci_heap/includes/fibonacci_heap.h
                #fibonacci_heap/srcs/fib_init.c
                #libbinheap/srcs/bin_free.c
                #libbinheap/srcs/bin_swap.c
                #libbinheap/srcs/bin_get_root.c
                #libbinheap/srcs/bin_insert.c
                #libbinheap/srcs/bin_remove_root.c
                #libbinheap/srcs/bin_inc_key.c
                #fibonacci_heap/srcs/fib_create_node.c
                #fibonacci_heap/srcs/fib_insert_node.c
                #fibonacci_heap/srcs/fib_heap_union.c
                #fibonacci_heap/srcs/fib_remove_min.c
                #srcs/dijkstra.c
                srcs/parse_map.c
                srcs/parse_room.c
                srcs/parse_utils.c
                srcs/parse_links.c
                srcs/parse_hash.c
                srcs/parse_room2.c
                #srcs/solver_bfs.c
        )

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)

