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
CMAKE_COMMAND = /home/kona/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kona/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6494.38/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kona/Progs/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kona/Progs/lem_in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_in.dir/flags.make

CMakeFiles/lem_in.dir/srcs/main.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_in.dir/srcs/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/main.c.o   -c /home/kona/Progs/lem_in/srcs/main.c

CMakeFiles/lem_in.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/main.c > CMakeFiles/lem_in.dir/srcs/main.c.i

CMakeFiles/lem_in.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/main.c -o CMakeFiles/lem_in.dir/srcs/main.c.s

CMakeFiles/lem_in.dir/srcs/man_err.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/man_err.c.o: ../srcs/man_err.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem_in.dir/srcs/man_err.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/man_err.c.o   -c /home/kona/Progs/lem_in/srcs/man_err.c

CMakeFiles/lem_in.dir/srcs/man_err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/man_err.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/man_err.c > CMakeFiles/lem_in.dir/srcs/man_err.c.i

CMakeFiles/lem_in.dir/srcs/man_err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/man_err.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/man_err.c -o CMakeFiles/lem_in.dir/srcs/man_err.c.s

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o: ../libft/srcs/3_dstr/srcs/dstr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o   -c /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr.c

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr.c > CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.i

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr.c -o CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.s

CMakeFiles/lem_in.dir/srcs/parse_map.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_map.c.o: ../srcs/parse_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem_in.dir/srcs/parse_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_map.c.o   -c /home/kona/Progs/lem_in/srcs/parse_map.c

CMakeFiles/lem_in.dir/srcs/parse_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_map.c > CMakeFiles/lem_in.dir/srcs/parse_map.c.i

CMakeFiles/lem_in.dir/srcs/parse_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_map.c -o CMakeFiles/lem_in.dir/srcs/parse_map.c.s

CMakeFiles/lem_in.dir/srcs/parse_room.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_room.c.o: ../srcs/parse_room.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lem_in.dir/srcs/parse_room.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_room.c.o   -c /home/kona/Progs/lem_in/srcs/parse_room.c

CMakeFiles/lem_in.dir/srcs/parse_room.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_room.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_room.c > CMakeFiles/lem_in.dir/srcs/parse_room.c.i

CMakeFiles/lem_in.dir/srcs/parse_room.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_room.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_room.c -o CMakeFiles/lem_in.dir/srcs/parse_room.c.s

CMakeFiles/lem_in.dir/srcs/parse_utils.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_utils.c.o: ../srcs/parse_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lem_in.dir/srcs/parse_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_utils.c.o   -c /home/kona/Progs/lem_in/srcs/parse_utils.c

CMakeFiles/lem_in.dir/srcs/parse_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_utils.c > CMakeFiles/lem_in.dir/srcs/parse_utils.c.i

CMakeFiles/lem_in.dir/srcs/parse_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_utils.c -o CMakeFiles/lem_in.dir/srcs/parse_utils.c.s

CMakeFiles/lem_in.dir/srcs/parse_links.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_links.c.o: ../srcs/parse_links.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lem_in.dir/srcs/parse_links.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_links.c.o   -c /home/kona/Progs/lem_in/srcs/parse_links.c

CMakeFiles/lem_in.dir/srcs/parse_links.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_links.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_links.c > CMakeFiles/lem_in.dir/srcs/parse_links.c.i

CMakeFiles/lem_in.dir/srcs/parse_links.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_links.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_links.c -o CMakeFiles/lem_in.dir/srcs/parse_links.c.s

CMakeFiles/lem_in.dir/srcs/parse_hash.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_hash.c.o: ../srcs/parse_hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lem_in.dir/srcs/parse_hash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_hash.c.o   -c /home/kona/Progs/lem_in/srcs/parse_hash.c

CMakeFiles/lem_in.dir/srcs/parse_hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_hash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_hash.c > CMakeFiles/lem_in.dir/srcs/parse_hash.c.i

CMakeFiles/lem_in.dir/srcs/parse_hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_hash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_hash.c -o CMakeFiles/lem_in.dir/srcs/parse_hash.c.s

CMakeFiles/lem_in.dir/srcs/parse_room2.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/parse_room2.c.o: ../srcs/parse_room2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/lem_in.dir/srcs/parse_room2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/parse_room2.c.o   -c /home/kona/Progs/lem_in/srcs/parse_room2.c

CMakeFiles/lem_in.dir/srcs/parse_room2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/parse_room2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/parse_room2.c > CMakeFiles/lem_in.dir/srcs/parse_room2.c.i

CMakeFiles/lem_in.dir/srcs/parse_room2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/parse_room2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/parse_room2.c -o CMakeFiles/lem_in.dir/srcs/parse_room2.c.s

CMakeFiles/lem_in.dir/srcs/solver.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver.c.o: ../srcs/solver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/lem_in.dir/srcs/solver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver.c.o   -c /home/kona/Progs/lem_in/srcs/solver.c

CMakeFiles/lem_in.dir/srcs/solver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver.c > CMakeFiles/lem_in.dir/srcs/solver.c.i

CMakeFiles/lem_in.dir/srcs/solver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver.c -o CMakeFiles/lem_in.dir/srcs/solver.c.s

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o: ../srcs/solver_bellman_ford_start_end.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o   -c /home/kona/Progs/lem_in/srcs/solver_bellman_ford_start_end.c

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_bellman_ford_start_end.c > CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.i

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_bellman_ford_start_end.c -o CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.s

CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o: ../srcs/solver_algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o   -c /home/kona/Progs/lem_in/srcs/solver_algorithm.c

CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_algorithm.c > CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.i

CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_algorithm.c -o CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.s

CMakeFiles/lem_in.dir/srcs/writer_main.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/writer_main.c.o: ../srcs/writer_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/lem_in.dir/srcs/writer_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/writer_main.c.o   -c /home/kona/Progs/lem_in/srcs/writer_main.c

CMakeFiles/lem_in.dir/srcs/writer_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/writer_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/writer_main.c > CMakeFiles/lem_in.dir/srcs/writer_main.c.i

CMakeFiles/lem_in.dir/srcs/writer_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/writer_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/writer_main.c -o CMakeFiles/lem_in.dir/srcs/writer_main.c.s

CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o: ../srcs/solver_find_best_current_way.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o   -c /home/kona/Progs/lem_in/srcs/solver_find_best_current_way.c

CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_find_best_current_way.c > CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.i

CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_find_best_current_way.c -o CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.s

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o: ../srcs/solver_bellman_ford_end_start.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o   -c /home/kona/Progs/lem_in/srcs/solver_bellman_ford_end_start.c

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_bellman_ford_end_start.c > CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.i

CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_bellman_ford_end_start.c -o CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.s

CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o: ../srcs/solver_bf_es_find_way.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o   -c /home/kona/Progs/lem_in/srcs/solver_bf_es_find_way.c

CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_bf_es_find_way.c > CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.i

CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_bf_es_find_way.c -o CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.s

CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o: ../srcs/solver_bf_find_way.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o   -c /home/kona/Progs/lem_in/srcs/solver_bf_find_way.c

CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_bf_find_way.c > CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.i

CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_bf_find_way.c -o CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.s

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o: ../srcs/solver_auxiliary_works_algo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o   -c /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo.c

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo.c > CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.i

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo.c -o CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.s

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o: ../srcs/solver_auxiliary_works_algo_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o   -c /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo_2.c

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo_2.c > CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.i

CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_auxiliary_works_algo_2.c -o CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.s

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o: ../srcs/solver_sufficienty_c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o   -c /home/kona/Progs/lem_in/srcs/solver_sufficienty_c.c

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_sufficienty_c.c > CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.i

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_sufficienty_c.c -o CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.s

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o: ../srcs/solver_sufficienty_c_common_rooms_calc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o   -c /home/kona/Progs/lem_in/srcs/solver_sufficienty_c_common_rooms_calc.c

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_sufficienty_c_common_rooms_calc.c > CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.i

CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_sufficienty_c_common_rooms_calc.c -o CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.s

CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o: ../srcs/solver_algo_separation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o   -c /home/kona/Progs/lem_in/srcs/solver_algo_separation.c

CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_algo_separation.c > CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.i

CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_algo_separation.c -o CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.s

CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o: ../srcs/solver_find_way.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building C object CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o   -c /home/kona/Progs/lem_in/srcs/solver_find_way.c

CMakeFiles/lem_in.dir/srcs/solver_find_way.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_find_way.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_find_way.c > CMakeFiles/lem_in.dir/srcs/solver_find_way.c.i

CMakeFiles/lem_in.dir/srcs/solver_find_way.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_find_way.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_find_way.c -o CMakeFiles/lem_in.dir/srcs/solver_find_way.c.s

CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o: ../srcs/solver_initialization.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Building C object CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o   -c /home/kona/Progs/lem_in/srcs/solver_initialization.c

CMakeFiles/lem_in.dir/srcs/solver_initialization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/solver_initialization.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/solver_initialization.c > CMakeFiles/lem_in.dir/srcs/solver_initialization.c.i

CMakeFiles/lem_in.dir/srcs/solver_initialization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/solver_initialization.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/solver_initialization.c -o CMakeFiles/lem_in.dir/srcs/solver_initialization.c.s

CMakeFiles/lem_in.dir/srcs/writer_main2.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/srcs/writer_main2.c.o: ../srcs/writer_main2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_25) "Building C object CMakeFiles/lem_in.dir/srcs/writer_main2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/srcs/writer_main2.c.o   -c /home/kona/Progs/lem_in/srcs/writer_main2.c

CMakeFiles/lem_in.dir/srcs/writer_main2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/srcs/writer_main2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/srcs/writer_main2.c > CMakeFiles/lem_in.dir/srcs/writer_main2.c.i

CMakeFiles/lem_in.dir/srcs/writer_main2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/srcs/writer_main2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/srcs/writer_main2.c -o CMakeFiles/lem_in.dir/srcs/writer_main2.c.s

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o: ../libft/srcs/3_dstr/srcs/dstr2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_26) "Building C object CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o   -c /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr2.c

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr2.c > CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.i

CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kona/Progs/lem_in/libft/srcs/3_dstr/srcs/dstr2.c -o CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.s

# Object files for target lem_in
lem_in_OBJECTS = \
"CMakeFiles/lem_in.dir/srcs/main.c.o" \
"CMakeFiles/lem_in.dir/srcs/man_err.c.o" \
"CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_map.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_room.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_utils.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_links.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_hash.c.o" \
"CMakeFiles/lem_in.dir/srcs/parse_room2.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o" \
"CMakeFiles/lem_in.dir/srcs/writer_main.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o" \
"CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o" \
"CMakeFiles/lem_in.dir/srcs/writer_main2.c.o" \
"CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o"

# External object files for target lem_in
lem_in_EXTERNAL_OBJECTS =

lem_in: CMakeFiles/lem_in.dir/srcs/main.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/man_err.c.o
lem_in: CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_map.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_room.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_utils.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_links.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_hash.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/parse_room2.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_start_end.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_algorithm.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/writer_main.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_find_best_current_way.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_bellman_ford_end_start.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_bf_es_find_way.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_bf_find_way.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_auxiliary_works_algo_2.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_sufficienty_c_common_rooms_calc.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_algo_separation.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_find_way.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/solver_initialization.c.o
lem_in: CMakeFiles/lem_in.dir/srcs/writer_main2.c.o
lem_in: CMakeFiles/lem_in.dir/libft/srcs/3_dstr/srcs/dstr2.c.o
lem_in: CMakeFiles/lem_in.dir/build.make
lem_in: ../libft/libft.a
lem_in: CMakeFiles/lem_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_27) "Linking C executable lem_in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_in.dir/build: lem_in

.PHONY : CMakeFiles/lem_in.dir/build

CMakeFiles/lem_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_in.dir/clean

CMakeFiles/lem_in.dir/depend:
	cd /home/kona/Progs/lem_in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kona/Progs/lem_in /home/kona/Progs/lem_in /home/kona/Progs/lem_in/cmake-build-debug /home/kona/Progs/lem_in/cmake-build-debug /home/kona/Progs/lem_in/cmake-build-debug/CMakeFiles/lem_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_in.dir/depend

