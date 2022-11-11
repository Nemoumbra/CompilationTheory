%option noyywrap
%option c++
%option yyclass="Lexer"

%option debug


%{

/* this will be pasted in the resulting file */

#include <cstdio>
#include <iostream>
#include "TestCommands.h"
#include "lexer.hh"

/* pasted code end */

%}

%%

exit { return TOKEN_EXIT; }

.* { return TOKEN_ANYTHING; }

%%
