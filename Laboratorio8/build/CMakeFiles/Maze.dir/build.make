# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build

# Include any dependencies generated for this target.
include CMakeFiles/Maze.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Maze.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Maze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Maze.dir/flags.make

CMakeFiles/Maze.dir/codegen:
.PHONY : CMakeFiles/Maze.dir/codegen

CMakeFiles/Maze.dir/src/Maze.cpp.o: CMakeFiles/Maze.dir/flags.make
CMakeFiles/Maze.dir/src/Maze.cpp.o: /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/src/Maze.cpp
CMakeFiles/Maze.dir/src/Maze.cpp.o: CMakeFiles/Maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Maze.dir/src/Maze.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Maze.dir/src/Maze.cpp.o -MF CMakeFiles/Maze.dir/src/Maze.cpp.o.d -o CMakeFiles/Maze.dir/src/Maze.cpp.o -c /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/src/Maze.cpp

CMakeFiles/Maze.dir/src/Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Maze.dir/src/Maze.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/src/Maze.cpp > CMakeFiles/Maze.dir/src/Maze.cpp.i

CMakeFiles/Maze.dir/src/Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Maze.dir/src/Maze.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/src/Maze.cpp -o CMakeFiles/Maze.dir/src/Maze.cpp.s

# Object files for target Maze
Maze_OBJECTS = \
"CMakeFiles/Maze.dir/src/Maze.cpp.o"

# External object files for target Maze
Maze_EXTERNAL_OBJECTS =

libMaze.a: CMakeFiles/Maze.dir/src/Maze.cpp.o
libMaze.a: CMakeFiles/Maze.dir/build.make
libMaze.a: CMakeFiles/Maze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMaze.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Maze.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Maze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Maze.dir/build: libMaze.a
.PHONY : CMakeFiles/Maze.dir/build

CMakeFiles/Maze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Maze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Maze.dir/clean

CMakeFiles/Maze.dir/depend:
	cd /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8 /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8 /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build /Users/mattia/Documents/GitHub/EserciziCpp/Laboratorio8/build/CMakeFiles/Maze.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Maze.dir/depend

