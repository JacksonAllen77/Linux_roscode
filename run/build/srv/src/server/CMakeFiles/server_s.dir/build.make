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
CMAKE_SOURCE_DIR = /home/ro/ROS/run/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ro/ROS/run/build

# Include any dependencies generated for this target.
include srv/src/server/CMakeFiles/server_s.dir/depend.make

# Include the progress variables for this target.
include srv/src/server/CMakeFiles/server_s.dir/progress.make

# Include the compile flags for this target's objects.
include srv/src/server/CMakeFiles/server_s.dir/flags.make

srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.o: srv/src/server/CMakeFiles/server_s.dir/flags.make
srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.o: /home/ro/ROS/run/src/srv/src/server/src/server_s.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ro/ROS/run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.o"
	cd /home/ro/ROS/run/build/srv/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_s.dir/src/server_s.cpp.o -c /home/ro/ROS/run/src/srv/src/server/src/server_s.cpp

srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_s.dir/src/server_s.cpp.i"
	cd /home/ro/ROS/run/build/srv/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ro/ROS/run/src/srv/src/server/src/server_s.cpp > CMakeFiles/server_s.dir/src/server_s.cpp.i

srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_s.dir/src/server_s.cpp.s"
	cd /home/ro/ROS/run/build/srv/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ro/ROS/run/src/srv/src/server/src/server_s.cpp -o CMakeFiles/server_s.dir/src/server_s.cpp.s

# Object files for target server_s
server_s_OBJECTS = \
"CMakeFiles/server_s.dir/src/server_s.cpp.o"

# External object files for target server_s
server_s_EXTERNAL_OBJECTS =

/home/ro/ROS/run/devel/lib/server/server_s: srv/src/server/CMakeFiles/server_s.dir/src/server_s.cpp.o
/home/ro/ROS/run/devel/lib/server/server_s: srv/src/server/CMakeFiles/server_s.dir/build.make
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/libroscpp.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/librosconsole.so
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/librostime.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /opt/ros/noetic/lib/libcpp_common.so
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/ro/ROS/run/devel/lib/server/server_s: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ro/ROS/run/devel/lib/server/server_s: srv/src/server/CMakeFiles/server_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ro/ROS/run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ro/ROS/run/devel/lib/server/server_s"
	cd /home/ro/ROS/run/build/srv/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srv/src/server/CMakeFiles/server_s.dir/build: /home/ro/ROS/run/devel/lib/server/server_s

.PHONY : srv/src/server/CMakeFiles/server_s.dir/build

srv/src/server/CMakeFiles/server_s.dir/clean:
	cd /home/ro/ROS/run/build/srv/src/server && $(CMAKE_COMMAND) -P CMakeFiles/server_s.dir/cmake_clean.cmake
.PHONY : srv/src/server/CMakeFiles/server_s.dir/clean

srv/src/server/CMakeFiles/server_s.dir/depend:
	cd /home/ro/ROS/run/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ro/ROS/run/src /home/ro/ROS/run/src/srv/src/server /home/ro/ROS/run/build /home/ro/ROS/run/build/srv/src/server /home/ro/ROS/run/build/srv/src/server/CMakeFiles/server_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srv/src/server/CMakeFiles/server_s.dir/depend

