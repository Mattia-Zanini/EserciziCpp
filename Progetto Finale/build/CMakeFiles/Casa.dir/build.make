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
CMAKE_SOURCE_DIR = "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build"

# Include any dependencies generated for this target.
include CMakeFiles/Casa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Casa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Casa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Casa.dir/flags.make

CMakeFiles/Casa.dir/codegen:
.PHONY : CMakeFiles/Casa.dir/codegen

CMakeFiles/Casa.dir/src/Casa.cpp.o: CMakeFiles/Casa.dir/flags.make
CMakeFiles/Casa.dir/src/Casa.cpp.o: /Users/mattia/Documents/GitHub/EserciziCpp/Progetto\ Finale/src/Casa.cpp
CMakeFiles/Casa.dir/src/Casa.cpp.o: CMakeFiles/Casa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Casa.dir/src/Casa.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Casa.dir/src/Casa.cpp.o -MF CMakeFiles/Casa.dir/src/Casa.cpp.o.d -o CMakeFiles/Casa.dir/src/Casa.cpp.o -c "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/src/Casa.cpp"

CMakeFiles/Casa.dir/src/Casa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Casa.dir/src/Casa.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/src/Casa.cpp" > CMakeFiles/Casa.dir/src/Casa.cpp.i

CMakeFiles/Casa.dir/src/Casa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Casa.dir/src/Casa.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/src/Casa.cpp" -o CMakeFiles/Casa.dir/src/Casa.cpp.s

# Object files for target Casa
Casa_OBJECTS = \
"CMakeFiles/Casa.dir/src/Casa.cpp.o"

# External object files for target Casa
Casa_EXTERNAL_OBJECTS =

libCasa.a: CMakeFiles/Casa.dir/src/Casa.cpp.o
libCasa.a: CMakeFiles/Casa.dir/build.make
libCasa.a: CMakeFiles/Casa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCasa.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Casa.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Casa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Casa.dir/build: libCasa.a
.PHONY : CMakeFiles/Casa.dir/build

CMakeFiles/Casa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Casa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Casa.dir/clean

CMakeFiles/Casa.dir/depend:
	cd "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale" "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale" "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build" "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build" "/Users/mattia/Documents/GitHub/EserciziCpp/Progetto Finale/build/CMakeFiles/Casa.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Casa.dir/depend
