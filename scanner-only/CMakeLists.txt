cmake_minimum_required(VERSION 3.0)

project(Scanner)

set(CMAKE_CXX_STANDARD 17)

# generate a *.cpp file here for later use
FLEX_TARGET(LexerCodeGen, lexer.l, ${Lexer_SOURCE_DIR}/lexer.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# specify files which need to be compiled and built into a binary
add_executable(
    Scanner.out,
    main.cpp,
    ${FLEX_LexerCodeGen_OUTPUTS}  # the file lexer generated
)