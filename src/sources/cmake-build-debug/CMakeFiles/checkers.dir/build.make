# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/adr1pet/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/adr1pet/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adr1pet/C_PROJECT/checkers/src/sources

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/checkers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checkers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkers.dir/flags.make

CMakeFiles/checkers.dir/boardgame.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/boardgame.c.o: ../boardgame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/checkers.dir/boardgame.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checkers.dir/boardgame.c.o   -c /home/adr1pet/C_PROJECT/checkers/src/sources/boardgame.c

CMakeFiles/checkers.dir/boardgame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/boardgame.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adr1pet/C_PROJECT/checkers/src/sources/boardgame.c > CMakeFiles/checkers.dir/boardgame.c.i

CMakeFiles/checkers.dir/boardgame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/boardgame.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adr1pet/C_PROJECT/checkers/src/sources/boardgame.c -o CMakeFiles/checkers.dir/boardgame.c.s

CMakeFiles/checkers.dir/boardgame.c.o.requires:

.PHONY : CMakeFiles/checkers.dir/boardgame.c.o.requires

CMakeFiles/checkers.dir/boardgame.c.o.provides: CMakeFiles/checkers.dir/boardgame.c.o.requires
	$(MAKE) -f CMakeFiles/checkers.dir/build.make CMakeFiles/checkers.dir/boardgame.c.o.provides.build
.PHONY : CMakeFiles/checkers.dir/boardgame.c.o.provides

CMakeFiles/checkers.dir/boardgame.c.o.provides.build: CMakeFiles/checkers.dir/boardgame.c.o


CMakeFiles/checkers.dir/main.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/checkers.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checkers.dir/main.c.o   -c /home/adr1pet/C_PROJECT/checkers/src/sources/main.c

CMakeFiles/checkers.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adr1pet/C_PROJECT/checkers/src/sources/main.c > CMakeFiles/checkers.dir/main.c.i

CMakeFiles/checkers.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adr1pet/C_PROJECT/checkers/src/sources/main.c -o CMakeFiles/checkers.dir/main.c.s

CMakeFiles/checkers.dir/main.c.o.requires:

.PHONY : CMakeFiles/checkers.dir/main.c.o.requires

CMakeFiles/checkers.dir/main.c.o.provides: CMakeFiles/checkers.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/checkers.dir/build.make CMakeFiles/checkers.dir/main.c.o.provides.build
.PHONY : CMakeFiles/checkers.dir/main.c.o.provides

CMakeFiles/checkers.dir/main.c.o.provides.build: CMakeFiles/checkers.dir/main.c.o


# Object files for target checkers
checkers_OBJECTS = \
"CMakeFiles/checkers.dir/boardgame.c.o" \
"CMakeFiles/checkers.dir/main.c.o"

# External object files for target checkers
checkers_EXTERNAL_OBJECTS =

checkers: CMakeFiles/checkers.dir/boardgame.c.o
checkers: CMakeFiles/checkers.dir/main.c.o
checkers: CMakeFiles/checkers.dir/build.make
checkers: CMakeFiles/checkers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable checkers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkers.dir/build: checkers

.PHONY : CMakeFiles/checkers.dir/build

CMakeFiles/checkers.dir/requires: CMakeFiles/checkers.dir/boardgame.c.o.requires
CMakeFiles/checkers.dir/requires: CMakeFiles/checkers.dir/main.c.o.requires

.PHONY : CMakeFiles/checkers.dir/requires

CMakeFiles/checkers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkers.dir/clean

CMakeFiles/checkers.dir/depend:
	cd /home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adr1pet/C_PROJECT/checkers/src/sources /home/adr1pet/C_PROJECT/checkers/src/sources /home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug /home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug /home/adr1pet/C_PROJECT/checkers/src/sources/cmake-build-debug/CMakeFiles/checkers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checkers.dir/depend

