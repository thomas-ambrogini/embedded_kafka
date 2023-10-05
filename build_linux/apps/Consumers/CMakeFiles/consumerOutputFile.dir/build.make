# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/thomas/.local/bin/cmake

# The command to remove a file.
RM = /home/thomas/.local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/embedded_kafka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/embedded_kafka/build_linux

# Include any dependencies generated for this target.
include apps/Consumers/CMakeFiles/consumerOutputFile.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include apps/Consumers/CMakeFiles/consumerOutputFile.dir/compiler_depend.make

# Include the progress variables for this target.
include apps/Consumers/CMakeFiles/consumerOutputFile.dir/progress.make

# Include the compile flags for this target's objects.
include apps/Consumers/CMakeFiles/consumerOutputFile.dir/flags.make

apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o: apps/Consumers/CMakeFiles/consumerOutputFile.dir/flags.make
apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o: /home/thomas/embedded_kafka/apps/Consumers/consumerOutputFile.cpp
apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o: apps/Consumers/CMakeFiles/consumerOutputFile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/embedded_kafka/build_linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o"
	cd /home/thomas/embedded_kafka/build_linux/apps/Consumers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o -MF CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o.d -o CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o -c /home/thomas/embedded_kafka/apps/Consumers/consumerOutputFile.cpp

apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.i"
	cd /home/thomas/embedded_kafka/build_linux/apps/Consumers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/embedded_kafka/apps/Consumers/consumerOutputFile.cpp > CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.i

apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.s"
	cd /home/thomas/embedded_kafka/build_linux/apps/Consumers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/embedded_kafka/apps/Consumers/consumerOutputFile.cpp -o CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.s

# Object files for target consumerOutputFile
consumerOutputFile_OBJECTS = \
"CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o"

# External object files for target consumerOutputFile
consumerOutputFile_EXTERNAL_OBJECTS =

apps/Consumers/consumerOutputFile: apps/Consumers/CMakeFiles/consumerOutputFile.dir/consumerOutputFile.cpp.o
apps/Consumers/consumerOutputFile: apps/Consumers/CMakeFiles/consumerOutputFile.dir/build.make
apps/Consumers/consumerOutputFile: src/Application/libapplication_library.a
apps/Consumers/consumerOutputFile: src/Diagnostic/libdiagnostic_library.a
apps/Consumers/consumerOutputFile: src/TopicManager/libtopicmanager_library.a
apps/Consumers/consumerOutputFile: src/Communication/libcommunication_library.a
apps/Consumers/consumerOutputFile: src/Domain/libdomain_library.a
apps/Consumers/consumerOutputFile: src/utils/libutils_library.a
apps/Consumers/consumerOutputFile: external/ti_rpmsg_char/libti_rpmsg_char_library.a
apps/Consumers/consumerOutputFile: apps/Consumers/CMakeFiles/consumerOutputFile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/embedded_kafka/build_linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable consumerOutputFile"
	cd /home/thomas/embedded_kafka/build_linux/apps/Consumers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/consumerOutputFile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/Consumers/CMakeFiles/consumerOutputFile.dir/build: apps/Consumers/consumerOutputFile
.PHONY : apps/Consumers/CMakeFiles/consumerOutputFile.dir/build

apps/Consumers/CMakeFiles/consumerOutputFile.dir/clean:
	cd /home/thomas/embedded_kafka/build_linux/apps/Consumers && $(CMAKE_COMMAND) -P CMakeFiles/consumerOutputFile.dir/cmake_clean.cmake
.PHONY : apps/Consumers/CMakeFiles/consumerOutputFile.dir/clean

apps/Consumers/CMakeFiles/consumerOutputFile.dir/depend:
	cd /home/thomas/embedded_kafka/build_linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/embedded_kafka /home/thomas/embedded_kafka/apps/Consumers /home/thomas/embedded_kafka/build_linux /home/thomas/embedded_kafka/build_linux/apps/Consumers /home/thomas/embedded_kafka/build_linux/apps/Consumers/CMakeFiles/consumerOutputFile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/Consumers/CMakeFiles/consumerOutputFile.dir/depend
