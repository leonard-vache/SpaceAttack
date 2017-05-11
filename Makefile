# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_SOURCE_DIR = /home/leo/Git_Project/SpaceAttack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/Git_Project/SpaceAttack

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/leo/Git_Project/SpaceAttack/CMakeFiles /home/leo/Git_Project/SpaceAttack/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/leo/Git_Project/SpaceAttack/CMakeFiles 0
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
# Target rules for targets named SpaceAttack

# Build rule for target.
SpaceAttack: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SpaceAttack
.PHONY : SpaceAttack

# fast build rule for target.
SpaceAttack/fast:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/build
.PHONY : SpaceAttack/fast

src/Collision.o: src/Collision.c.o
.PHONY : src/Collision.o

# target to build an object file
src/Collision.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Collision.c.o
.PHONY : src/Collision.c.o

src/Collision.i: src/Collision.c.i
.PHONY : src/Collision.i

# target to preprocess a source file
src/Collision.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Collision.c.i
.PHONY : src/Collision.c.i

src/Collision.s: src/Collision.c.s
.PHONY : src/Collision.s

# target to generate assembly for a file
src/Collision.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Collision.c.s
.PHONY : src/Collision.c.s

src/Element.o: src/Element.c.o
.PHONY : src/Element.o

# target to build an object file
src/Element.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Element.c.o
.PHONY : src/Element.c.o

src/Element.i: src/Element.c.i
.PHONY : src/Element.i

# target to preprocess a source file
src/Element.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Element.c.i
.PHONY : src/Element.c.i

src/Element.s: src/Element.c.s
.PHONY : src/Element.s

# target to generate assembly for a file
src/Element.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Element.c.s
.PHONY : src/Element.c.s

src/GameMgt.o: src/GameMgt.c.o
.PHONY : src/GameMgt.o

# target to build an object file
src/GameMgt.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o
.PHONY : src/GameMgt.c.o

src/GameMgt.i: src/GameMgt.c.i
.PHONY : src/GameMgt.i

# target to preprocess a source file
src/GameMgt.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GameMgt.c.i
.PHONY : src/GameMgt.c.i

src/GameMgt.s: src/GameMgt.c.s
.PHONY : src/GameMgt.s

# target to generate assembly for a file
src/GameMgt.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GameMgt.c.s
.PHONY : src/GameMgt.c.s

src/Geometry.o: src/Geometry.c.o
.PHONY : src/Geometry.o

# target to build an object file
src/Geometry.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Geometry.c.o
.PHONY : src/Geometry.c.o

src/Geometry.i: src/Geometry.c.i
.PHONY : src/Geometry.i

# target to preprocess a source file
src/Geometry.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Geometry.c.i
.PHONY : src/Geometry.c.i

src/Geometry.s: src/Geometry.c.s
.PHONY : src/Geometry.s

# target to generate assembly for a file
src/Geometry.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Geometry.c.s
.PHONY : src/Geometry.c.s

src/GraphicsMgt.o: src/GraphicsMgt.c.o
.PHONY : src/GraphicsMgt.o

# target to build an object file
src/GraphicsMgt.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o
.PHONY : src/GraphicsMgt.c.o

src/GraphicsMgt.i: src/GraphicsMgt.c.i
.PHONY : src/GraphicsMgt.i

# target to preprocess a source file
src/GraphicsMgt.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.i
.PHONY : src/GraphicsMgt.c.i

src/GraphicsMgt.s: src/GraphicsMgt.c.s
.PHONY : src/GraphicsMgt.s

# target to generate assembly for a file
src/GraphicsMgt.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.s
.PHONY : src/GraphicsMgt.c.s

src/KeyboardMgt.o: src/KeyboardMgt.c.o
.PHONY : src/KeyboardMgt.o

# target to build an object file
src/KeyboardMgt.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o
.PHONY : src/KeyboardMgt.c.o

src/KeyboardMgt.i: src/KeyboardMgt.c.i
.PHONY : src/KeyboardMgt.i

# target to preprocess a source file
src/KeyboardMgt.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.i
.PHONY : src/KeyboardMgt.c.i

src/KeyboardMgt.s: src/KeyboardMgt.c.s
.PHONY : src/KeyboardMgt.s

# target to generate assembly for a file
src/KeyboardMgt.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.s
.PHONY : src/KeyboardMgt.c.s

src/Motion.o: src/Motion.c.o
.PHONY : src/Motion.o

# target to build an object file
src/Motion.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Motion.c.o
.PHONY : src/Motion.c.o

src/Motion.i: src/Motion.c.i
.PHONY : src/Motion.i

# target to preprocess a source file
src/Motion.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Motion.c.i
.PHONY : src/Motion.c.i

src/Motion.s: src/Motion.c.s
.PHONY : src/Motion.s

# target to generate assembly for a file
src/Motion.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Motion.c.s
.PHONY : src/Motion.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/main.c.s
.PHONY : src/main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... SpaceAttack"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... src/Collision.o"
	@echo "... src/Collision.i"
	@echo "... src/Collision.s"
	@echo "... src/Element.o"
	@echo "... src/Element.i"
	@echo "... src/Element.s"
	@echo "... src/GameMgt.o"
	@echo "... src/GameMgt.i"
	@echo "... src/GameMgt.s"
	@echo "... src/Geometry.o"
	@echo "... src/Geometry.i"
	@echo "... src/Geometry.s"
	@echo "... src/GraphicsMgt.o"
	@echo "... src/GraphicsMgt.i"
	@echo "... src/GraphicsMgt.s"
	@echo "... src/KeyboardMgt.o"
	@echo "... src/KeyboardMgt.i"
	@echo "... src/KeyboardMgt.s"
	@echo "... src/Motion.o"
	@echo "... src/Motion.i"
	@echo "... src/Motion.s"
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

