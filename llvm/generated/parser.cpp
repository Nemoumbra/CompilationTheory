// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 57 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"

    #include "driver.hh"
    #include "location.hh"

    // Here we include all of our grammar rules files (including Program.hh)
    #include "includes_for_parser.hh"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner& scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 59 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 151 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"

  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< Assignment* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< BaseExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_base_statement: // base_statement
        value.YY_MOVE_OR_COPY< BaseStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_to_print: // call_to_print
        value.YY_MOVE_OR_COPY< CallToPrint* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cond_clause: // cond_clause
        value.YY_MOVE_OR_COPY< CondClause* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conditional: // conditional
        value.YY_MOVE_OR_COPY< Conditional* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.YY_MOVE_OR_COPY< Statements* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.move< Assignment* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< BaseExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_base_statement: // base_statement
        value.move< BaseStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_to_print: // call_to_print
        value.move< CallToPrint* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cond_clause: // cond_clause
        value.move< CondClause* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conditional: // conditional
        value.move< Conditional* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< Statements* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.copy< Assignment* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< BaseExpression* > (that.value);
        break;

      case symbol_kind::S_base_statement: // base_statement
        value.copy< BaseStatement* > (that.value);
        break;

      case symbol_kind::S_call_to_print: // call_to_print
        value.copy< CallToPrint* > (that.value);
        break;

      case symbol_kind::S_cond_clause: // cond_clause
        value.copy< CondClause* > (that.value);
        break;

      case symbol_kind::S_conditional: // conditional
        value.copy< Conditional* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.copy< Program* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.copy< Statement* > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.copy< Statements* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.move< Assignment* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< BaseExpression* > (that.value);
        break;

      case symbol_kind::S_base_statement: // base_statement
        value.move< BaseStatement* > (that.value);
        break;

      case symbol_kind::S_call_to_print: // call_to_print
        value.move< CallToPrint* > (that.value);
        break;

      case symbol_kind::S_cond_clause: // cond_clause
        value.move< CondClause* > (that.value);
        break;

      case symbol_kind::S_conditional: // conditional
        value.move< Conditional* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< Declaration* > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.move< Program* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.move< Statement* > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.move< Statements* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< Assignment* > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< BaseExpression* > ();
        break;

      case symbol_kind::S_base_statement: // base_statement
        yylhs.value.emplace< BaseStatement* > ();
        break;

      case symbol_kind::S_call_to_print: // call_to_print
        yylhs.value.emplace< CallToPrint* > ();
        break;

      case symbol_kind::S_cond_clause: // cond_clause
        yylhs.value.emplace< CondClause* > ();
        break;

      case symbol_kind::S_conditional: // conditional
        yylhs.value.emplace< Conditional* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case symbol_kind::S_unit: // unit
        yylhs.value.emplace< Program* > ();
        break;

      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< Statement* > ();
        break;

      case symbol_kind::S_statements: // statements
        yylhs.value.emplace< Statements* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // unit: "main" "{" statements "}"
#line 193 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                { 
    yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < Statements* > ());
    driver.program = yylhs.value.as < Program* > ();
 }
#line 789 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 3: // statements: %empty
#line 201 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
           { 
        yylhs.value.as < Statements* > () = new Statements();
    }
#line 797 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 4: // statements: statements base_statement
#line 204 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                { 
        yystack_[1].value.as < Statements* > ()->AddStatement(yystack_[0].value.as < BaseStatement* > ());
        yylhs.value.as < Statements* > () = yystack_[1].value.as < Statements* > ();
    }
#line 806 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 5: // expression: "number"
#line 211 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
             { 
        yylhs.value.as < BaseExpression* > () = new NumberExpression(yystack_[0].value.as < int > ());
    }
#line 814 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 6: // expression: "identifier"
#line 214 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                   {
        yylhs.value.as < BaseExpression* > () = new IdentifierExpr(yystack_[0].value.as < std::string > ());
    }
#line 822 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 7: // expression: expression "+" expression
#line 217 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new AddExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 830 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 8: // expression: expression "-" expression
#line 220 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new SubExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 838 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 9: // expression: expression "*" expression
#line 223 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new MultExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 846 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 10: // expression: expression "/" expression
#line 226 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new IntDivExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 854 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 11: // expression: expression "==" expression
#line 229 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                 {
        yylhs.value.as < BaseExpression* > () = new EQExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 862 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 12: // expression: expression "!=" expression
#line 232 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                 {
        yylhs.value.as < BaseExpression* > () = new NEExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 870 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 13: // expression: expression "<" expression
#line 235 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new LTExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 878 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 14: // expression: expression ">" expression
#line 238 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                {
        yylhs.value.as < BaseExpression* > () = new GTExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 886 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 15: // expression: expression "<=" expression
#line 241 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                 {
        yylhs.value.as < BaseExpression* > () = new LEQExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 894 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 16: // expression: expression ">=" expression
#line 244 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                 {
        yylhs.value.as < BaseExpression* > () = new GEQExpression(yystack_[2].value.as < BaseExpression* > (), yystack_[0].value.as < BaseExpression* > ());
    }
#line 902 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 17: // expression: "(" expression ")"
#line 247 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                         {
        yylhs.value.as < BaseExpression* > () = new NestedExpr(yystack_[1].value.as < BaseExpression* > ());
    }
#line 910 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 18: // base_statement: statement
#line 254 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
              { 
        yylhs.value.as < BaseStatement* > () = yystack_[0].value.as < Statement* > ();
    }
#line 918 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 19: // base_statement: declaration
#line 257 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                  { 
        yylhs.value.as < BaseStatement* > () = yystack_[0].value.as < Declaration* > ();
    }
#line 926 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 20: // declaration: "decl" "identifier" ":" "int_type" ";"
#line 274 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                           {
        yylhs.value.as < Declaration* > () = new Declaration(yystack_[3].value.as < std::string > ());
    }
#line 934 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 21: // statement: assignment
#line 279 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
               { 
        yylhs.value.as < Statement* > () = yystack_[0].value.as < Assignment* > ();
    }
#line 942 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 22: // statement: conditional
#line 282 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                  {
        yylhs.value.as < Statement* > () = yystack_[0].value.as < Conditional* > ();
    }
#line 950 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 23: // statement: call_to_print
#line 285 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                    {
        yylhs.value.as < Statement* > () = yystack_[0].value.as < CallToPrint* > ();
    }
#line 958 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 24: // assignment: "identifier" "=" expression ";"
#line 291 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                    { 
        yylhs.value.as < Assignment* > () = new Assignment(yystack_[3].value.as < std::string > (), yystack_[1].value.as < BaseExpression* > ());
        // driver.variables[$1] = $3->eval(driver);
     }
#line 967 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 25: // call_to_print: "print" "(" expression ")" ";"
#line 297 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                   {
        yylhs.value.as < CallToPrint* > () = new CallToPrint(yystack_[2].value.as < BaseExpression* > ());
    }
#line 975 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 26: // conditional: "if" "(" expression ")" "{" cond_clause "}" "else" "{" cond_clause "}"
#line 303 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                                                                           { 
        yylhs.value.as < Conditional* > () = new Conditional(yystack_[8].value.as < BaseExpression* > (), yystack_[5].value.as < CondClause* > (), yystack_[1].value.as < CondClause* > ());
     }
#line 983 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 27: // cond_clause: %empty
#line 308 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
           {
        yylhs.value.as < CondClause* > () = new CondClause();
    }
#line 991 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;

  case 28: // cond_clause: cond_clause statement
#line 311 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"
                            {
        yystack_[1].value.as < CondClause* > ()->AddStatement(yystack_[0].value.as < Statement* > ());
        yylhs.value.as < CondClause* > () = yystack_[1].value.as < CondClause* > ();
    }
#line 1000 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"
    break;


#line 1004 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -20;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -1,     4,    10,   -20,   -20,    88,   -20,     0,    25,    26,
      28,   -20,   -20,   -20,   -20,   -20,   -20,    41,    27,    27,
      27,    37,    27,   -20,   -20,    17,    23,    44,    49,    53,
      27,    27,    27,    27,    61,    27,    27,    27,    27,    27,
      27,    76,   -20,   -20,   -20,    63,    63,   -16,   -16,   -20,
      74,    74,    74,    74,    74,    74,   -20,    89,    73,   -20,
      80,   -20,   100,   -20
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     2,     0,     0,     0,
       0,     4,    19,    18,    21,    23,    22,     0,     0,     0,
       0,     0,     0,     6,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    20,    17,     8,     7,     9,    10,    27,
      11,    12,    13,    14,    16,    15,    25,     0,     0,    28,
       0,    27,     0,    26
  };

  const signed char
  parser::yypgoto_[] =
  {
     -20,   -20,   -20,   -19,   -20,   -20,    87,   -20,   -20,   -20,
      32
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     5,    25,    11,    12,    59,    14,    15,    16,
      57
  };

  const signed char
  parser::yytable_[] =
  {
      26,    27,     1,    29,    35,    36,    37,    38,    39,    40,
       4,    45,    46,    47,    48,     3,    50,    51,    52,    53,
      54,    55,    30,    31,    32,    33,    17,    34,    30,    31,
      32,    33,    20,    41,    18,    19,    22,    35,    36,    37,
      38,    39,    40,    35,    36,    37,    38,    39,    40,    30,
      31,    32,    33,    23,    24,    21,    28,    42,    30,    31,
      32,    33,    43,    44,    35,    36,    37,    38,    39,    40,
      32,    33,    49,    35,    36,    37,    38,    39,    40,    30,
      31,    32,    33,    35,    36,    37,    38,    39,    40,    56,
      60,    61,    13,    62,    35,    36,    37,    38,    39,    40,
       6,    58,     0,     7,     8,     8,     9,     9,     0,     0,
       0,     0,    63,     0,    10,    10,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,    10
  };

  const signed char
  parser::yycheck_[] =
  {
      19,    20,     3,    22,    20,    21,    22,    23,    24,    25,
       0,    30,    31,    32,    33,    11,    35,    36,    37,    38,
      39,    40,     5,     6,     7,     8,    26,    10,     5,     6,
       7,     8,     4,    10,     9,     9,     9,    20,    21,    22,
      23,    24,    25,    20,    21,    22,    23,    24,    25,     5,
       6,     7,     8,    26,    27,    14,    19,    13,     5,     6,
       7,     8,    13,    10,    20,    21,    22,    23,    24,    25,
       7,     8,    11,    20,    21,    22,    23,    24,    25,     5,
       6,     7,     8,    20,    21,    22,    23,    24,    25,    13,
      17,    11,     5,    61,    20,    21,    22,    23,    24,    25,
      12,    12,    -1,    15,    16,    16,    18,    18,    -1,    -1,
      -1,    -1,    12,    -1,    26,    26,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    29,    11,     0,    30,    12,    15,    16,    18,
      26,    32,    33,    34,    35,    36,    37,    26,     9,     9,
       4,    14,     9,    26,    27,    31,    31,    31,    19,    31,
       5,     6,     7,     8,    10,    20,    21,    22,    23,    24,
      25,    10,    13,    13,    10,    31,    31,    31,    31,    11,
      31,    31,    31,    31,    31,    31,    13,    38,    12,    34,
      17,    11,    38,    12
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    28,    29,    30,    30,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    32,    32,
      33,    34,    34,    34,    35,    36,    37,    38,    38
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     4,     0,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       5,     1,     1,     1,     4,     5,    11,     0,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"main\"", "\"=\"",
  "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"",
  "\";\"", "\":\"", "\"decl\"", "\"if\"", "\"else\"", "\"print\"",
  "\"int_type\"", "\"==\"", "\"!=\"", "\"<\"", "\">\"", "\">=\"", "\"<=\"",
  "\"identifier\"", "\"number\"", "$accept", "unit", "statements",
  "expression", "base_statement", "declaration", "statement", "assignment",
  "call_to_print", "conditional", "cond_clause", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   193,   193,   201,   204,   211,   214,   217,   220,   223,
     226,   229,   232,   235,   238,   241,   244,   247,   254,   257,
     274,   279,   282,   285,   291,   297,   303,   308,   311
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1518 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/generated//parser.cpp"

#line 319 "/home/nickolay/MIPT/3_semester/compile_theory/CompilationTheory/llvm/inputs//parser.y"


// This code is pasted in the end of the parser.cpp file
void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
