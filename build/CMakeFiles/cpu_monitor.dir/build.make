# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhiming/CLionProjects/ebpf-monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiming/CLionProjects/ebpf-monitor/build

# Include any dependencies generated for this target.
include CMakeFiles/cpu_monitor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpu_monitor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpu_monitor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpu_monitor.dir/flags.make

CMakeFiles/cpu_monitor.dir/src/main.c.o: CMakeFiles/cpu_monitor.dir/flags.make
CMakeFiles/cpu_monitor.dir/src/main.c.o: /home/zhiming/CLionProjects/ebpf-monitor/src/main.c
CMakeFiles/cpu_monitor.dir/src/main.c.o: CMakeFiles/cpu_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cpu_monitor.dir/src/main.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpu_monitor.dir/src/main.c.o -MF CMakeFiles/cpu_monitor.dir/src/main.c.o.d -o CMakeFiles/cpu_monitor.dir/src/main.c.o -c /home/zhiming/CLionProjects/ebpf-monitor/src/main.c

CMakeFiles/cpu_monitor.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpu_monitor.dir/src/main.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhiming/CLionProjects/ebpf-monitor/src/main.c > CMakeFiles/cpu_monitor.dir/src/main.c.i

CMakeFiles/cpu_monitor.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpu_monitor.dir/src/main.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhiming/CLionProjects/ebpf-monitor/src/main.c -o CMakeFiles/cpu_monitor.dir/src/main.c.s

CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o: CMakeFiles/cpu_monitor.dir/flags.make
CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o: /home/zhiming/CLionProjects/ebpf-monitor/src/monitor.bpf.c
CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o: CMakeFiles/cpu_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o -MF CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o.d -o CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o -c /home/zhiming/CLionProjects/ebpf-monitor/src/monitor.bpf.c

CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhiming/CLionProjects/ebpf-monitor/src/monitor.bpf.c > CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.i

CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhiming/CLionProjects/ebpf-monitor/src/monitor.bpf.c -o CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.s

CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o: CMakeFiles/cpu_monitor.dir/flags.make
CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o: /home/zhiming/CLionProjects/ebpf-monitor/src/cpu_calculator.c
CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o: CMakeFiles/cpu_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o -MF CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o.d -o CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o -c /home/zhiming/CLionProjects/ebpf-monitor/src/cpu_calculator.c

CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhiming/CLionProjects/ebpf-monitor/src/cpu_calculator.c > CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.i

CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhiming/CLionProjects/ebpf-monitor/src/cpu_calculator.c -o CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.s

CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o: CMakeFiles/cpu_monitor.dir/flags.make
CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o: /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_config.c
CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o: CMakeFiles/cpu_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o -MF CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o.d -o CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o -c /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_config.c

CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_config.c > CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.i

CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_config.c -o CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.s

CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o: CMakeFiles/cpu_monitor.dir/flags.make
CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o: /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_adjuster.c
CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o: CMakeFiles/cpu_monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o -MF CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o.d -o CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o -c /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_adjuster.c

CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_adjuster.c > CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.i

CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhiming/CLionProjects/ebpf-monitor/src/cgroup_adjuster.c -o CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.s

# Object files for target cpu_monitor
cpu_monitor_OBJECTS = \
"CMakeFiles/cpu_monitor.dir/src/main.c.o" \
"CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o" \
"CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o" \
"CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o" \
"CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o"

# External object files for target cpu_monitor
cpu_monitor_EXTERNAL_OBJECTS =

cpu_monitor: CMakeFiles/cpu_monitor.dir/src/main.c.o
cpu_monitor: CMakeFiles/cpu_monitor.dir/src/monitor.bpf.c.o
cpu_monitor: CMakeFiles/cpu_monitor.dir/src/cpu_calculator.c.o
cpu_monitor: CMakeFiles/cpu_monitor.dir/src/cgroup_config.c.o
cpu_monitor: CMakeFiles/cpu_monitor.dir/src/cgroup_adjuster.c.o
cpu_monitor: CMakeFiles/cpu_monitor.dir/build.make
cpu_monitor: CMakeFiles/cpu_monitor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable cpu_monitor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpu_monitor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpu_monitor.dir/build: cpu_monitor
.PHONY : CMakeFiles/cpu_monitor.dir/build

CMakeFiles/cpu_monitor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpu_monitor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpu_monitor.dir/clean

CMakeFiles/cpu_monitor.dir/depend:
	cd /home/zhiming/CLionProjects/ebpf-monitor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiming/CLionProjects/ebpf-monitor /home/zhiming/CLionProjects/ebpf-monitor /home/zhiming/CLionProjects/ebpf-monitor/build /home/zhiming/CLionProjects/ebpf-monitor/build /home/zhiming/CLionProjects/ebpf-monitor/build/CMakeFiles/cpu_monitor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cpu_monitor.dir/depend

