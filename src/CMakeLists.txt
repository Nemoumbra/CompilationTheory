cmake_minimum_required(VERSION 3.5)

project(CUSTOM_COMPILER)

set(CMAKE_CXX_STANDARD 17)

set(GENERATED_FOLDER ${PROJECT_SOURCE_DIR}/generated/)
set(INPUT_FOLDER ${PROJECT_SOURCE_DIR}/inputs/)

# generate *.cpp and *.hh files here for later use
BISON_TARGET(
    BisonCodeGen
    ${INPUT_FOLDER}/parser.y
    ${GENERATED_FOLDER}/parser.cpp
    COMPILE_FLAGS --graph=${CUSTOM_COMPILER_SOURCE_DIR}/parser-graph/parser.gv
    DEFINES_FILE ${GENERATED_FOLDER}/parser.hh
)

# generate a *.cpp file here for later use
FLEX_TARGET(
    LexerCodeGen
    ${INPUT_FOLDER}/scanner.l
    ${GENERATED_FOLDER}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(
    LexerCodeGen
    BisonCodeGen
)

include_directories(${GENERATED_FOLDER})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

add_executable(
    CustomCompiler

    main.cpp
    driver.cpp
    ${FLEX_LexerCodeGen_OUTPUTS}
    ${BISON_BisonCodeGen_OUTPUTS}
    utils/utils.cpp
    utils/location_manager.cpp

    grammar-entities/Statements.cpp
    grammar-entities/Declaration.cpp
    grammar-entities/Conditional.cpp
    grammar-entities/PreLoop.cpp
    grammar-entities/CallToPrint.cpp
    grammar-entities/Assignment.cpp
    
    grammar-entities/expressions/AddExpression.cpp
    grammar-entities/expressions/SubExpression.cpp
    grammar-entities/expressions/MultExpression.cpp
    grammar-entities/expressions/IntDivExpression.cpp
    grammar-entities/expressions/NumberExpression.cpp
    grammar-entities/expressions/IdentifierExpr.cpp
    grammar-entities/expressions/NestedExpression.cpp
    grammar-entities/expressions/EQExpression.cpp
    grammar-entities/expressions/NEExpression.cpp
    grammar-entities/expressions/LTExpression.cpp
    grammar-entities/expressions/GTExpression.cpp
    grammar-entities/expressions/GEQExpression.cpp
    grammar-entities/expressions/LEQExpression.cpp

    symbol-table/symbol_table.cpp
    symbol-table/visibility_checker.cpp

    visitors/PrintVisitor.cpp
    visitors/Interpreter.cpp
    visitors/SymbolTableVisitor.cpp

    Program.cpp
)

target_include_directories(
    CustomCompiler PRIVATE ${CUSTOM_COMPILER_SOURCE_DIR}
)


add_custom_target(
    DrawAutomaton
    COMMAND dot -Tpng ${CUSTOM_COMPILER_SOURCE_DIR}/parser-graph/parser.gv -o ${CUSTOM_COMPILER_SOURCE_DIR}/parser-graph/parser.png
    COMMENT Generate the PNG graph image
    DEPENDS ${GENERATED_FOLDER}/parser.cpp
)
