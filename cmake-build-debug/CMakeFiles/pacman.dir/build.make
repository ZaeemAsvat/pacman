# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/zaeemasvat_/Downloads/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zaeemasvat_/Downloads/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zaeemasvat_/CLionProjects/pacman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pacman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pacman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pacman.dir/flags.make

CMakeFiles/pacman.dir/main.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pacman.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/main.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/main.cpp

CMakeFiles/pacman.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/main.cpp > CMakeFiles/pacman.dir/main.cpp.i

CMakeFiles/pacman.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/main.cpp -o CMakeFiles/pacman.dir/main.cpp.s

CMakeFiles/pacman.dir/window.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/window.cpp.o: ../window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pacman.dir/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/window.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/window.cpp

CMakeFiles/pacman.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/window.cpp > CMakeFiles/pacman.dir/window.cpp.i

CMakeFiles/pacman.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/window.cpp -o CMakeFiles/pacman.dir/window.cpp.s

CMakeFiles/pacman.dir/world.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/world.cpp.o: ../world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pacman.dir/world.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/world.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/world.cpp

CMakeFiles/pacman.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/world.cpp > CMakeFiles/pacman.dir/world.cpp.i

CMakeFiles/pacman.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/world.cpp -o CMakeFiles/pacman.dir/world.cpp.s

CMakeFiles/pacman.dir/tile.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/tile.cpp.o: ../tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pacman.dir/tile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/tile.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/tile.cpp

CMakeFiles/pacman.dir/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/tile.cpp > CMakeFiles/pacman.dir/tile.cpp.i

CMakeFiles/pacman.dir/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/tile.cpp -o CMakeFiles/pacman.dir/tile.cpp.s

CMakeFiles/pacman.dir/texture.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/texture.cpp.o: ../texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pacman.dir/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/texture.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/texture.cpp

CMakeFiles/pacman.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/texture.cpp > CMakeFiles/pacman.dir/texture.cpp.i

CMakeFiles/pacman.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/texture.cpp -o CMakeFiles/pacman.dir/texture.cpp.s

CMakeFiles/pacman.dir/pacman.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/pacman.cpp.o: ../pacman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pacman.dir/pacman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/pacman.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/pacman.cpp

CMakeFiles/pacman.dir/pacman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/pacman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/pacman.cpp > CMakeFiles/pacman.dir/pacman.cpp.i

CMakeFiles/pacman.dir/pacman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/pacman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/pacman.cpp -o CMakeFiles/pacman.dir/pacman.cpp.s

CMakeFiles/pacman.dir/ghost.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/ghost.cpp.o: ../ghost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pacman.dir/ghost.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/ghost.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/ghost.cpp

CMakeFiles/pacman.dir/ghost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/ghost.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/ghost.cpp > CMakeFiles/pacman.dir/ghost.cpp.i

CMakeFiles/pacman.dir/ghost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/ghost.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/ghost.cpp -o CMakeFiles/pacman.dir/ghost.cpp.s

CMakeFiles/pacman.dir/helpers.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/helpers.cpp.o: ../helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pacman.dir/helpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/helpers.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/helpers.cpp

CMakeFiles/pacman.dir/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/helpers.cpp > CMakeFiles/pacman.dir/helpers.cpp.i

CMakeFiles/pacman.dir/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/helpers.cpp -o CMakeFiles/pacman.dir/helpers.cpp.s

CMakeFiles/pacman.dir/character.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/character.cpp.o: ../character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pacman.dir/character.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/character.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/character.cpp

CMakeFiles/pacman.dir/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/character.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/character.cpp > CMakeFiles/pacman.dir/character.cpp.i

CMakeFiles/pacman.dir/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/character.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/character.cpp -o CMakeFiles/pacman.dir/character.cpp.s

CMakeFiles/pacman.dir/timer.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/timer.cpp.o: ../timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pacman.dir/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/timer.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/timer.cpp

CMakeFiles/pacman.dir/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/timer.cpp > CMakeFiles/pacman.dir/timer.cpp.i

CMakeFiles/pacman.dir/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/timer.cpp -o CMakeFiles/pacman.dir/timer.cpp.s

CMakeFiles/pacman.dir/BlueGhost.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/BlueGhost.cpp.o: ../BlueGhost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pacman.dir/BlueGhost.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/BlueGhost.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/BlueGhost.cpp

CMakeFiles/pacman.dir/BlueGhost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/BlueGhost.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/BlueGhost.cpp > CMakeFiles/pacman.dir/BlueGhost.cpp.i

CMakeFiles/pacman.dir/BlueGhost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/BlueGhost.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/BlueGhost.cpp -o CMakeFiles/pacman.dir/BlueGhost.cpp.s

CMakeFiles/pacman.dir/RedGhost.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/RedGhost.cpp.o: ../RedGhost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pacman.dir/RedGhost.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/RedGhost.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/RedGhost.cpp

CMakeFiles/pacman.dir/RedGhost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/RedGhost.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/RedGhost.cpp > CMakeFiles/pacman.dir/RedGhost.cpp.i

CMakeFiles/pacman.dir/RedGhost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/RedGhost.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/RedGhost.cpp -o CMakeFiles/pacman.dir/RedGhost.cpp.s

CMakeFiles/pacman.dir/mazeIndex.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/mazeIndex.cpp.o: ../mazeIndex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pacman.dir/mazeIndex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/mazeIndex.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/mazeIndex.cpp

CMakeFiles/pacman.dir/mazeIndex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/mazeIndex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/mazeIndex.cpp > CMakeFiles/pacman.dir/mazeIndex.cpp.i

CMakeFiles/pacman.dir/mazeIndex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/mazeIndex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/mazeIndex.cpp -o CMakeFiles/pacman.dir/mazeIndex.cpp.s

CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o: ../LoadLevelHelpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/LoadLevelHelpers.cpp

CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/LoadLevelHelpers.cpp > CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.i

CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/LoadLevelHelpers.cpp -o CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.s

CMakeFiles/pacman.dir/GhostPlan.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/GhostPlan.cpp.o: ../GhostPlan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/pacman.dir/GhostPlan.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/GhostPlan.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/GhostPlan.cpp

CMakeFiles/pacman.dir/GhostPlan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/GhostPlan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/GhostPlan.cpp > CMakeFiles/pacman.dir/GhostPlan.cpp.i

CMakeFiles/pacman.dir/GhostPlan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/GhostPlan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/GhostPlan.cpp -o CMakeFiles/pacman.dir/GhostPlan.cpp.s

CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o: ../GhostScatterPeriod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o -c /home/zaeemasvat_/CLionProjects/pacman/GhostScatterPeriod.cpp

CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaeemasvat_/CLionProjects/pacman/GhostScatterPeriod.cpp > CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.i

CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaeemasvat_/CLionProjects/pacman/GhostScatterPeriod.cpp -o CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.s

# Object files for target pacman
pacman_OBJECTS = \
"CMakeFiles/pacman.dir/main.cpp.o" \
"CMakeFiles/pacman.dir/window.cpp.o" \
"CMakeFiles/pacman.dir/world.cpp.o" \
"CMakeFiles/pacman.dir/tile.cpp.o" \
"CMakeFiles/pacman.dir/texture.cpp.o" \
"CMakeFiles/pacman.dir/pacman.cpp.o" \
"CMakeFiles/pacman.dir/ghost.cpp.o" \
"CMakeFiles/pacman.dir/helpers.cpp.o" \
"CMakeFiles/pacman.dir/character.cpp.o" \
"CMakeFiles/pacman.dir/timer.cpp.o" \
"CMakeFiles/pacman.dir/BlueGhost.cpp.o" \
"CMakeFiles/pacman.dir/RedGhost.cpp.o" \
"CMakeFiles/pacman.dir/mazeIndex.cpp.o" \
"CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o" \
"CMakeFiles/pacman.dir/GhostPlan.cpp.o" \
"CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o"

# External object files for target pacman
pacman_EXTERNAL_OBJECTS =

pacman: CMakeFiles/pacman.dir/main.cpp.o
pacman: CMakeFiles/pacman.dir/window.cpp.o
pacman: CMakeFiles/pacman.dir/world.cpp.o
pacman: CMakeFiles/pacman.dir/tile.cpp.o
pacman: CMakeFiles/pacman.dir/texture.cpp.o
pacman: CMakeFiles/pacman.dir/pacman.cpp.o
pacman: CMakeFiles/pacman.dir/ghost.cpp.o
pacman: CMakeFiles/pacman.dir/helpers.cpp.o
pacman: CMakeFiles/pacman.dir/character.cpp.o
pacman: CMakeFiles/pacman.dir/timer.cpp.o
pacman: CMakeFiles/pacman.dir/BlueGhost.cpp.o
pacman: CMakeFiles/pacman.dir/RedGhost.cpp.o
pacman: CMakeFiles/pacman.dir/mazeIndex.cpp.o
pacman: CMakeFiles/pacman.dir/LoadLevelHelpers.cpp.o
pacman: CMakeFiles/pacman.dir/GhostPlan.cpp.o
pacman: CMakeFiles/pacman.dir/GhostScatterPeriod.cpp.o
pacman: CMakeFiles/pacman.dir/build.make
pacman: CMakeFiles/pacman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable pacman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pacman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pacman.dir/build: pacman

.PHONY : CMakeFiles/pacman.dir/build

CMakeFiles/pacman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pacman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pacman.dir/clean

CMakeFiles/pacman.dir/depend:
	cd /home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zaeemasvat_/CLionProjects/pacman /home/zaeemasvat_/CLionProjects/pacman /home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug /home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug /home/zaeemasvat_/CLionProjects/pacman/cmake-build-debug/CMakeFiles/pacman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pacman.dir/depend

