// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "bison-parser.tab.hh"


// Unqualified %code blocks.
#line 18 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:435

  namespace yy
  {
    // Return the next token.
    parser::symbol_type yylex (Parser & drv);
  }
#line 32 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:435

#include "parser.hpp"

#line 56 "bison-parser.tab.cc" // lalr1.cc:435


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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 151 "bison-parser.tab.cc" // lalr1.cc:510

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


  /// Build a parser object.
  parser::parser (Parser& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
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
    switch (that.type_get ())
    {
      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
  parser::yypop_ (int n)
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
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
    // State.
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
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
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

#line 559 "bison-parser.tab.cc" // lalr1.cc:919
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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -193;

  const short parser::yytable_ninf_ = -140;

  const short
  parser::yypact_[] =
  {
    1359,    63,   445,  -193,  -193,  -193,  -193,  -193,   220,   220,
     220,  -193,  -193,  -193,  -193,  -193,  -193,    27,  -193,  -193,
      -2,   445,  -193,     7,   -58,  1200,   -37,  -193,   -29,  -193,
    -193,   -57,  -193,  1335,  1049,   -24,  -193,  -193,  -193,    30,
    -193,  -193,  -193,    -9,  -193,  1245,     6,  1404,  -193,   158,
    -193,  -193,     9,    29,  -193,   771,   300,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  1082,  1102,  1102,  -193,  -193,
    -193,  -193,   579,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
     118,   382,  1049,  -193,   -56,     8,   208,    51,   211,    25,
      41,    26,   117,   -10,  -193,  -193,   -33,  -193,   109,   189,
     175,   163,  1404,   445,   134,  1290,  1404,  1155,  1359,  -193,
     718,   169,   250,  1049,   152,   171,   178,   187,   206,   218,
     241,   246,   804,  -193,  -193,   197,  -193,  -193,  -193,   384,
     252,  -193,   579,  -193,   579,  -193,  -193,   -19,   130,   247,
     -51,   323,  -193,  -193,   824,  1049,   324,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  1049,  -193,
    -193,  1049,  1049,  1049,  1049,  1049,  1049,  1049,  1049,  1049,
    1049,  1049,  1049,  1049,  1049,  1049,  1049,  1049,  1049,  1049,
    1049,  -193,  -193,   254,   257,     0,  1171,  -193,   261,  1290,
    -193,  -193,  -193,    99,   259,   251,  -193,   718,  1049,   332,
    -193,    40,   857,   115,  -193,  -193,   384,  -193,   255,   384,
    1049,  1049,  1049,   284,   468,  -193,  -193,  -193,   223,  -193,
    -193,  -193,   136,   139,  -193,   910,  -193,  -193,  -193,  -193,
      93,  -193,    -4,  -193,  -193,  -193,  -193,  -193,   -56,   -56,
       8,     8,   208,   208,   208,   208,    51,    51,   211,    25,
      41,    26,   117,    -5,  -193,  1049,   189,  -193,   276,  -193,
     274,  -193,   -24,  -193,   445,  -193,    98,   273,  -193,  -193,
     632,  -193,  -193,  -193,  -193,   384,  -193,   104,   132,   138,
     282,   526,   943,   943,  -193,   293,   293,   718,  -193,  1049,
    -193,  -193,  1049,  -193,  -193,  -193,  -193,  -193,  -193,   665,
    -193,  -193,  -193,   857,  -193,   384,   384,   384,  1049,   963,
     996,   156,  -193,  -193,  -193,  -193,   315,  -193,  -193,   165,
     384,   207,   384,   233,  -193,   685,   384,   299,  -193,   384,
    -193,   384,  -193,  -193,  -193,  -193,  -193
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    30,     0,     3,     2,    11,    12,    13,    14,     0,
       0,    15,    16,    18,    17,    19,    20,     0,     4,     5,
       6,     0,    26,     0,    29,     0,     0,   186,   143,   187,
     184,     0,   185,     0,     0,   136,   138,    30,    29,     0,
      10,     8,     9,     0,     7,     0,    25,     0,    37,    30,
      28,    27,   144,     0,    39,     0,     0,   182,   183,     1,
     188,    45,    42,    43,    44,     0,     0,     0,    40,    41,
      86,    81,     0,    80,    82,    83,    84,    85,    46,    50,
      74,    87,     0,    89,    93,    96,    99,   104,   107,   109,
     111,   113,   115,   117,   119,   132,     0,   137,     0,     0,
      30,     0,     0,     0,     0,     0,    21,     0,     0,   147,
       0,   140,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,   148,     0,   156,   153,   154,   170,
       0,   155,     0,    78,     0,    75,    76,    45,     0,    46,
       0,     0,    56,    57,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   121,     0,    87,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,    38,    31,    33,     0,     0,   146,     0,     0,
      23,    22,   178,   175,   176,     0,   145,     0,     0,     0,
      64,     0,     0,     0,    68,    62,     0,   134,     0,     0,
       0,     0,     0,     0,     0,   162,   161,   163,     0,   149,
     171,   173,     0,     0,    48,     0,    49,    47,    55,    52,
       0,    72,     0,    54,   120,    90,    91,    92,    94,    95,
      97,    98,   102,   103,   100,   101,   105,   106,   108,   110,
     112,   114,   116,     0,   133,     0,     0,    35,     0,   180,
       0,    24,   139,   174,     0,   179,     0,     0,    71,   141,
       0,    63,    67,    69,   150,     0,   152,     0,     0,     0,
       0,    45,     0,     0,   164,    79,     0,     0,    88,     0,
      53,    51,     0,    32,    34,    36,   181,   177,    60,     0,
      70,   142,    66,     0,   151,     0,     0,     0,     0,     0,
       0,     0,    73,   118,    61,    65,   160,   169,   157,     0,
       0,     0,     0,     0,    58,     0,     0,     0,   167,     0,
     165,     0,    59,   159,   158,   168,   166
  };

  const short
  parser::yypgoto_[] =
  {
    -193,  -193,    15,   304,  -193,   -12,    16,     1,  -193,   122,
    -193,  -193,   -52,  -193,  -193,  -189,  -192,  -124,  -193,   176,
    -193,   -14,  -193,   -32,   119,   149,   100,   148,   221,   205,
     216,   204,   219,  -193,  -111,  -101,  -193,   -34,  -186,  -193,
     361,   224,     4,   -22,    11,  -117,  -193,   -84,   269,   -25,
    -193,  -179,  -193,  -193,  -193
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    20,   103,    22,    23,   104,    38,   105,   184,   185,
      26,    27,    78,    79,    80,   200,   201,   202,   203,   204,
     230,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   158,   125,   208,    35,
      36,    28,    52,    53,   126,   127,   128,   129,   130,   131,
     194,   195,    31,    32,    33
  };

  const short
  parser::yytable_[] =
  {
      96,    25,   207,    39,    29,   266,    58,   260,   178,   205,
      46,    30,   267,   271,    56,    21,    24,   161,    48,    57,
     139,   111,    45,   101,   180,   -30,    25,   227,     3,     4,
      43,   162,   163,    98,    25,    44,    30,    60,   140,    54,
      21,    24,   180,   231,    30,    55,    25,   181,    21,    24,
     160,   133,   135,   136,   -30,    34,    30,   234,   106,   224,
      21,    24,    99,  -139,   168,   169,    18,    19,   159,   293,
     180,   180,   257,   138,    50,   258,   291,   102,    47,   254,
     139,   302,   139,   179,   108,   297,   196,   207,   218,   292,
     188,   164,   165,   213,   191,   311,   205,   283,   140,   159,
     140,   205,   262,    51,   189,   109,    25,   174,   193,    25,
     302,   232,   269,   106,   315,   270,    30,   106,   176,    30,
      21,    24,   274,    21,    24,   276,   141,   142,   143,   235,
     236,   237,   175,   222,   177,   223,   302,  -139,  -139,  -139,
     170,   171,    34,    50,   207,   253,   303,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   309,   310,   101,   289,   205,
     298,   290,    51,   299,    50,   303,   277,   278,   279,   180,
      50,   313,   305,    50,   159,   182,   205,   193,   312,   272,
      25,   304,   183,   288,   198,   144,   199,   145,   205,   146,
      30,   303,   205,    51,    21,    24,   190,   180,   225,    51,
     306,   159,    51,   180,   285,    25,   307,   286,   282,   166,
     167,   316,   317,   318,   205,    30,   172,   173,   324,    21,
      24,   325,  -139,  -139,  -139,   107,   328,    34,   330,   187,
     180,   159,   333,   327,   180,   335,   209,   336,   210,  -139,
    -139,  -139,   186,   -30,    34,   211,     5,     6,     7,     8,
       9,    10,    11,    12,   212,   193,    13,    14,   242,   243,
     244,   245,   180,   219,   319,   321,   323,    56,   159,   -30,
     -30,   -30,   180,   238,   239,   329,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   214,   -30,   -30,   180,   284,
     -30,   -30,   -30,   112,    62,    63,    64,    65,   180,    66,
      67,   331,    40,    41,    42,   240,   241,   215,   -30,   -30,
     246,   247,   216,   -30,   221,   226,   228,   233,   255,   265,
       3,     4,   256,   261,   264,   268,     5,     6,     7,     8,
       9,    10,    11,    12,   206,   280,    13,    14,   295,   275,
      15,    16,   296,   300,    68,    69,   113,   114,   115,   308,
     116,   117,   118,   119,   287,   120,   121,   122,    18,    19,
      70,    56,   123,    71,   326,   334,   124,    72,   294,   273,
     249,   251,    73,    74,    75,    76,    77,   112,    62,    63,
      64,    65,   250,    66,    67,   248,    97,   252,   220,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     3,     4,     0,   263,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,     0,     0,    15,    16,     0,     0,    68,    69,
     113,   114,   115,     0,   116,   117,   118,   119,    37,   120,
     121,   122,    18,    19,    70,    56,   157,    71,     0,     0,
     124,    72,     0,     0,     0,     0,    73,    74,    75,    76,
      77,   281,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,    13,    14,     0,     0,    15,    16,     2,     3,     4,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,    14,     0,     0,    15,    16,
      17,     0,    68,    69,     0,     0,     0,     0,     0,   -30,
    -139,  -139,  -139,  -139,     0,     0,    18,    19,    70,     0,
       0,    71,     0,     0,   124,    72,     0,     0,     0,     0,
      73,    74,    75,    76,    77,   -30,   -30,   -30,     0,     0,
       0,     0,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,     0,     0,   -30,   -30,   -30,     0,
    -139,  -139,   137,    62,    63,    64,    65,     0,    66,    67,
       0,     0,     0,     0,   -30,   -30,  -139,     0,     0,   -30,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,  -139,  -139,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,     0,     0,    15,
      16,     0,     0,    68,    69,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    70,
       0,     0,    71,     0,     0,     0,    72,     0,     0,     0,
       0,    73,    74,    75,    76,    77,     0,     0,    61,    62,
      63,    64,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    61,    62,
      63,    64,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,    70,   197,   301,    71,     0,     0,     0,    72,
       0,   198,     0,   199,    73,    74,    75,    76,    77,    68,
      69,    61,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     0,     0,     0,     0,    70,   197,   314,    71,    68,
      69,     0,    72,     0,   198,     0,   199,    73,    74,    75,
      76,    77,     0,     0,     0,    70,   197,   332,    71,     0,
       0,     0,    72,     0,   198,     0,   199,    73,    74,    75,
      76,    77,    68,    69,    61,    62,    63,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,    70,   197,
       0,    71,     0,     0,     0,    72,     0,   198,     0,   199,
      73,    74,    75,    76,    77,     0,     0,    61,    62,    63,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    61,    62,    63,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,    70,   110,     0,    71,     0,     0,     0,    72,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    68,    69,
      61,    62,    63,    64,    65,     0,    66,    67,     0,     0,
       0,     0,     0,     0,    70,     0,     0,    71,    68,    69,
     217,    72,     0,     0,     0,     0,    73,    74,    75,    76,
      77,     0,     0,     0,    70,     0,     0,    71,     0,     0,
       0,    72,   229,     0,     0,     0,    73,    74,    75,    76,
      77,    68,    69,    61,    62,    63,    64,    65,     0,    66,
      67,     0,     0,     0,     0,     0,     0,    70,   197,     0,
      71,     0,     0,     0,    72,     0,     0,     0,     0,    73,
      74,    75,    76,    77,     0,     0,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
      70,   287,     0,    71,     0,     0,     0,    72,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    68,    69,    61,
      62,    63,    64,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    70,     0,     0,    71,    68,    69,   124,
      72,     0,     0,     0,     0,    73,    74,    75,    76,    77,
       0,     0,     0,    70,     0,     0,    71,     0,     0,     0,
      72,   320,     0,     0,     0,    73,    74,    75,    76,    77,
      68,    69,    61,    62,    63,    64,    65,     0,    66,    67,
       0,     0,     0,     0,     0,     0,    70,     0,     0,    71,
       0,     0,     0,    72,   322,     0,     0,     0,    73,    74,
      75,    76,    77,     0,     0,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,    70,
       0,     0,    71,     0,     0,     0,    72,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,    71,    68,    69,    37,   132,
       0,     0,     0,     0,    73,    74,    75,    76,    77,     0,
       0,     0,    70,     0,    37,    71,     0,     0,     0,   134,
       0,     0,     0,     0,    73,    74,    75,    76,    77,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,    13,    14,    49,     0,    15,    16,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,    14,     0,
       0,    15,    16,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     0,   192,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    50,     0,    13,    14,   100,   259,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,    51,     2,     3,     4,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    50,
       0,    13,    14,     1,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,    51,     2,
       3,     4,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    50,    59,    13,    14,     1,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     1,    51,     2,     3,     4,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,    13,    14,     0,     0,    15,    16,    17,     2,     3,
       4,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    18,    19,    13,    14,    37,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,     0,     3,     4,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,     0,     0,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19
  };

  const short
  parser::yycheck_[] =
  {
      34,     0,   113,     2,     0,   197,    31,   186,    18,   110,
       3,     0,   198,   202,    71,     0,     0,    73,    76,    76,
      72,    55,    21,    45,    75,    44,    25,    78,    30,    31,
       3,    87,    88,     3,    33,    20,    25,    33,    72,    76,
      25,    25,    75,   144,    33,    74,    45,    80,    33,    33,
      82,    65,    66,    67,    73,    79,    45,   158,    47,    78,
      45,    45,    71,     0,    13,    14,    68,    69,    82,   255,
      75,    75,    72,    72,    44,    75,    80,    71,    71,   180,
     132,   270,   134,    93,    75,   264,   108,   198,   122,    94,
     102,    83,    84,   118,   106,   287,   197,   214,   132,   113,
     134,   202,     3,    73,   103,    76,   105,    82,   107,   108,
     299,   145,    72,   102,   303,    75,   105,   106,    92,   108,
     105,   105,   206,   108,   108,   209,     8,     9,    10,   161,
     162,   163,    91,   132,    17,   134,   325,    74,    75,    76,
      89,    90,    79,    44,   255,   179,   270,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   282,   283,   189,    75,   270,
      72,    78,    73,    75,    44,   299,   210,   211,   212,    75,
      44,   292,    78,    44,   198,    76,   287,   186,   289,    74,
     189,   275,     3,   225,    79,    77,    81,    79,   299,    81,
     189,   325,   303,    73,   189,   189,    72,    75,    78,    73,
      78,   225,    73,    75,    78,   214,    78,    78,   214,    11,
      12,   305,   306,   307,   325,   214,    15,    16,    72,   214,
     214,    75,    74,    75,    76,    77,   320,    79,   322,    76,
      75,   255,   326,    78,    75,   329,    94,   331,    77,    74,
      75,    76,    77,     3,    79,    77,    36,    37,    38,    39,
      40,    41,    42,    43,    77,   264,    46,    47,   168,   169,
     170,   171,    75,    76,   308,   309,   310,    71,   292,    29,
      30,    31,    75,   164,   165,    78,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    77,    46,    47,    75,    76,
      50,    51,    52,     3,     4,     5,     6,     7,    75,     9,
      10,    78,     8,     9,    10,   166,   167,    76,    68,    69,
     172,   173,    76,    73,    72,    78,     3,     3,    74,    78,
      30,    31,    75,    72,    75,     3,    36,    37,    38,    39,
      40,    41,    42,    43,    94,    61,    46,    47,    72,    94,
      50,    51,    78,    80,    54,    55,    56,    57,    58,    77,
      60,    61,    62,    63,    71,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    59,    76,    76,    77,   256,   203,
     175,   177,    82,    83,    84,    85,    86,     3,     4,     5,
       6,     7,   176,     9,    10,   174,    35,   178,   129,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    30,    31,    -1,   193,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,     3,    65,
      66,    67,    68,    69,    70,    71,    74,    73,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    50,    51,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    50,    51,
      52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    68,    69,    70,    -1,
      -1,    73,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    29,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    -1,    -1,    50,    51,    52,    -1,
      54,    55,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    82,    83,    84,    85,    86,    54,
      55,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    54,
      55,    -1,    77,    -1,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    82,    83,    84,
      85,    86,    54,    55,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    54,    55,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    54,    55,
      76,    77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    54,    55,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    54,    55,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    54,    55,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      54,    55,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    54,    55,     3,    77,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    70,    -1,     3,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,     3,    -1,    50,    51,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    78,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,     3,    78,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,    -1,    73,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,     3,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    73,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    46,    47,     3,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,     3,    73,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    50,    51,    52,    29,    30,
      31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    68,    69,    46,    47,     3,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    29,    30,    31,    36,    37,    38,    39,    40,
      41,    42,    43,    46,    47,    50,    51,    52,    68,    69,
      96,    97,    98,    99,   101,   102,   105,   106,   136,   137,
     139,   147,   148,   149,    79,   134,   135,     3,   101,   102,
      98,    98,    98,     3,    97,   102,     3,    71,    76,     3,
      44,    73,   137,   138,    76,    74,    71,    76,   144,     0,
     137,     3,     4,     5,     6,     7,     9,    10,    54,    55,
      70,    73,    77,    82,    83,    84,    85,    86,   107,   108,
     109,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   132,   135,     3,    71,
       3,   138,    71,    97,   100,   102,   139,    77,    75,    76,
      71,   132,     3,    56,    57,    58,    60,    61,    62,    63,
      65,    66,    67,    72,    76,   132,   139,   140,   141,   142,
     143,   144,    77,   116,    77,   116,   116,     3,   102,   107,
     132,     8,     9,    10,    77,    79,    81,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    74,   131,   116,
     118,    73,    87,    88,    83,    84,    11,    12,    13,    14,
      89,    90,    15,    16,    82,    91,    92,    17,    18,    93,
      75,    80,    76,     3,   103,   104,    77,    76,   100,   102,
      72,   100,    78,   102,   145,   146,   138,    71,    79,    81,
     110,   111,   112,   113,   114,   130,    94,   129,   133,    94,
      77,    77,    77,   144,    77,    76,    76,    76,   132,    76,
     143,    72,   102,   102,    78,    78,    78,    78,     3,    78,
     115,   130,   132,     3,   130,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   122,   122,   123,   124,
     125,   126,   127,   132,   130,    74,    75,    72,    75,    78,
     146,    72,     3,   136,    75,    78,   111,   133,     3,    72,
      75,   110,    74,   114,   142,    94,   142,   132,   132,   132,
      61,     3,   137,   140,    76,    78,    78,    71,   118,    75,
      78,    80,    94,   133,   104,    72,    78,   146,    72,    75,
      80,    72,   110,   112,   142,    78,    78,    78,    77,   140,
     140,   111,   130,   129,    72,   110,   142,   142,   142,   132,
      78,   132,    78,   132,    72,    75,    59,    78,   142,    78,
     142,    78,    72,   142,    76,   142,   142
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    95,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   111,   111,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   119,   120,   120,   120,   121,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   134,   135,   135,   136,   136,
     137,   137,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     147,   147,   148,   148,   137,   137,   137,   149,   149
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     5,     2,     1,     2,     2,     1,
       1,     1,     3,     1,     3,     5,     6,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     2,     1,
       3,     5,     6,     1,     1,     3,     4,     3,     1,     2,
       3,     4,     3,     1,     1,     1,     1,     5,     7,     7,
       5,     2,     2,     2,     3,     6,     7,     6,     7,     5,
       1,     2,     2,     3,     2,     1,     1,     3,     4,     5,
       5,     6,     2,     2,     1,     1,     1,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "IDENTIFIER", "INT_CONSTANT",
  "REAL_CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP",
  "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "BOOL", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS",
  "TRUE", "FALSE", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "EXPORT", "ASYNC",
  "AWAIT", "'{'", "'}'", "'*'", "'='", "','", "';'", "'('", "')'", "'['",
  "']'", "'.'", "'&'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "$accept", "linkage_modifier",
  "linkage_modifiers", "primitive_type", "struct_or_union",
  "struct_declaration_list", "struct_or_union_specifier", "type",
  "enum_member", "enum_members", "enum_specifier", "type_declaration",
  "literal", "primary_expression", "postfix_expression", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expr", "constexpr", "array_size_modifier", "array_size_modifiers",
  "scalar_or_array_name", "declaration", "declaration_list",
  "variable_declaration", "expression_statement", "labeled_statement",
  "statement", "statement_list", "block", "parameter", "parameter_list",
  "function_signature", "function_declaration", "translation_unit", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,    62,    62,    63,    64,    65,    69,    70,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    88,
      89,    93,    94,    98,    99,   100,   104,   105,   106,   107,
     108,   112,   113,   117,   118,   122,   123,   127,   128,   129,
     133,   134,   135,   136,   137,   141,   142,   143,   144,   145,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     163,   164,   165,   169,   170,   171,   172,   176,   180,   181,
     185,   186,   190,   191,   195,   196,   197,   198,   199,   200,
     205,   206,   207,   208,   209,   210,   211,   215,   216,   220,
     221,   222,   223,   227,   228,   229,   233,   234,   235,   239,
     240,   241,   242,   243,   247,   248,   249,   253,   254,   258,
     259,   263,   264,   268,   269,   273,   274,   278,   279,   283,
     284,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   302,   303,   307,   311,   315,   316,   320,   321,
     325,   326,   327,   328,   332,   333,   337,   338,   342,   343,
     347,   348,   349,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     373,   374,   378,   379,   383,   384,   388,   389,   393,   394,
     395,   396,   400,   401,   405,   406,   407,   411,   412
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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
#line 1422 "bison-parser.tab.cc" // lalr1.cc:1242
#line 414 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:1243


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

// Return the next token.
yy::parser::symbol_type yy::yylex (Parser & drv)
{
  return drv.get_next_token();
}

