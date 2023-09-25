cmake_minimum_required(VERSION 3.5)
project(CompilerTheory)


# Request that we have flex and bison installed
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# This is where our executables will end up
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CompilerTheory_SOURCE_DIR}/bin)

# Recursively run CMake on folders:
add_subdirectory(src)
