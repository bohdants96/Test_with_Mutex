﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bohda\CLionProjects\CreateMutex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\CreateMutex.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\CreateMutex.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CreateMutex.dir\flags.make

CMakeFiles\CreateMutex.dir\main.cpp.obj: CMakeFiles\CreateMutex.dir\flags.make
CMakeFiles\CreateMutex.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CreateMutex.dir/main.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1433~1.316\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CreateMutex.dir\main.cpp.obj /FdCMakeFiles\CreateMutex.dir\ /FS -c C:\Users\bohda\CLionProjects\CreateMutex\main.cpp
<<

CMakeFiles\CreateMutex.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CreateMutex.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1433~1.316\bin\Hostx86\x86\cl.exe > CMakeFiles\CreateMutex.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\bohda\CLionProjects\CreateMutex\main.cpp
<<

CMakeFiles\CreateMutex.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CreateMutex.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1433~1.316\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CreateMutex.dir\main.cpp.s /c C:\Users\bohda\CLionProjects\CreateMutex\main.cpp
<<

# Object files for target CreateMutex
CreateMutex_OBJECTS = \
"CMakeFiles\CreateMutex.dir\main.cpp.obj"

# External object files for target CreateMutex
CreateMutex_EXTERNAL_OBJECTS =

CreateMutex.exe: CMakeFiles\CreateMutex.dir\main.cpp.obj
CreateMutex.exe: CMakeFiles\CreateMutex.dir\build.make
CreateMutex.exe: CMakeFiles\CreateMutex.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CreateMutex.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CreateMutex.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1433~1.316\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\CreateMutex.dir\objects1.rsp @<<
 /out:CreateMutex.exe /implib:CreateMutex.lib /pdb:C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug\CreateMutex.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CreateMutex.dir\build: CreateMutex.exe
.PHONY : CMakeFiles\CreateMutex.dir\build

CMakeFiles\CreateMutex.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CreateMutex.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CreateMutex.dir\clean

CMakeFiles\CreateMutex.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\bohda\CLionProjects\CreateMutex C:\Users\bohda\CLionProjects\CreateMutex C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug C:\Users\bohda\CLionProjects\CreateMutex\cmake-build-debug\CMakeFiles\CreateMutex.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\CreateMutex.dir\depend

