# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Users/hhismans/.brew/Cellar/cmake/3.9.4_1/bin/cmake

# The command to remove a file.
RM = /Users/hhismans/.brew/Cellar/cmake/3.9.4_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hhismans/work/rubiks/opencv_sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hhismans/work/rubiks/opencv_sandbox

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Users/hhismans/.brew/Cellar/cmake/3.9.4_1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Users/hhismans/.brew/Cellar/cmake/3.9.4_1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/hhismans/work/rubiks/opencv_sandbox/CMakeFiles /Users/hhismans/work/rubiks/opencv_sandbox/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/hhismans/work/rubiks/opencv_sandbox/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DisplayImage

# Build rule for target.
DisplayImage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DisplayImage
.PHONY : DisplayImage

# fast build rule for target.
DisplayImage/fast:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/build
.PHONY : DisplayImage/fast

src/Cube.algo.class.o: src/Cube.algo.class.cpp.o

.PHONY : src/Cube.algo.class.o

# target to build an object file
src/Cube.algo.class.cpp.o:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.algo.class.cpp.o
.PHONY : src/Cube.algo.class.cpp.o

src/Cube.algo.class.i: src/Cube.algo.class.cpp.i

.PHONY : src/Cube.algo.class.i

# target to preprocess a source file
src/Cube.algo.class.cpp.i:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.algo.class.cpp.i
.PHONY : src/Cube.algo.class.cpp.i

src/Cube.algo.class.s: src/Cube.algo.class.cpp.s

.PHONY : src/Cube.algo.class.s

# target to generate assembly for a file
src/Cube.algo.class.cpp.s:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.algo.class.cpp.s
.PHONY : src/Cube.algo.class.cpp.s

src/Cube.class.o: src/Cube.class.cpp.o

.PHONY : src/Cube.class.o

# target to build an object file
src/Cube.class.cpp.o:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.class.cpp.o
.PHONY : src/Cube.class.cpp.o

src/Cube.class.i: src/Cube.class.cpp.i

.PHONY : src/Cube.class.i

# target to preprocess a source file
src/Cube.class.cpp.i:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.class.cpp.i
.PHONY : src/Cube.class.cpp.i

src/Cube.class.s: src/Cube.class.cpp.s

.PHONY : src/Cube.class.s

# target to generate assembly for a file
src/Cube.class.cpp.s:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Cube.class.cpp.s
.PHONY : src/Cube.class.cpp.s

src/OpenCvHandler.class.o: src/OpenCvHandler.class.cpp.o

.PHONY : src/OpenCvHandler.class.o

# target to build an object file
src/OpenCvHandler.class.cpp.o:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/OpenCvHandler.class.cpp.o
.PHONY : src/OpenCvHandler.class.cpp.o

src/OpenCvHandler.class.i: src/OpenCvHandler.class.cpp.i

.PHONY : src/OpenCvHandler.class.i

# target to preprocess a source file
src/OpenCvHandler.class.cpp.i:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/OpenCvHandler.class.cpp.i
.PHONY : src/OpenCvHandler.class.cpp.i

src/OpenCvHandler.class.s: src/OpenCvHandler.class.cpp.s

.PHONY : src/OpenCvHandler.class.s

# target to generate assembly for a file
src/OpenCvHandler.class.cpp.s:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/OpenCvHandler.class.cpp.s
.PHONY : src/OpenCvHandler.class.cpp.s

src/Piece.class.o: src/Piece.class.cpp.o

.PHONY : src/Piece.class.o

# target to build an object file
src/Piece.class.cpp.o:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Piece.class.cpp.o
.PHONY : src/Piece.class.cpp.o

src/Piece.class.i: src/Piece.class.cpp.i

.PHONY : src/Piece.class.i

# target to preprocess a source file
src/Piece.class.cpp.i:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Piece.class.cpp.i
.PHONY : src/Piece.class.cpp.i

src/Piece.class.s: src/Piece.class.cpp.s

.PHONY : src/Piece.class.s

# target to generate assembly for a file
src/Piece.class.cpp.s:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Piece.class.cpp.s
.PHONY : src/Piece.class.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... DisplayImage"
	@echo "... src/Cube.algo.class.o"
	@echo "... src/Cube.algo.class.i"
	@echo "... src/Cube.algo.class.s"
	@echo "... src/Cube.class.o"
	@echo "... src/Cube.class.i"
	@echo "... src/Cube.class.s"
	@echo "... src/OpenCvHandler.class.o"
	@echo "... src/OpenCvHandler.class.i"
	@echo "... src/OpenCvHandler.class.s"
	@echo "... src/Piece.class.o"
	@echo "... src/Piece.class.i"
	@echo "... src/Piece.class.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

