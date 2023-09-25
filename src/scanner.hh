#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Scanner::ScanToken()
// Here we use not int, but a different return type

// BisonGodeGen file
#include "generated/parser.hh"

class Driver; // forward declaration of the class declared in driver.hh and defined in driver.cpp

class Scanner: public yyFlexLexer {
 public:
    Driver& driver;

    Scanner(Driver& driver): driver(driver) {}
	virtual ~Scanner() {}
    
	virtual yy::parser::symbol_type ScanToken();
    void UpdateLocation();
};