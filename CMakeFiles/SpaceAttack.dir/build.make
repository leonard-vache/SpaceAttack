# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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

# Include any dependencies generated for this target.
include CMakeFiles/SpaceAttack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SpaceAttack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpaceAttack.dir/flags.make

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o: src/GraphicsMgt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o   -c /home/leo/Git_Project/SpaceAttack/src/GraphicsMgt.c

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/GraphicsMgt.c > CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.i

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/GraphicsMgt.c -o CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.s

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.requires

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.provides: CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.provides

CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o

CMakeFiles/SpaceAttack.dir/src/Element.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/Element.c.o: src/Element.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/Element.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/Element.c.o   -c /home/leo/Git_Project/SpaceAttack/src/Element.c

CMakeFiles/SpaceAttack.dir/src/Element.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/Element.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/Element.c > CMakeFiles/SpaceAttack.dir/src/Element.c.i

CMakeFiles/SpaceAttack.dir/src/Element.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/Element.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/Element.c -o CMakeFiles/SpaceAttack.dir/src/Element.c.s

CMakeFiles/SpaceAttack.dir/src/Element.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/Element.c.o.requires

CMakeFiles/SpaceAttack.dir/src/Element.c.o.provides: CMakeFiles/SpaceAttack.dir/src/Element.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Element.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/Element.c.o.provides

CMakeFiles/SpaceAttack.dir/src/Element.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/Element.c.o

CMakeFiles/SpaceAttack.dir/src/main.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/main.c.o: src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/main.c.o   -c /home/leo/Git_Project/SpaceAttack/src/main.c

CMakeFiles/SpaceAttack.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/main.c > CMakeFiles/SpaceAttack.dir/src/main.c.i

CMakeFiles/SpaceAttack.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/main.c -o CMakeFiles/SpaceAttack.dir/src/main.c.s

CMakeFiles/SpaceAttack.dir/src/main.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/main.c.o.requires

CMakeFiles/SpaceAttack.dir/src/main.c.o.provides: CMakeFiles/SpaceAttack.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/main.c.o.provides

CMakeFiles/SpaceAttack.dir/src/main.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/main.c.o

CMakeFiles/SpaceAttack.dir/src/Geometry.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/Geometry.c.o: src/Geometry.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/Geometry.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/Geometry.c.o   -c /home/leo/Git_Project/SpaceAttack/src/Geometry.c

CMakeFiles/SpaceAttack.dir/src/Geometry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/Geometry.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/Geometry.c > CMakeFiles/SpaceAttack.dir/src/Geometry.c.i

CMakeFiles/SpaceAttack.dir/src/Geometry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/Geometry.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/Geometry.c -o CMakeFiles/SpaceAttack.dir/src/Geometry.c.s

CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.requires

CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.provides: CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.provides

CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/Geometry.c.o

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o: src/KeyboardMgt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o   -c /home/leo/Git_Project/SpaceAttack/src/KeyboardMgt.c

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/KeyboardMgt.c > CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.i

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/KeyboardMgt.c -o CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.s

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.requires

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.provides: CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.provides

CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o

CMakeFiles/SpaceAttack.dir/src/Collision.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/Collision.c.o: src/Collision.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/Collision.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/Collision.c.o   -c /home/leo/Git_Project/SpaceAttack/src/Collision.c

CMakeFiles/SpaceAttack.dir/src/Collision.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/Collision.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/Collision.c > CMakeFiles/SpaceAttack.dir/src/Collision.c.i

CMakeFiles/SpaceAttack.dir/src/Collision.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/Collision.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/Collision.c -o CMakeFiles/SpaceAttack.dir/src/Collision.c.s

CMakeFiles/SpaceAttack.dir/src/Collision.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/Collision.c.o.requires

CMakeFiles/SpaceAttack.dir/src/Collision.c.o.provides: CMakeFiles/SpaceAttack.dir/src/Collision.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Collision.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/Collision.c.o.provides

CMakeFiles/SpaceAttack.dir/src/Collision.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/Collision.c.o

CMakeFiles/SpaceAttack.dir/src/Motion.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/Motion.c.o: src/Motion.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/Motion.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/Motion.c.o   -c /home/leo/Git_Project/SpaceAttack/src/Motion.c

CMakeFiles/SpaceAttack.dir/src/Motion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/Motion.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/Motion.c > CMakeFiles/SpaceAttack.dir/src/Motion.c.i

CMakeFiles/SpaceAttack.dir/src/Motion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/Motion.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/Motion.c -o CMakeFiles/SpaceAttack.dir/src/Motion.c.s

CMakeFiles/SpaceAttack.dir/src/Motion.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/Motion.c.o.requires

CMakeFiles/SpaceAttack.dir/src/Motion.c.o.provides: CMakeFiles/SpaceAttack.dir/src/Motion.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/Motion.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/Motion.c.o.provides

CMakeFiles/SpaceAttack.dir/src/Motion.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/Motion.c.o

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o: CMakeFiles/SpaceAttack.dir/flags.make
CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o: src/GameMgt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Git_Project/SpaceAttack/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o   -c /home/leo/Git_Project/SpaceAttack/src/GameMgt.c

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SpaceAttack.dir/src/GameMgt.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/Git_Project/SpaceAttack/src/GameMgt.c > CMakeFiles/SpaceAttack.dir/src/GameMgt.c.i

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SpaceAttack.dir/src/GameMgt.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/Git_Project/SpaceAttack/src/GameMgt.c -o CMakeFiles/SpaceAttack.dir/src/GameMgt.c.s

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.requires:
.PHONY : CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.requires

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.provides: CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.requires
	$(MAKE) -f CMakeFiles/SpaceAttack.dir/build.make CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.provides.build
.PHONY : CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.provides

CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.provides.build: CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o

# Object files for target SpaceAttack
SpaceAttack_OBJECTS = \
"CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o" \
"CMakeFiles/SpaceAttack.dir/src/Element.c.o" \
"CMakeFiles/SpaceAttack.dir/src/main.c.o" \
"CMakeFiles/SpaceAttack.dir/src/Geometry.c.o" \
"CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o" \
"CMakeFiles/SpaceAttack.dir/src/Collision.c.o" \
"CMakeFiles/SpaceAttack.dir/src/Motion.c.o" \
"CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o"

# External object files for target SpaceAttack
SpaceAttack_EXTERNAL_OBJECTS =

bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/Element.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/main.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/Geometry.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/Collision.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/Motion.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/build.make
bin/SpaceAttack: /usr/lib/x86_64-linux-gnu/libSDL2main.a
bin/SpaceAttack: /usr/lib/x86_64-linux-gnu/libSDL2.so
bin/SpaceAttack: CMakeFiles/SpaceAttack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable bin/SpaceAttack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpaceAttack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpaceAttack.dir/build: bin/SpaceAttack
.PHONY : CMakeFiles/SpaceAttack.dir/build

CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/GraphicsMgt.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/Element.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/main.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/Geometry.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/KeyboardMgt.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/Collision.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/Motion.c.o.requires
CMakeFiles/SpaceAttack.dir/requires: CMakeFiles/SpaceAttack.dir/src/GameMgt.c.o.requires
.PHONY : CMakeFiles/SpaceAttack.dir/requires

CMakeFiles/SpaceAttack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpaceAttack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpaceAttack.dir/clean

CMakeFiles/SpaceAttack.dir/depend:
	cd /home/leo/Git_Project/SpaceAttack && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/Git_Project/SpaceAttack /home/leo/Git_Project/SpaceAttack /home/leo/Git_Project/SpaceAttack /home/leo/Git_Project/SpaceAttack /home/leo/Git_Project/SpaceAttack/CMakeFiles/SpaceAttack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpaceAttack.dir/depend

