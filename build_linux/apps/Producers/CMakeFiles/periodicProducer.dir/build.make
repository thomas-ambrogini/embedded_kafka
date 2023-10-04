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
include apps/Producers/CMakeFiles/periodicProducer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include apps/Producers/CMakeFiles/periodicProducer.dir/compiler_depend.make

# Include the progress variables for this target.
include apps/Producers/CMakeFiles/periodicProducer.dir/progress.make

# Include the compile flags for this target's objects.
include apps/Producers/CMakeFiles/periodicProducer.dir/flags.make

apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o: apps/Producers/CMakeFiles/periodicProducer.dir/flags.make
apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o: /home/thomas/embedded_kafka/apps/Producers/periodicProducer.cpp
apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o: apps/Producers/CMakeFiles/periodicProducer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/embedded_kafka/build_linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o"
	cd /home/thomas/embedded_kafka/build_linux/apps/Producers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o -MF CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o.d -o CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o -c /home/thomas/embedded_kafka/apps/Producers/periodicProducer.cpp

apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/periodicProducer.dir/periodicProducer.cpp.i"
	cd /home/thomas/embedded_kafka/build_linux/apps/Producers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/embedded_kafka/apps/Producers/periodicProducer.cpp > CMakeFiles/periodicProducer.dir/periodicProducer.cpp.i

apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/periodicProducer.dir/periodicProducer.cpp.s"
	cd /home/thomas/embedded_kafka/build_linux/apps/Producers && /opt/cross-compilers/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/embedded_kafka/apps/Producers/periodicProducer.cpp -o CMakeFiles/periodicProducer.dir/periodicProducer.cpp.s

# Object files for target periodicProducer
periodicProducer_OBJECTS = \
"CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o"

# External object files for target periodicProducer
periodicProducer_EXTERNAL_OBJECTS =

apps/Producers/periodicProducer: apps/Producers/CMakeFiles/periodicProducer.dir/periodicProducer.cpp.o
apps/Producers/periodicProducer: apps/Producers/CMakeFiles/periodicProducer.dir/build.make
apps/Producers/periodicProducer: src/Application/libapplication_library.a
apps/Producers/periodicProducer: src/Diagnostic/libdiagnostic_library.a
apps/Producers/periodicProducer: src/TopicManager/libtopicmanager_library.a
apps/Producers/periodicProducer: src/Communication/libcommunication_library.a
apps/Producers/periodicProducer: src/Domain/libdomain_library.a
apps/Producers/periodicProducer: src/utils/libutils_library.a
apps/Producers/periodicProducer: external/ti_rpmsg_char/libti_rpmsg_char_library.a
apps/Producers/periodicProducer: apps/Producers/CMakeFiles/periodicProducer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/embedded_kafka/build_linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable periodicProducer"
	cd /home/thomas/embedded_kafka/build_linux/apps/Producers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/periodicProducer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/Producers/CMakeFiles/periodicProducer.dir/build: apps/Producers/periodicProducer
.PHONY : apps/Producers/CMakeFiles/periodicProducer.dir/build

apps/Producers/CMakeFiles/periodicProducer.dir/clean:
	cd /home/thomas/embedded_kafka/build_linux/apps/Producers && $(CMAKE_COMMAND) -P CMakeFiles/periodicProducer.dir/cmake_clean.cmake
.PHONY : apps/Producers/CMakeFiles/periodicProducer.dir/clean

apps/Producers/CMakeFiles/periodicProducer.dir/depend:
	cd /home/thomas/embedded_kafka/build_linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/embedded_kafka /home/thomas/embedded_kafka/apps/Producers /home/thomas/embedded_kafka/build_linux /home/thomas/embedded_kafka/build_linux/apps/Producers /home/thomas/embedded_kafka/build_linux/apps/Producers/CMakeFiles/periodicProducer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/Producers/CMakeFiles/periodicProducer.dir/depend

