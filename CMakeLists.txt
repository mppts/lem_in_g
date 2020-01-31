cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

include_directories( libft/includes includes binary_heap binary_heap/includes fibonacci_heap fibonacci_heap/includes)

add_executable(lem_in
        main.c
        includes/lem_in.h
        libft/includes/libft.h
        solver.c
        man_err.c
        deque.c
        binary_heap/srcs/binary_init.c
        binary_heap/includes/binary_heap.h
        fibonacci_heap/includes/fibonacci_heap.h
        fibonacci_heap/srcs/fib_init.c
        binary_heap/srcs/bin_free.c binary_heap/srcs/bin_swap.c binary_heap/srcs/bin_get_root.c binary_heap/srcs/bin_insert.c binary_heap/srcs/bin_remove_root.c binary_heap/srcs/bin_inc_key.c fibonacci_heap/srcs/fib_create_node.c fibonacci_heap/srcs/fib_insert_node.c fibonacci_heap/srcs/fib_heap_union.c fibonacci_heap/srcs/fib_remove_min.c dijkstra.c)