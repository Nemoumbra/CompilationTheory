// BISON grammar file with comments by Nemoumbra

// The C++ deterministic parser is selected using the skeleton directive ‘%skeleton "lalr1.cc"’

%skeleton "lalr1.cc"

// Require version "3.5" or higher of Bison
%require "3.5"

// I don't know what '%defines' does
%defines
string
// Next 2 directives are related to the fact that we use C++

// Request that symbols be handled as a whole (type, value, and possibly location) in the scanner.
%define api.token.constructor

// The symbols are defined with type names, special storage techniques are used to allow any kind of C++ object to be used.
%define api.value.type variant

// This lets us use the definitions like the following:
// %token <int> INT "integer"
// %token <std::string> STR "string"


// OLD COMMENT: Issue runtime assertions to catch invalid uses: symbols must be constructed and destroyed properly.

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
    /* Forward declaration of classes in order to disable cyclic dependencies */
    class Scanner;
    class Driver;
}

// This code is inserted in the parser.cpp file at the start
%code {
    #include "driver.hh"
    #include "location.hh"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

// Specify additional yylex argument declarations
%lex-param { Scanner &scanner }
// we get 'yy::parser::symbol_type yylex(Scanner &scanner)'

// In parser.hh and parser.cpp these are added as fields to class 'yy::parser'
// (and to the constructor as well)
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
    LPAREN "("
    RPAREN ")"
    LCURLY "{" 
    RCURLY "}" 
    SEMICOLON ";"
    COLON ":"
    DECLARE "decl"
    IF "if"
    ELSE "else"
    PRINT "print"
    INT_TYPE "int_type"
    EQ "=="
    <std::string> IDENTIFIER "identifier"
    <int> NUMBER "number"
;

// The format for tokens is:
// [<type>] name [number for enum] ["alias_name"]
// This makes a enum 'token_kind_type' in struct 'token' (parser.hh)
// Note: the actual enum values are formed by prefixing 'name' with 'api.token.prefix'
// In our case that makes TOK_END = 0, TOK_ASSIGN, ...
// alias_name is called 'semantic type tag'

// For every token with name 'name' defined here bison makes a function
// 'static symbol_type make_name(args)' in file parser.hh
// Note: the prefix is not added to 'name' here
// Note: a variable of type 'type' is put into the symbol_type constructor
// and is assigned a value in 'make_name(args)'



// To declare exclusively nonterminal symbols
%nterm <int> expression


// OLD COMMENT: "Prints output in parsing option for debugging location terminal"

// The code in braces is called only if we enable trace_parsing
// After the braces we list symbol names which we write these logs for
// In this case it's for every symbol that has a semantic tag

%printer { yyo << $$; } <*>;

// 'yyo' is an alias name for the output - in our case (C++) that's 'std::ostream&'
// $$ is a semantic value assiciated with the symbol
// @$ is the location of the symbol

// Note: there could be multiple %printer statements (for more detailed logs)


// Grammar info section is surrounded by %% from both sides
%%



// Associativity and relative precedence rules for operators in the language
// (These strings are semantic type tags)

// %doesn't matter "=="
%left "+" "-";
%left "*" "/";
// This means that 
// 1) '+', '-', '*' and '/' are left associative
// 2) '+' and '-' have equal precedence which is less than
// the precedence of '*' and '/' (their precedence is also equal)


// Specify the grammar’s start symbol

%start unit;
// Bison assumes by default that the start symbol for the grammar
// the first nonterminal specified in the grammar specification section.
// This declaration overrides the restriction


// Now we define our grammar rules
// The syntax for defining a rule for some nonterminal is 
// nonterminal_name : something {/* action code */}
// We can mention tokens by their semantic type tag and other nonterminals
// which have to be defined somewhere in this file.
// Using a pipe '|' allows to select either rule
// Note: the code is executed every time the rule is recognized

// unit: assignments exp ";" { driver.result = $2; };
// $N refers to the semantic value of the semantic value of the Nth component of the rule
// Note: here we start counting from 1

unit: "main" "{" statements "}" { /* code */ }

// The %empty directive allows to make explicit that a rule is empty on purpose instead of writing nothing
// assignments:
//    %empty {}
//    | assignments assignment {};


statements:
    %empty { /* code */ }
    | statements statement { /* code */ }
    | statements declaration { /* code */ }


//assignment:
//   "identifier" ":=" expression ";" {
//        driver.variables[$1] = $3;
//        if (driver.location_debug) {
//            std::cerr << driver.location << std::endl;
//       }
//    }
//    | error ";" {
//    	// Hint for compilation error, resuming producing messages
//    	std::cerr << "You should provide assignment in the form: variable := expression ; " << std::endl;
//    };

declaration:
    "decl" "identifier" ":" "int_type" ";" { /* code */ }

statement:
    assignment { /* code */ }
    | conditional { /* code */ }
    | call_to_print { /* code */ }
    

assignment:
    "identifier" "=" expression ";" { /* code */ }

call_to_print:
    "print" "(" expression ")" ";" { /* code */ }

conditional:
    "if" "(" expression "==" expression ")" "{" cond_clause "}" "else" "{" cond_clause "}" { /* code */ }

cond_clause:
    %empty { /* code */ }
    | cond_clause statement { /* code */ }

expression:
    "number" { /* code */ }
    | "identifier" {$$ = driver.variables[$1];}
    | expression "+" expression {$$ = $1 + $3; }
    | expression "-" expression {$$ = $1 - $3; }
    | expression "*" expression {$$ = $1 * $3; }
    | expression "/" expression {$$ = $1 / $3; }
    | "(" expression ")" {$$ = $2; };


// Grammar info section is surrounded by %% from both sides
%%

// This code is pasted in the end of the parser.cpp file
void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
