# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/iastaff/Internship/Digital_Twins_IC382_old/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/iastaff/Internship/Digital_Twins_IC382_old/build

# Utility rule file for clean_test_results_rosserial_test.

# Include the progress variables for this target.
include catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/progress.make

catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test:
	cd /home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_test && /usr/bin/python2 /opt/ros/melodic/share/catkin/cmake/test/remove_test_results.py /home/iastaff/Digital_Twins_IC382/build/test_results/rosserial_test

clean_test_results_rosserial_test: catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test
clean_test_results_rosserial_test: catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/build.make

.PHONY : clean_test_results_rosserial_test

# Rule to build all files generated by this target.
catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/build: clean_test_results_rosserial_test

.PHONY : catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/build

catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/clean:
	cd /home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_test && $(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_rosserial_test.dir/cmake_clean.cmake
.PHONY : catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/clean

catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/depend:
	cd /home/iastaff/Internship/Digital_Twins_IC382_old/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iastaff/Internship/Digital_Twins_IC382_old/src /home/iastaff/Internship/Digital_Twins_IC382_old/src/catkin_arduino/src/rosserial/rosserial_test /home/iastaff/Internship/Digital_Twins_IC382_old/build /home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_test /home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : catkin_arduino/src/rosserial/rosserial_test/CMakeFiles/clean_test_results_rosserial_test.dir/depend

