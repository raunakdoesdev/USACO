# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sauhaarda/Desktop/USACO/stall4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sauhaarda/Desktop/USACO/stall4

# Include any dependencies generated for this target.
include CMakeFiles/stall4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stall4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stall4.dir/flags.make

CMakeFiles/stall4.dir/stall4.cpp.o: CMakeFiles/stall4.dir/flags.make
CMakeFiles/stall4.dir/stall4.cpp.o: stall4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sauhaarda/Desktop/USACO/stall4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stall4.dir/stall4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stall4.dir/stall4.cpp.o -c /home/sauhaarda/Desktop/USACO/stall4/stall4.cpp

CMakeFiles/stall4.dir/stall4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stall4.dir/stall4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sauhaarda/Desktop/USACO/stall4/stall4.cpp > CMakeFiles/stall4.dir/stall4.cpp.i

CMakeFiles/stall4.dir/stall4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stall4.dir/stall4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sauhaarda/Desktop/USACO/stall4/stall4.cpp -o CMakeFiles/stall4.dir/stall4.cpp.s

CMakeFiles/stall4.dir/stall4.cpp.o.requires:

.PHONY : CMakeFiles/stall4.dir/stall4.cpp.o.requires

CMakeFiles/stall4.dir/stall4.cpp.o.provides: CMakeFiles/stall4.dir/stall4.cpp.o.requires
	$(MAKE) -f CMakeFiles/stall4.dir/build.make CMakeFiles/stall4.dir/stall4.cpp.o.provides.build
.PHONY : CMakeFiles/stall4.dir/stall4.cpp.o.provides

CMakeFiles/stall4.dir/stall4.cpp.o.provides.build: CMakeFiles/stall4.dir/stall4.cpp.o


# Object files for target stall4
stall4_OBJECTS = \
"CMakeFiles/stall4.dir/stall4.cpp.o"

# External object files for target stall4
stall4_EXTERNAL_OBJECTS =

stall4: CMakeFiles/stall4.dir/stall4.cpp.o
stall4: CMakeFiles/stall4.dir/build.make
stall4: CMakeFiles/stall4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sauhaarda/Desktop/USACO/stall4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stall4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stall4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stall4.dir/build: stall4

.PHONY : CMakeFiles/stall4.dir/build

CMakeFiles/stall4.dir/requires: CMakeFiles/stall4.dir/stall4.cpp.o.requires

.PHONY : CMakeFiles/stall4.dir/requires

CMakeFiles/stall4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stall4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stall4.dir/clean

CMakeFiles/stall4.dir/depend:
	cd /home/sauhaarda/Desktop/USACO/stall4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sauhaarda/Desktop/USACO/stall4 /home/sauhaarda/Desktop/USACO/stall4 /home/sauhaarda/Desktop/USACO/stall4 /home/sauhaarda/Desktop/USACO/stall4 /home/sauhaarda/Desktop/USACO/stall4/CMakeFiles/stall4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stall4.dir/depend

