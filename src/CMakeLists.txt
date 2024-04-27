cmake_minimum_required(VERSION 3.5)

project(CUSTOM_COMPILER)

set(CMAKE_CXX_STANDARD 17)

set(GENERATED_FOLDER ${PROJECT_SOURCE_DIR}/generated/)
set(GRAPH_FOLDER ${PROJECT_SOURCE_DIR}/parser-graph/)
set(INPUT_FOLDER ${PROJECT_SOURCE_DIR}/inputs/)

# I don't think Flex and Bison can create parent directories...
file(MAKE_DIRECTORY ${GENERATED_FOLDER})
file(MAKE_DIRECTORY ${GRAPH_FOLDER})

# generate *.cpp and *.hh files here for later use
BISON_TARGET(
    BisonCodeGen
    ${INPUT_FOLDER}/parser.y
    ${GENERATED_FOLDER}/parser.cpp
    COMPILE_FLAGS --graph=${GRAPH_FOLDER}/parser.gv
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
    grammar-entities/BreakStatement.cpp
    grammar-entities/ContinueStatement.cpp
    grammar-entities/AssertStatement.cpp
    
    grammar-entities/expressions/AddExpression.cpp
    grammar-entities/expressions/SubExpression.cpp
    grammar-entities/expressions/MultExpression.cpp
    grammar-entities/expressions/IntDivExpression.cpp
    grammar-entities/expressions/RemainderExpression.cpp
    grammar-entities/expressions/NumberExpression.cpp
    grammar-entities/expressions/IdentifierExpr.cpp
    grammar-entities/expressions/NestedExpression.cpp
    grammar-entities/expressions/EQExpression.cpp
    grammar-entities/expressions/NEExpression.cpp
    grammar-entities/expressions/LTExpression.cpp
    grammar-entities/expressions/GTExpression.cpp
    grammar-entities/expressions/GEQExpression.cpp
    grammar-entities/expressions/LEQExpression.cpp

    symbol-table/stack/symbol_table.cpp
    symbol-table/stack/visibility_checker.cpp

    visitors/PrintVisitor.cpp
    visitors/Interpreter.cpp
    visitors/VisibilityCheckVisitor.cpp
    visitors/BreakContinueVisitor.cpp

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
