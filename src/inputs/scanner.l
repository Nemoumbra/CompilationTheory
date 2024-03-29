
/* Flex lexer file with comments by Nemoumbra */
/* Unfortunately, the comments end up in the scanner.cpp file */
%option noyywrap nounput noinput batch debug
/* These options are hard to explain so far... */

/* Specifies that you want flex to generate a C++ scanner class  */
%option c++

/* This is how we want to class to be called */
%option yyclass="Scanner"

/* This code is pasted after the automaton is defined */
%{
    
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"

  // A symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    yy::parser::location_type& loc
  );

  // This function is called to get the correct error (and, maybe, debug) messages 
  void Scanner::UpdateLocation() {
    driver.locman.move_forward(yyleng);

    // We basically move the location 'yyleng' chars forward
    // ('yyleng' is something like 'yytext.size()')
  }

  // Code run each time a pattern is matched.
  #define YY_USER_ACTION UpdateLocation();
%}

/* These are user-defined aliases for regular expressions */
id    [a-zA-Z][a-zA-Z_0-9]*
int   -?[0-9]+
blank [ \t\r]
assign =
comment \/\/.*?\n


/* This starts the token definition section */
%%

%{
  // This code will be pasted into the scanner function 'yylex'
  // In our case it'll be defined as 'ScanToken'

  // To be honest, here I don't want to do anything

  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.locman.current;

  loc.step();
%}

  /* Note: comments here should be preceded by whitespace chars (I chose tabulation) */
  /* Every token is defined by a regular expression and the code */
  /* we want to run whenever it is matched by our scanner */

{blank}+   {
    loc.step();
    // This moves 'begin' onto 'end'
}

\n+ {
    loc.lines(yyleng);
    // The length of this token is the number of new lines =>
    // => we adjust the height of the location

    loc.step();
}

{comment}  {
    loc.step();
    loc.lines(1);
}


  /* These function are generated by BISON */
"func main()" return yy::parser::make_FUNC_MAIN(loc);
"-"           return yy::parser::make_MINUS(loc);
"+"           return yy::parser::make_PLUS(loc);
"*"           return yy::parser::make_STAR(loc);
"/"           return yy::parser::make_SLASH(loc);
"%"           return yy::parser::make_PERCENT(loc);
"("           return yy::parser::make_LPAREN(loc);
")"           return yy::parser::make_RPAREN(loc);
"{"           return yy::parser::make_LCURLY(loc);
"}"           return yy::parser::make_RCURLY(loc);
{assign}      return yy::parser::make_ASSIGN(loc);
";"           return yy::parser::make_SEMICOLON(loc);
":"           return yy::parser::make_COLON(loc);
"declare"     return yy::parser::make_DECLARE(loc);
"if"          return yy::parser::make_IF(loc);
"else"        return yy::parser::make_ELSE(loc);
"while"       return yy::parser::make_WHILE(loc);
"break"       return yy::parser::make_BREAK(loc);
"continue"    return yy::parser::make_CONTINUE(loc);
"print"       return yy::parser::make_PRINT(loc);
"assert"      return yy::parser::make_ASSERT(loc);
"int"         return yy::parser::make_INT_TYPE(loc);
"=="          return yy::parser::make_EQ(loc);
"!="          return yy::parser::make_NE(loc);
"<"           return yy::parser::make_LT(loc);
">"           return yy::parser::make_GT(loc);
"<="          return yy::parser::make_LEQ(loc);
">="          return yy::parser::make_GEQ(loc);


  /* The next one is a little tricky: it's not the 'static symbol_type make_NUMBER (int v, location_type l)' */
  /* made by BISON, this is our function declared above: */
  /* 'yy::parser::symbol_type make_NUMBER(const std::string &s, const yy::parser::location_type& loc)' */

  /* 'yytext' is a pointer to the current symbol in the input file, so we call strtol(s.c_str(), NULL, 10) */
  /* to make an integer from this offset and only then call the bison-made make_NUMBER */
  /* Note: the definition can be found after the %% section */

{int}         return make_NUMBER(yytext, loc);


  /* Here we create identifiers */
{id}       {
              return yy::parser::make_IDENTIFIER(yytext, loc);

              // When we pass yytext here, a copy std::string is made from it.
              // Note: 'yytext' is the temporary storage that holds the matched string

              // In the yy::parser::make_IDENTIFIER function we return the result of symbol_type's constructor

              // 'symbol_type' is derived from 'basic_symbol<by_kind>' which is typedefed as 'super_type'
           }

  /* This is how you can throw a syntax error (in this case we for some reason hate dots) */

  /* .          { */
  /*             throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext)); */
  /*         } */

<<EOF>>    return yy::parser::make_END (loc);

%%
/* This ends the token definition section */



/* And here we have the definition of the function discussed above */
yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);

  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE)) {
    loc.columns(1);
    throw yy::parser::syntax_error(
      loc, "Integer is out of range: " + s
    );
  }
  
  return yy::parser::make_NUMBER((int) n, loc);
}