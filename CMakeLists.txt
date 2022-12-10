cmake_minimum_required(VERSION 3.0)
project(CompilerTheory)


# request that we have flex and bison installed
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# this is where our executables will end up
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CompilerTheory_SOURCE_DIR}/bin)

# recursively run CMake on folders:
# add_subdirectory(scanner-only)
# add_subdirectory(parser)
# add_subdirectory(ast-parser)
add_subdirectory(llvm)