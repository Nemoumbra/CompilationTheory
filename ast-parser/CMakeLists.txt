cmake_minimum_required(VERSION 3.0)

project(AST_PARSER)

set(CMAKE_CXX_STANDARD 17)

# generate *.cpp and *.hh files here for later use
BISON_TARGET(
    BisonCodeGen
    parser.y
    ${AST_PARSER_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${AST_PARSER_SOURCE_DIR}/parser.hh
)

# generate a *.cpp file here for later use
FLEX_TARGET(
    LexerCodeGen
    scanner.l
    ${AST_PARSER_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(
    LexerCodeGen
    BisonCodeGen
)

add_executable(
    ASTParserModule

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

    Program.cpp
)

target_include_directories(ASTParserModule PRIVATE ${AST_PARSER_SOURCE_DIR})


add_custom_target(
    VisitorTree
    COMMAND dot -Tpng ${AST_PARSER_SOURCE_DIR}/parser.gv -o ${AST_PARSER_SOURCE_DIR}/ast-parser.png

    DEPENDS ${AST_PARSER_SOURCE_DIR}/parser.cpp
)

add_dependencies(ASTParserModule VisitorTree)
