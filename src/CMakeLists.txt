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

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(
    CustomCompiler

    main.cpp
    driver.cpp
    ${FLEX_LexerCodeGen_OUTPUTS}
    ${BISON_BisonCodeGen_OUTPUTS}

    # grammar-entities/BaseStatement.cpp
    grammar-entities/Statements.cpp
    # grammar-entities/Statement.cpp
    grammar-entities/Declaration.cpp
    grammar-entities/Conditional.cpp
    grammar-entities/CondClause.cpp
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

    visitors/PrintVisitor.cpp
    visitors/Interpreter.cpp
    visitors/IrGeneratorVisitor.cpp

    Program.cpp
)

target_include_directories(
    CustomCompiler PRIVATE ${CUSTOM_COMPILER_SOURCE_DIR}
)

target_link_libraries(
    CustomCompiler
    LLVM-16
)

add_custom_target(
    DrawAutomaton
    COMMAND dot -Tpng ${CUSTOM_COMPILER_SOURCE_DIR}/parser-graph/parser.gv -o ${CUSTOM_COMPILER_SOURCE_DIR}/parser-graph/parser.png
    COMMENT Generate the PNG graph image
    DEPENDS ${GENERATED_FOLDER}/parser.cpp
)
