# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/kona/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kona/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kona/CLionProjects/lem_in_g

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kona/CLionProjects/lem_in_g/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_in.dir/flags.make

CMakeFiles/lem_in.dir/main.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_in.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/main.c.o   -c /home/kona/CLionProjects/lem_in_g/main.c

CMakeFiles/lem_in.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/main.c > CMakeFiles/lem_in.dir/main.c.i

CMakeFiles/lem_in.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/main.c -o CMakeFiles/lem_in.dir/main.c.s

CMakeFiles/lem_in.dir/solver.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/solver.c.o: ../solver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem_in.dir/solver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/solver.c.o   -c /home/kona/CLionProjects/lem_in_g/solver.c

CMakeFiles/lem_in.dir/solver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/solver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/solver.c > CMakeFiles/lem_in.dir/solver.c.i

CMakeFiles/lem_in.dir/solver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/solver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/solver.c -o CMakeFiles/lem_in.dir/solver.c.s

CMakeFiles/lem_in.dir/man_err.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/man_err.c.o: ../man_err.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem_in.dir/man_err.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/man_err.c.o   -c /home/kona/CLionProjects/lem_in_g/man_err.c

CMakeFiles/lem_in.dir/man_err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/man_err.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/man_err.c > CMakeFiles/lem_in.dir/man_err.c.i

CMakeFiles/lem_in.dir/man_err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/man_err.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/man_err.c -o CMakeFiles/lem_in.dir/man_err.c.s

CMakeFiles/lem_in.dir/deque.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/deque.c.o: ../deque.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem_in.dir/deque.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/deque.c.o   -c /home/kona/CLionProjects/lem_in_g/deque.c

CMakeFiles/lem_in.dir/deque.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/deque.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/deque.c > CMakeFiles/lem_in.dir/deque.c.i

CMakeFiles/lem_in.dir/deque.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/deque.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/deque.c -o CMakeFiles/lem_in.dir/deque.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o: ../binary_heap/srcs/binary_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/binary_init.c

CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/binary_init.c > CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/binary_init.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.s

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o: ../fibonacci_heap/srcs/fib_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o   -c /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_init.c

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_init.c > CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.i

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_init.c -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o: ../binary_heap/srcs/bin_free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_free.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_free.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_free.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o: ../binary_heap/srcs/bin_swap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_swap.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_swap.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_swap.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o: ../binary_heap/srcs/bin_get_root.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_get_root.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_get_root.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_get_root.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o: ../binary_heap/srcs/bin_insert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_insert.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_insert.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_insert.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o: ../binary_heap/srcs/bin_remove_root.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_remove_root.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_remove_root.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_remove_root.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.s

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o: ../binary_heap/srcs/bin_inc_key.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o   -c /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_inc_key.c

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_inc_key.c > CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.i

CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/binary_heap/srcs/bin_inc_key.c -o CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.s

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o: ../fibonacci_heap/srcs/fib_create_node.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o   -c /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_create_node.c

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_create_node.c > CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.i

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_create_node.c -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.s

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o: ../fibonacci_heap/srcs/fib_insert_node.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o   -c /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_insert_node.c

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_insert_node.c > CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.i

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_insert_node.c -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.s

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o: ../fibonacci_heap/srcs/fib_heap_union.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o   -c /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_heap_union.c

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_heap_union.c > CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.i

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_heap_union.c -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.s

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o: ../fibonacci_heap/srcs/fib_remove_min.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o   -c /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_remove_min.c

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_remove_min.c > CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.i

CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/fibonacci_heap/srcs/fib_remove_min.c -o CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.s

CMakeFiles/lem_in.dir/dijkstra.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/dijkstra.c.o: ../dijkstra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/lem_in.dir/dijkstra.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/dijkstra.c.o   -c /home/kona/CLionProjects/lem_in_g/dijkstra.c

CMakeFiles/lem_in.dir/dijkstra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/dijkstra.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/CLionProjects/lem_in_g/dijkstra.c > CMakeFiles/lem_in.dir/dijkstra.c.i

CMakeFiles/lem_in.dir/dijkstra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/dijkstra.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/CLionProjects/lem_in_g/dijkstra.c -o CMakeFiles/lem_in.dir/dijkstra.c.s

# Object files for target lem_in
lem_in_OBJECTS = \
"CMakeFiles/lem_in.dir/main.c.o" \
"CMakeFiles/lem_in.dir/solver.c.o" \
"CMakeFiles/lem_in.dir/man_err.c.o" \
"CMakeFiles/lem_in.dir/deque.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o" \
"CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o" \
"CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o" \
"CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o" \
"CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o" \
"CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o" \
"CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o" \
"CMakeFiles/lem_in.dir/dijkstra.c.o"

# External object files for target lem_in
lem_in_EXTERNAL_OBJECTS =

lem_in: CMakeFiles/lem_in.dir/main.c.o
lem_in: CMakeFiles/lem_in.dir/solver.c.o
lem_in: CMakeFiles/lem_in.dir/man_err.c.o
lem_in: CMakeFiles/lem_in.dir/deque.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/binary_init.c.o
lem_in: CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_init.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_free.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_swap.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_get_root.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_insert.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_remove_root.c.o
lem_in: CMakeFiles/lem_in.dir/binary_heap/srcs/bin_inc_key.c.o
lem_in: CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_create_node.c.o
lem_in: CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_insert_node.c.o
lem_in: CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_heap_union.c.o
lem_in: CMakeFiles/lem_in.dir/fibonacci_heap/srcs/fib_remove_min.c.o
lem_in: CMakeFiles/lem_in.dir/dijkstra.c.o
lem_in: CMakeFiles/lem_in.dir/build.make
lem_in: CMakeFiles/lem_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C executable lem_in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_in.dir/build: lem_in

.PHONY : CMakeFiles/lem_in.dir/build

CMakeFiles/lem_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_in.dir/clean

CMakeFiles/lem_in.dir/depend:
	cd /home/kona/CLionProjects/lem_in_g/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kona/CLionProjects/lem_in_g /home/kona/CLionProjects/lem_in_g /home/kona/CLionProjects/lem_in_g/cmake-build-debug /home/kona/CLionProjects/lem_in_g/cmake-build-debug /home/kona/CLionProjects/lem_in_g/cmake-build-debug/CMakeFiles/lem_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_in.dir/depend

