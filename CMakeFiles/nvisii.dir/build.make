# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /beegfs/Tools/easybuild/stacks/rome/2022a/software/CMake/3.23.1-GCCcore-11.3.0/bin/cmake

# The command to remove a file.
RM = /beegfs/Tools/easybuild/stacks/rome/2022a/software/CMake/3.23.1-GCCcore-11.3.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /beegfs/teran_parrales/NVISII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /beegfs/teran_parrales/NVISII

# Include any dependencies generated for this target.
include CMakeFiles/nvisii.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nvisii.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nvisii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nvisii.dir/flags.make

CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o: CMakeFiles/nvisii.dir/flags.make
CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o: CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx
CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o: CMakeFiles/nvisii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/beegfs/teran_parrales/NVISII/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o"
	/beegfs/Tools/easybuild/stacks/rome/2022a/software/GCCcore/11.3.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o -MF CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o.d -o CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o -c /beegfs/teran_parrales/NVISII/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx

CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.i"
	/beegfs/Tools/easybuild/stacks/rome/2022a/software/GCCcore/11.3.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /beegfs/teran_parrales/NVISII/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx > CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.i

CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.s"
	/beegfs/Tools/easybuild/stacks/rome/2022a/software/GCCcore/11.3.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /beegfs/teran_parrales/NVISII/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx -o CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.s

# Object files for target nvisii
nvisii_OBJECTS = \
"CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o"

# External object files for target nvisii
nvisii_EXTERNAL_OBJECTS =

lib/_nvisii.so: CMakeFiles/nvisii.dir/CMakeFiles/nvisii.dir/nvisiiPYTHON_wrap.cxx.o
lib/_nvisii.so: CMakeFiles/nvisii.dir/build.make
lib/_nvisii.so: lib/libgenerator.a
lib/_nvisii.so: lib/libglfw3.a
lib/_nvisii.so: lib/libowl_static.a
lib/_nvisii.so: externals/assimp/lib/libassimp.a
lib/_nvisii.so: lib/libnvisii_lib.a
lib/_nvisii.so: lib/libgenerator.a
lib/_nvisii.so: lib/libglfw3.a
lib/_nvisii.so: /usr/lib64/libm.so
lib/_nvisii.so: lib/libowl_static.a
lib/_nvisii.so: /usr/lib64/libcuda.so
lib/_nvisii.so: externals/assimp/lib/libassimp.a
lib/_nvisii.so: /beegfs/Tools/easybuild/stacks/rome/2022a/software/zlib/1.2.12-GCCcore-11.3.0/lib/libz.so
lib/_nvisii.so: /beegfs/Tools/easybuild/stacks/rome/2022a/software/CUDA/11.7.0/lib64/libcudart_static.a
lib/_nvisii.so: /usr/lib64/librt.so
lib/_nvisii.so: /beegfs/Tools/easybuild/stacks/rome/2022a/software/CUDA/11.7.0/lib64/libcudadevrt.a
lib/_nvisii.so: CMakeFiles/nvisii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/beegfs/teran_parrales/NVISII/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/_nvisii.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nvisii.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nvisii.dir/build: lib/_nvisii.so
.PHONY : CMakeFiles/nvisii.dir/build

CMakeFiles/nvisii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nvisii.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nvisii.dir/clean

CMakeFiles/nvisii.dir/depend:
	cd /beegfs/teran_parrales/NVISII && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /beegfs/teran_parrales/NVISII /beegfs/teran_parrales/NVISII /beegfs/teran_parrales/NVISII /beegfs/teran_parrales/NVISII /beegfs/teran_parrales/NVISII/CMakeFiles/nvisii.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nvisii.dir/depend
