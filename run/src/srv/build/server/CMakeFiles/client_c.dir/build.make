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
CMAKE_SOURCE_DIR = /home/ro/ROS/srv/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ro/ROS/srv/build

# Include any dependencies generated for this target.
include server/CMakeFiles/client_c.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/client_c.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/client_c.dir/flags.make

server/CMakeFiles/client_c.dir/src/client_c.cpp.o: server/CMakeFiles/client_c.dir/flags.make
server/CMakeFiles/client_c.dir/src/client_c.cpp.o: /home/ro/ROS/srv/src/server/src/client_c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ro/ROS/srv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server/CMakeFiles/client_c.dir/src/client_c.cpp.o"
	cd /home/ro/ROS/srv/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_c.dir/src/client_c.cpp.o -c /home/ro/ROS/srv/src/server/src/client_c.cpp

server/CMakeFiles/client_c.dir/src/client_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_c.dir/src/client_c.cpp.i"
	cd /home/ro/ROS/srv/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ro/ROS/srv/src/server/src/client_c.cpp > CMakeFiles/client_c.dir/src/client_c.cpp.i

server/CMakeFiles/client_c.dir/src/client_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_c.dir/src/client_c.cpp.s"
	cd /home/ro/ROS/srv/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ro/ROS/srv/src/server/src/client_c.cpp -o CMakeFiles/client_c.dir/src/client_c.cpp.s

# Object files for target client_c
client_c_OBJECTS = \
"CMakeFiles/client_c.dir/src/client_c.cpp.o"

# External object files for target client_c
client_c_EXTERNAL_OBJECTS =

/home/ro/ROS/srv/devel/lib/server/client_c: server/CMakeFiles/client_c.dir/src/client_c.cpp.o
/home/ro/ROS/srv/devel/lib/server/client_c: server/CMakeFiles/client_c.dir/build.make
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/libroscpp.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/librosconsole.so
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/librostime.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /opt/ros/noetic/lib/libcpp_common.so
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/ro/ROS/srv/devel/lib/server/client_c: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ro/ROS/srv/devel/lib/server/client_c: server/CMakeFiles/client_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ro/ROS/srv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ro/ROS/srv/devel/lib/server/client_c"
	cd /home/ro/ROS/srv/build/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/client_c.dir/build: /home/ro/ROS/srv/devel/lib/server/client_c

.PHONY : server/CMakeFiles/client_c.dir/build

server/CMakeFiles/client_c.dir/clean:
	cd /home/ro/ROS/srv/build/server && $(CMAKE_COMMAND) -P CMakeFiles/client_c.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/client_c.dir/clean

server/CMakeFiles/client_c.dir/depend:
	cd /home/ro/ROS/srv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ro/ROS/srv/src /home/ro/ROS/srv/src/server /home/ro/ROS/srv/build /home/ro/ROS/srv/build/server /home/ro/ROS/srv/build/server/CMakeFiles/client_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/client_c.dir/depend

