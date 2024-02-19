// BISON grammar file with comments by Nemoumbra

// The C++ deterministic parser is selected using the skeleton directive ‘%skeleton "lalr1.cc"’

%skeleton "lalr1.cc"

// Require version "3.5" or higher of Bison
%require "3.5"

// I don't know what '%defines' does
%defines

// Next 2 directives are related to the fact that we use C++

// Request that symbols be handled as a whole (type, value, and possibly location) in the scanner.
%define api.token.constructor

// The symbols are defined with type names, special storage techniques are used to allow any kind of C++ object to be used.
%define api.value.type variant

// This lets us use the definitions like the following:
// %token <int> INT "integer"
// %token <std::string> STR "string"


// Here we'll issue runtime assertions to catch invalid uses: symbols must be constructed and destroyed properly.

// This option checks these constraints using RTTI
%define parse.assert

// Require parser instrumentation for tracing
%define parse.trace

// Control the generation of syntax error messages
// 'verbose' means that error messages report the unexpected token, and possibly the expected ones.
%define parse.error verbose

// Add a prefix 'TOK_' to the token names when generating their definition in the target language
%define api.token.prefix {TOK_}

// Generate the code for processing the locations
// This can be used to generate better error messages
%locations


// This code is inserted in the parser.hh file at the start
%code requires {
    #include <string>
    #include <memory>

    /* Forward declaration of classes in order to disable cyclic dependencies */
    class Scanner;
    class Driver;

    // Here we write forward declarations for all of our grammar rules classes
    #include "../forward_declarations.hh"
}

// This code is inserted in the parser.cpp file at the start
%code {
    #include "driver.hh"
    #include "location.hh"

    // Here we include all of our grammar rules files (including Program.hh)
    #include "includes_for_parser.hh"

    /* Force parser to use our custom function from */
    static yy::parser::symbol_type yylex(Scanner& scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

// Specify additional yylex argument declarations
%lex-param { Scanner &scanner }
%lex-param { Driver &driver }

// This gives us 'yy::parser::symbol_type yylex(Scanner &scanner, Driver &driver)'


// The following is added to the class 'yy::parser' as fields (and to the constructors, of couse)
// in the files parser.hh and parser.cpp
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }



%token
    END 0 "end of file"
    FUNC_MAIN "main"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"
    LPAREN "("
    RPAREN ")"
    LCURLY "{" 
    RCURLY "}" 
    SEMICOLON ";"
    COLON ":"
    DECLARE "decl"
    IF "if"
    ELSE "else"
    WHILE "while"
    BREAK "break"
    CONTINUE "continue"
    PRINT "print"
    ASSERT "assert"
    INT_TYPE "int_type"
    EQ "=="
    NE "!="
    LT "<"
    GT ">"
    GEQ ">="
    LEQ "<="
    <std::string> IDENTIFIER "identifier"
    <int> NUMBER "number"
;

// The format for tokens is:
// [<type>] name [number for enum] ["alias_name"]
// This makes a enum 'token_kind_type' in struct 'token' (parser.hh)

// Note: the actual enum values are formed by prefixing 'name' with 'api.token.prefix'
// In our case that makes TOK_END = 0, TOK_ASSIGN, ...

// Note: alias_name is called 'semantic type tag'

// For every token defined here bison makes a function
// 'static symbol_type make_{name}(args)' in file parser.hh

// Note: the prefix is not added to 'name' here
// Note: a variable of type 'type' is put into the symbol_type constructor and assigned a value in 'make_{name}(args)'




// %nterm is used to declare exclusively nonterminal symbols
%nterm <std::shared_ptr<Program>> unit
%nterm <std::shared_ptr<BaseExpression>> expression
%nterm <std::shared_ptr<Assignment>> assignment
%nterm <std::shared_ptr<Declaration>> declaration
%nterm <std::shared_ptr<Conditional>> conditional
%nterm <std::shared_ptr<Statements>> statements
%nterm <std::shared_ptr<Statement>> statement
%nterm <std::shared_ptr<CallToPrint>> call_to_print
%nterm <std::shared_ptr<PreLoop>> pre_loop
%nterm <std::shared_ptr<BreakStatement>> loop_break
%nterm <std::shared_ptr<ContinueStatement>> loop_continue
%nterm <std::shared_ptr<AssertStatement>> assertion




// The code in braces is called only if we enable trace_parsing

// After the braces we list symbol names which we write these logs for
// In this case it would have been for every symbol that has a semantic tag

//%printer { yyo << $$; } <*>;

// 'yyo' is an alias name for the output - in our case (C++) that's 'std::ostream&'
// $$ is a semantic value assiciated with the symbol
// @$ is the location of the symbol

// Note: there could be multiple %printer statements (for more detailed logs)




// Grammar info section is surrounded by %% from both sides
%%


// Associativity and relative precedence rules for operators in the language
// (These strings are semantic type tags)


%left "==" "!=";
%left "<" "<=" ">" ">=";
%left "+" "-";
%left "*" "/" "%";
// This means that 
// 1) All the operators listed here are left associative
// 2) '+' and '-' have equal precedence which is less than
// the precedence of '*', '/' and '%' (their precedence is also equal), etc.


// Specify the grammar’s start symbol

%start unit;
// Bison assumes by default that the start symbol for the grammar is
// the first nonterminal specified in the grammar specification section.
// This declaration overrides the restriction




// Now we define our grammar rules

// The syntax for defining a rule for an arbitrary nonterminal is 
// nonterminal_name : something {/* action code */}

// We can mention tokens by their semantic type tag and other nonterminals
// which have to be defined somewhere in this file.

// Using a pipe '|' allows to select either rule

// Note: the code is executed every time the rule is recognized


// Example:
// unit: assignments exp ";" { driver.result = $2; };
// $N refers to the semantic value of the semantic value of the Nth component of the rule
// Note: here we start counting from 1







unit: "main" "{" statements "}" {
    $$ = std::make_shared<Program>($3);
    driver.program = $$;
 }




statements:
    %empty { 
        $$ = std::make_shared<Statements>();
    }
    | statements statement {
        $1->AddStatement($2);
        $$ = $1;
    }

// The %empty directive allows to make explicit that a rule is empty on purpose instead of writing nothing




expression:
    "number" {
        $$ = std::make_shared<NumberExpression>($1);
    }
    | "identifier" {
        const auto loc = driver.locman.last_id;
        $$ = std::make_shared<IdentifierExpr>($1, loc);
    }
    | expression "+" expression {
        $$ = std::make_shared<AddExpression>($1, $3);
    }
    | expression "-" expression {
        $$ = std::make_shared<SubExpression>($1, $3);
    }
    | expression "*" expression {
        $$ = std::make_shared<MultExpression>($1, $3);
    }
    | expression "/" expression {
        $$ = std::make_shared<IntDivExpression>($1, $3);
    }
    | expression "%" expression {
        $$ = std::make_shared<RemainderExpression>($1, $3);
    }
    | expression "==" expression {
        $$ = std::make_shared<EQExpression>($1, $3);
    }
    | expression "!=" expression {
        $$ = std::make_shared<NEExpression>($1, $3);
    }
    | expression "<" expression {
        $$ = std::make_shared<LTExpression>($1, $3);
    }
    | expression ">" expression {
        $$ = std::make_shared<GTExpression>($1, $3);
    }
    | expression "<=" expression {
        $$ = std::make_shared<LEQExpression>($1, $3);
    }
    | expression ">=" expression {
        $$ = std::make_shared<GEQExpression>($1, $3);
    }
    | "(" expression ")" {
        $$ = std::make_shared<NestedExpr>($2);
    }
    ;





declaration:
    "decl" "identifier" ":" "int_type" ";" {
        $$ = std::make_shared<Declaration>($2);
    }


statement:
    assignment {
        $$ = $1;
    }
    | conditional {
        $$ = $1;
    }
    | pre_loop {
        $$ = $1;
    }
    | call_to_print {
        $$ = $1;
    }
    | declaration {
        $$ = $1;
    }
    | loop_break {
        $$ = $1;
    }
    | loop_continue {
        $$ = $1;
    }
    | assertion {
        $$ = $1;
    }
    


assignment:
    "identifier" "=" expression ";" {
        const auto loc = driver.locman.last_assign_id;
        $$ = std::make_shared<Assignment>($1, $3, loc);
     }


call_to_print:
    "print" "(" expression ")" ";" {
        $$ = std::make_shared<CallToPrint>($3);
    }


// I would really like to distinguish ints and bools, but let's just use C/C++ conversions (maybe for now)
conditional:
    "if" "(" expression ")" "{" statements "}" "else" "{" statements "}" {
        $$ = std::make_shared<Conditional>($3, $6, $10);
     }

pre_loop:
    "while" "(" expression ")" "{" statements "}" {
        $$ = std::make_shared<PreLoop>($3, $6);
    }

loop_break:
    "break" ";" {
        const auto loc = driver.locman.last_break_continue;
        $$ = std::make_shared<BreakStatement>(loc);
    }

loop_continue:
    "continue" ";" {
        const auto loc = driver.locman.last_break_continue;
        $$ = std::make_shared<ContinueStatement>(loc);
    }

assertion:
   "assert" "(" expression ")" ";" {
        const auto loc = driver.locman.last_assert;
        $$ = std::make_shared<AssertStatement>($3, loc);
   }


// Grammar info section is surrounded by %% from both sides
%%




// This code is pasted in the end of the parser.cpp file
void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
