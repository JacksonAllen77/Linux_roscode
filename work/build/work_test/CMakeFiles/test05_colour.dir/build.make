# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ro/ROS/work/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ro/ROS/work/build

# Include any dependencies generated for this target.
include work_test/CMakeFiles/test05_colour.dir/depend.make

# Include the progress variables for this target.
include work_test/CMakeFiles/test05_colour.dir/progress.make

# Include the compile flags for this target's objects.
include work_test/CMakeFiles/test05_colour.dir/flags.make

work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o: work_test/CMakeFiles/test05_colour.dir/flags.make
work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o: /home/ro/ROS/work/src/work_test/src/test05_colour.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ro/ROS/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o"
	cd /home/ro/ROS/work/build/work_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o -c /home/ro/ROS/work/src/work_test/src/test05_colour.cpp

work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test05_colour.dir/src/test05_colour.cpp.i"
	cd /home/ro/ROS/work/build/work_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ro/ROS/work/src/work_test/src/test05_colour.cpp > CMakeFiles/test05_colour.dir/src/test05_colour.cpp.i

work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test05_colour.dir/src/test05_colour.cpp.s"
	cd /home/ro/ROS/work/build/work_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ro/ROS/work/src/work_test/src/test05_colour.cpp -o CMakeFiles/test05_colour.dir/src/test05_colour.cpp.s

# Object files for target test05_colour
test05_colour_OBJECTS = \
"CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o"

# External object files for target test05_colour
test05_colour_EXTERNAL_OBJECTS =

/home/ro/ROS/work/devel/lib/work_test/test05_colour: work_test/CMakeFiles/test05_colour.dir/src/test05_colour.cpp.o
/home/ro/ROS/work/devel/lib/work_test/test05_colour: work_test/CMakeFiles/test05_colour.dir/build.make
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/libroscpp.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/librosconsole.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/librostime.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /opt/ros/noetic/lib/libcpp_common.so
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/ro/ROS/work/devel/lib/work_test/test05_colour: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ro/ROS/work/devel/lib/work_test/test05_colour: work_test/CMakeFiles/test05_colour.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ro/ROS/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ro/ROS/work/devel/lib/work_test/test05_colour"
	cd /home/ro/ROS/work/build/work_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test05_colour.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
work_test/CMakeFiles/test05_colour.dir/build: /home/ro/ROS/work/devel/lib/work_test/test05_colour

.PHONY : work_test/CMakeFiles/test05_colour.dir/build

work_test/CMakeFiles/test05_colour.dir/clean:
	cd /home/ro/ROS/work/build/work_test && $(CMAKE_COMMAND) -P CMakeFiles/test05_colour.dir/cmake_clean.cmake
.PHONY : work_test/CMakeFiles/test05_colour.dir/clean

work_test/CMakeFiles/test05_colour.dir/depend:
	cd /home/ro/ROS/work/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ro/ROS/work/src /home/ro/ROS/work/src/work_test /home/ro/ROS/work/build /home/ro/ROS/work/build/work_test /home/ro/ROS/work/build/work_test/CMakeFiles/test05_colour.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : work_test/CMakeFiles/test05_colour.dir/depend

