# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Aplicaciones\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Aplicaciones\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Conecta4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Conecta4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Conecta4.dir/flags.make

CMakeFiles/Conecta4.dir/Conecta4.c.obj: CMakeFiles/Conecta4.dir/flags.make
CMakeFiles/Conecta4.dir/Conecta4.c.obj: CMakeFiles/Conecta4.dir/includes_C.rsp
CMakeFiles/Conecta4.dir/Conecta4.c.obj: ../Conecta4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Conecta4.dir/Conecta4.c.obj"
	D:\Aplicaciones\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Conecta4.dir\Conecta4.c.obj -c C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\Conecta4.c

CMakeFiles/Conecta4.dir/Conecta4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Conecta4.dir/Conecta4.c.i"
	D:\Aplicaciones\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\Conecta4.c > CMakeFiles\Conecta4.dir\Conecta4.c.i

CMakeFiles/Conecta4.dir/Conecta4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Conecta4.dir/Conecta4.c.s"
	D:\Aplicaciones\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\Conecta4.c -o CMakeFiles\Conecta4.dir\Conecta4.c.s

# Object files for target Conecta4
Conecta4_OBJECTS = \
"CMakeFiles/Conecta4.dir/Conecta4.c.obj"

# External object files for target Conecta4
Conecta4_EXTERNAL_OBJECTS =

Conecta4.exe: CMakeFiles/Conecta4.dir/Conecta4.c.obj
Conecta4.exe: CMakeFiles/Conecta4.dir/build.make
Conecta4.exe: CMakeFiles/Conecta4.dir/linklibs.rsp
Conecta4.exe: CMakeFiles/Conecta4.dir/objects1.rsp
Conecta4.exe: CMakeFiles/Conecta4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Conecta4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Conecta4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Conecta4.dir/build: Conecta4.exe
.PHONY : CMakeFiles/Conecta4.dir/build

CMakeFiles/Conecta4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Conecta4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Conecta4.dir/clean

CMakeFiles/Conecta4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4 C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4 C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug C:\Users\isaac\Desktop\VegaIsaac\Proyecto\Conecta4\cmake-build-debug\CMakeFiles\Conecta4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Conecta4.dir/depend

