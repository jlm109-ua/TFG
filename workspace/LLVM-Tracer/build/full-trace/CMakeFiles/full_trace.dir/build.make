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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/LLVM-Tracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/LLVM-Tracer/build

# Include any dependencies generated for this target.
include full-trace/CMakeFiles/full_trace.dir/depend.make

# Include the progress variables for this target.
include full-trace/CMakeFiles/full_trace.dir/progress.make

# Include the compile flags for this target's objects.
include full-trace/CMakeFiles/full_trace.dir/flags.make

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o: full-trace/CMakeFiles/full_trace.dir/flags.make
full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o: ../full-trace/full_trace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/LLVM-Tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o"
	cd /workspace/LLVM-Tracer/build/full-trace && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/full_trace.dir/full_trace.cpp.o -c /workspace/LLVM-Tracer/full-trace/full_trace.cpp

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/full_trace.dir/full_trace.cpp.i"
	cd /workspace/LLVM-Tracer/build/full-trace && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/LLVM-Tracer/full-trace/full_trace.cpp > CMakeFiles/full_trace.dir/full_trace.cpp.i

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/full_trace.dir/full_trace.cpp.s"
	cd /workspace/LLVM-Tracer/build/full-trace && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/LLVM-Tracer/full-trace/full_trace.cpp -o CMakeFiles/full_trace.dir/full_trace.cpp.s

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.requires:

.PHONY : full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.requires

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.provides: full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.requires
	$(MAKE) -f full-trace/CMakeFiles/full_trace.dir/build.make full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.provides.build
.PHONY : full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.provides

full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.provides.build: full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o


# Object files for target full_trace
full_trace_OBJECTS = \
"CMakeFiles/full_trace.dir/full_trace.cpp.o"

# External object files for target full_trace
full_trace_EXTERNAL_OBJECTS =

full-trace/full_trace.so: full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o
full-trace/full_trace.so: full-trace/CMakeFiles/full_trace.dir/build.make
full-trace/full_trace.so: full-trace/CMakeFiles/full_trace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/LLVM-Tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library full_trace.so"
	cd /workspace/LLVM-Tracer/build/full-trace && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/full_trace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
full-trace/CMakeFiles/full_trace.dir/build: full-trace/full_trace.so

.PHONY : full-trace/CMakeFiles/full_trace.dir/build

full-trace/CMakeFiles/full_trace.dir/requires: full-trace/CMakeFiles/full_trace.dir/full_trace.cpp.o.requires

.PHONY : full-trace/CMakeFiles/full_trace.dir/requires

full-trace/CMakeFiles/full_trace.dir/clean:
	cd /workspace/LLVM-Tracer/build/full-trace && $(CMAKE_COMMAND) -P CMakeFiles/full_trace.dir/cmake_clean.cmake
.PHONY : full-trace/CMakeFiles/full_trace.dir/clean

full-trace/CMakeFiles/full_trace.dir/depend:
	cd /workspace/LLVM-Tracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/LLVM-Tracer /workspace/LLVM-Tracer/full-trace /workspace/LLVM-Tracer/build /workspace/LLVM-Tracer/build/full-trace /workspace/LLVM-Tracer/build/full-trace/CMakeFiles/full_trace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : full-trace/CMakeFiles/full_trace.dir/depend
