cmake_minimum_required(VERSION 3.0)

project(Parser)

set(CMAKE_CXX_STANDARD 17)

# generate *.cpp and *.hh files here for later use
BISON_TARGET(
    BisonCodeGen
    parser.y
    ${Parser_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${Parser_SOURCE_DIR}/parser.hh
)

# generate a *.cpp file here for later use
FLEX_TARGET(
    LexerCodeGen
    scanner.l
    ${Parser_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(
    LexerCodeGen
    BisonCodeGen
)

add_executable(
    ParserModule
    main.cpp
    driver.cpp
    ${FLEX_LexerCodeGen_OUTPUTS}
    ${BISON_BisonCodeGen_OUTPUTS}
)

target_include_directories(ParserModule PRIVATE ${Parser_SOURCE_DIR})
