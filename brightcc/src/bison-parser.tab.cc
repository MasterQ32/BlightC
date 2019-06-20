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
#line 19 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:435

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


  const short parser::yypact_ninf_ = -234;

  const short parser::yytable_ninf_ = -139;

  const short
  parser::yypact_[] =
  {
    1336,     7,   444,  -234,  -234,  -234,  -234,  -234,   220,   220,
     220,  -234,  -234,  -234,  -234,  -234,  -234,    41,  -234,  -234,
     148,   444,  -234,    30,   -49,  1177,   -12,  -234,    -8,  -234,
    -234,   -28,  -234,  1312,  1048,   -17,  -234,  -234,  -234,    16,
    -234,  -234,  -234,     3,  -234,  1222,    19,  1381,  -234,   159,
    -234,  -234,    21,    28,  -234,   770,   299,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  1081,  1101,  1101,  -234,  -234,
    -234,   578,  -234,  -234,  -234,  -234,  -234,  -234,  -234,   132,
     379,  1048,  -234,   107,   -66,    43,    27,   158,    32,    38,
      47,   118,    -9,  -234,  -234,    -4,  -234,    61,   140,   236,
      69,  1381,   444,    92,  1267,  1381,   606,  1336,  -234,   717,
     115,   249,  1048,    88,   119,   121,   151,   133,   155,   116,
     165,   803,  -234,  -234,   207,  -234,  -234,  -234,   383,   136,
    -234,   578,  -234,   578,  -234,  -234,   -15,    49,   169,    45,
     240,  -234,  -234,   823,  1048,   262,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  1048,  -234,  -234,
    1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,
    1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,  1048,
    -234,  -234,   175,   197,   109,  1154,  -234,   204,  1267,  -234,
    -234,  -234,    29,   223,   229,  -234,   717,  1048,   311,  -234,
     131,   856,   145,  -234,  -234,   383,  -234,   234,   383,  1048,
    1048,  1048,   283,   467,  -234,  -234,  -234,   256,  -234,  -234,
    -234,    94,   127,  -234,   909,  -234,  -234,  -234,  -234,   147,
    -234,    31,  -234,  -234,  -234,  -234,  -234,   107,   107,   -66,
     -66,    43,    43,    43,    43,    27,    27,   158,    32,    38,
      47,   118,   -63,  -234,  1048,   140,  -234,   275,  -234,   270,
    -234,   -17,  -234,   444,  -234,   167,   278,  -234,  -234,   631,
    -234,  -234,  -234,  -234,   383,  -234,   170,   176,   206,   286,
     525,   942,   942,  -234,   298,   298,   717,  -234,  1048,  -234,
    -234,  1048,  -234,  -234,  -234,  -234,  -234,  -234,   664,  -234,
    -234,  -234,   856,  -234,   383,   383,   383,  1048,   962,   995,
     222,  -234,  -234,  -234,  -234,   314,  -234,  -234,   241,   383,
     245,   383,   246,  -234,   684,   383,   301,  -234,   383,  -234,
     383,  -234,  -234,  -234,  -234,  -234
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    30,     0,     3,     2,    11,    12,    13,    14,     0,
       0,    15,    16,    18,    17,    19,    20,     0,     4,     5,
       6,     0,    26,     0,    29,     0,     0,   185,   142,   186,
     183,     0,   184,     0,     0,   135,   137,    30,    29,     0,
      10,     8,     9,     0,     7,     0,    25,     0,    37,    30,
      28,    27,   143,     0,    39,     0,     0,   181,   182,     1,
     187,    45,    42,    43,    44,     0,     0,     0,    40,    41,
      81,     0,    80,    82,    83,    84,    85,    46,    50,    74,
      86,     0,    88,    92,    95,    98,   103,   106,   108,   110,
     112,   114,   116,   118,   131,     0,   136,     0,     0,    30,
       0,     0,     0,     0,     0,    21,     0,     0,   146,     0,
     139,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   147,     0,   155,   152,   153,   169,     0,
     154,     0,    78,     0,    75,    76,    45,     0,    46,     0,
       0,    56,    57,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   120,     0,    86,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,    38,    31,    33,     0,     0,   145,     0,     0,    23,
      22,   177,   174,   175,     0,   144,     0,     0,     0,    64,
       0,     0,     0,    68,    62,     0,   133,     0,     0,     0,
       0,     0,     0,     0,   161,   160,   162,     0,   148,   170,
     172,     0,     0,    48,     0,    49,    47,    55,    52,     0,
      72,     0,    54,   119,    89,    90,    91,    93,    94,    96,
      97,   101,   102,    99,   100,   104,   105,   107,   109,   111,
     113,   115,     0,   132,     0,     0,    35,     0,   179,     0,
      24,   138,   173,     0,   178,     0,     0,    71,   140,     0,
      63,    67,    69,   149,     0,   151,     0,     0,     0,     0,
      45,     0,     0,   163,    79,     0,     0,    87,     0,    53,
      51,     0,    32,    34,    36,   180,   176,    60,     0,    70,
     141,    66,     0,   150,     0,     0,     0,     0,     0,     0,
       0,    73,   117,    61,    65,   159,   168,   156,     0,     0,
       0,     0,     0,    58,     0,     0,     0,   166,     0,   164,
       0,    59,   158,   157,   167,   165
  };

  const short
  parser::yypgoto_[] =
  {
    -234,  -234,     5,   317,  -234,   -85,    24,     1,  -234,   123,
    -234,  -234,   -56,  -234,  -234,  -133,  -192,  -233,  -234,   172,
    -234,   -14,  -234,   -36,    57,   168,   101,   180,   218,   205,
     219,   221,   203,  -234,   -84,  -101,  -234,   -34,  -184,  -234,
     360,   216,     2,   -22,    14,  -202,  -234,   -75,   268,   -25,
    -234,  -175,  -234,  -234,  -234
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    20,   102,    22,    23,   103,    38,   104,   183,   184,
      26,    27,    77,    78,    79,   199,   200,   201,   202,   203,
     229,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   157,   124,   207,    35,
      36,    28,    52,    53,   125,   126,   127,   128,   129,   130,
     193,   194,    31,    32,    33
  };

  const short
  parser::yytable_[] =
  {
      95,    25,    29,    39,   265,    21,    58,  -138,   204,   177,
     259,   282,   179,   266,    30,   138,   187,   163,   164,    97,
     190,   110,    45,   100,    24,    44,    25,    48,   206,   -30,
      21,   291,   261,    46,    25,    60,   302,   139,    21,    30,
     167,   168,   230,    56,    43,   159,    25,    30,    57,    24,
      21,   132,   134,   135,   165,   166,   233,    24,   -30,    30,
      50,   105,    34,   223,    54,   302,    55,   158,   270,    24,
     292,   179,   137,    50,    98,   138,   180,   138,   253,   308,
     309,  -138,  -138,  -138,   178,   195,    34,   217,   296,    51,
     101,   302,   212,    50,   310,   204,   107,   139,   158,   139,
     204,    47,    51,   188,   108,    25,   179,   192,    25,    21,
     231,   290,    21,   206,   173,   105,   169,   170,    30,   105,
     179,    30,    51,   226,   234,   235,   236,   224,    24,   174,
     273,    24,   221,   275,   222,   176,   301,   181,    50,   175,
     140,   141,   142,   182,   252,   186,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   189,   301,   100,    51,   204,   314,
     206,    50,   284,   171,   172,   276,   277,   278,     3,     4,
     160,   256,   208,   158,   257,   204,   192,   311,   287,    25,
     179,   301,   214,    21,   161,   162,   209,   204,   210,   303,
      51,   204,    30,   268,    56,   285,   269,   312,   220,   143,
     158,   144,    24,   145,    25,   281,    18,    19,    21,   271,
     237,   238,   288,   204,   197,   289,   198,    30,   211,   315,
     316,   317,   213,  -138,  -138,  -138,   106,    24,    34,   297,
     158,   215,   298,   227,   327,   179,   329,   225,   304,   254,
     332,   179,   -30,   334,   305,   335,     5,     6,     7,     8,
       9,    10,    11,    12,   192,   232,    13,    14,   241,   242,
     243,   244,   255,   318,   320,   322,   260,   158,   -30,   -30,
     -30,   179,   179,   218,   306,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   323,   -30,   -30,   324,   263,   -30,
     -30,   -30,   111,    62,    63,    64,    65,   264,    66,    67,
    -138,  -138,  -138,   185,   267,    34,   179,   -30,   -30,   326,
     179,   179,   -30,   328,   330,    40,    41,    42,   274,     3,
       4,   179,   283,   239,   240,     5,     6,     7,     8,     9,
      10,    11,    12,   205,   279,    13,    14,   294,   295,    15,
      16,   245,   246,    68,    69,   112,   113,   114,   299,   115,
     116,   117,   118,   307,   119,   120,   121,    18,    19,   286,
      56,   122,    70,   325,   272,   123,    71,   333,   293,   248,
     251,    72,    73,    74,    75,    76,   111,    62,    63,    64,
      65,   247,    66,    67,   249,    96,   219,   250,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   262,     0,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
      14,     0,     0,    15,    16,     0,     0,    68,    69,   112,
     113,   114,     0,   115,   116,   117,   118,    37,   119,   120,
     121,    18,    19,   156,    56,     0,    70,     0,     0,   123,
      71,     0,     0,     0,     0,    72,    73,    74,    75,    76,
     280,    62,    63,    64,    65,     0,    66,    67,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,     0,     0,    15,    16,     2,     3,     4,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,    13,    14,     0,     0,    15,    16,    17,
       0,    68,    69,     0,     0,     0,     0,     0,   -30,  -138,
    -138,  -138,  -138,     0,     0,    18,    19,     0,     0,     0,
      70,     0,     0,   123,    71,     0,     0,     0,     0,    72,
      73,    74,    75,    76,   -30,   -30,   -30,     0,     0,     0,
       0,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,   -30,     0,     0,   -30,   -30,   -30,     0,  -138,
    -138,   136,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     0,     0,   -30,   -30,     0,     0,     0,   -30,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,    37,
    -138,  -138,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,    14,     0,     0,    15,    16,
       0,     0,    68,    69,    61,    62,    63,    64,    65,     0,
      66,    67,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    70,    13,    14,     0,    71,    15,    16,     0,     0,
      72,    73,    74,    75,    76,     0,     0,    61,    62,    63,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,    68,    69,    61,    62,    63,
      64,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,   196,   300,    70,     0,     0,     0,    71,     0,
     197,     0,   198,    72,    73,    74,    75,    76,    68,    69,
      61,    62,    63,    64,    65,     0,    66,    67,     0,     0,
       0,     0,     0,     0,     0,   196,   313,    70,    68,    69,
       0,    71,     0,   197,     0,   198,    72,    73,    74,    75,
      76,     0,     0,     0,     0,   196,   331,    70,     0,     0,
       0,    71,     0,   197,     0,   198,    72,    73,    74,    75,
      76,    68,    69,    61,    62,    63,    64,    65,     0,    66,
      67,     0,     0,     0,     0,     0,     0,     0,   196,     0,
      70,     0,     0,     0,    71,     0,   197,     0,   198,    72,
      73,    74,    75,    76,     0,     0,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    61,    62,    63,    64,
      65,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,   109,     0,    70,     0,     0,     0,    71,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    68,    69,    61,
      62,    63,    64,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    68,    69,   216,
      71,     0,     0,     0,     0,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
      71,   228,     0,     0,     0,    72,    73,    74,    75,    76,
      68,    69,    61,    62,    63,    64,    65,     0,    66,    67,
       0,     0,     0,     0,     0,     0,     0,   196,     0,    70,
       0,     0,     0,    71,     0,     0,     0,     0,    72,    73,
      74,    75,    76,     0,     0,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    61,    62,    63,    64,    65,
       0,    66,    67,     0,     0,     0,     0,     0,     0,     0,
     286,     0,    70,     0,     0,     0,    71,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    68,    69,    61,    62,
      63,    64,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    68,    69,   123,    71,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,    71,
     319,     0,     0,     0,    72,    73,    74,    75,    76,    68,
      69,    61,    62,    63,    64,    65,     0,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,    71,   321,     0,     0,     0,    72,    73,    74,
      75,    76,     0,     0,    61,    62,    63,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    61,    62,    63,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,    71,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    68,    69,    37,   131,     0,
       0,     0,     0,    72,    73,    74,    75,    76,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   133,     0,
      49,     0,     0,    72,    73,    74,    75,    76,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,     0,     0,    15,    16,     2,     3,     4,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    50,     0,    13,    14,    99,     0,    15,    16,    17,
       0,     0,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
      51,     2,     3,     4,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    50,     0,    13,    14,
       1,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,    51,     2,     3,     4,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    50,    59,    13,    14,     1,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     1,
      51,     2,     3,     4,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,    13,    14,
       0,     0,    15,    16,    17,     2,     3,     4,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      18,    19,    13,    14,    37,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,    14,     0,
       0,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19
  };

  const short
  parser::yycheck_[] =
  {
      34,     0,     0,     2,   196,     0,    31,     0,   109,    18,
     185,   213,    75,   197,     0,    71,   101,    83,    84,     3,
     105,    55,    21,    45,     0,    20,    25,    76,   112,    44,
      25,    94,     3,     3,    33,    33,   269,    71,    33,    25,
      13,    14,   143,    71,     3,    81,    45,    33,    76,    25,
      45,    65,    66,    67,    11,    12,   157,    33,    73,    45,
      44,    47,    79,    78,    76,   298,    74,    81,   201,    45,
     254,    75,    71,    44,    71,   131,    80,   133,   179,   281,
     282,    74,    75,    76,    93,   107,    79,   121,   263,    73,
      71,   324,   117,    44,   286,   196,    75,   131,   112,   133,
     201,    71,    73,   102,    76,   104,    75,   106,   107,   104,
     144,    80,   107,   197,    82,   101,    89,    90,   104,   105,
      75,   107,    73,    78,   160,   161,   162,    78,   104,    91,
     205,   107,   131,   208,   133,    17,   269,    76,    44,    92,
       8,     9,    10,     3,   178,    76,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    72,   298,   188,    73,   269,   302,
     254,    44,    78,    15,    16,   209,   210,   211,    30,    31,
      73,    72,    94,   197,    75,   286,   185,   288,   224,   188,
      75,   324,    76,   188,    87,    88,    77,   298,    77,   274,
      73,   302,   188,    72,    71,    78,    75,   291,    72,    77,
     224,    79,   188,    81,   213,   213,    68,    69,   213,    74,
     163,   164,    75,   324,    79,    78,    81,   213,    77,   304,
     305,   306,    77,    74,    75,    76,    77,   213,    79,    72,
     254,    76,    75,     3,   319,    75,   321,    78,    78,    74,
     325,    75,     3,   328,    78,   330,    36,    37,    38,    39,
      40,    41,    42,    43,   263,     3,    46,    47,   167,   168,
     169,   170,    75,   307,   308,   309,    72,   291,    29,    30,
      31,    75,    75,    76,    78,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    72,    46,    47,    75,    75,    50,
      51,    52,     3,     4,     5,     6,     7,    78,     9,    10,
      74,    75,    76,    77,     3,    79,    75,    68,    69,    78,
      75,    75,    73,    78,    78,     8,     9,    10,    94,    30,
      31,    75,    76,   165,   166,    36,    37,    38,    39,    40,
      41,    42,    43,    94,    61,    46,    47,    72,    78,    50,
      51,   171,   172,    54,    55,    56,    57,    58,    80,    60,
      61,    62,    63,    77,    65,    66,    67,    68,    69,    71,
      71,    72,    73,    59,   202,    76,    77,    76,   255,   174,
     177,    82,    83,    84,    85,    86,     3,     4,     5,     6,
       7,   173,     9,    10,   175,    35,   128,   176,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   192,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    50,    51,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,     3,    65,    66,
      67,    68,    69,    74,    71,    -1,    73,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    50,    51,    29,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    50,    51,    52,    -1,    54,
      55,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,     3,
      85,    86,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    50,    51,
      -1,    -1,    54,    55,     3,     4,     5,     6,     7,    -1,
       9,    10,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    73,    46,    47,    -1,    77,    50,    51,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    54,    55,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    82,    83,    84,    85,    86,    54,    55,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    54,    55,
      -1,    77,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    82,    83,    84,    85,
      86,    54,    55,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    54,    55,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    54,    55,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      54,    55,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    54,    55,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    54,    55,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    82,    83,    84,    85,    86,    54,
      55,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    54,    55,     3,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
       3,    -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    50,    51,    29,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,     3,    -1,    50,    51,    52,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,
      73,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
       3,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    -1,    -1,    73,    29,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    46,    47,     3,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,     3,
      73,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    -1,    50,    51,    52,    29,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      68,    69,    46,    47,     3,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69
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
      73,    77,    82,    83,    84,    85,    86,   107,   108,   109,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   132,   135,     3,    71,     3,
     138,    71,    97,   100,   102,   139,    77,    75,    76,    71,
     132,     3,    56,    57,    58,    60,    61,    62,    63,    65,
      66,    67,    72,    76,   132,   139,   140,   141,   142,   143,
     144,    77,   116,    77,   116,   116,     3,   102,   107,   132,
       8,     9,    10,    77,    79,    81,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    74,   131,   116,   118,
      73,    87,    88,    83,    84,    11,    12,    13,    14,    89,
      90,    15,    16,    82,    91,    92,    17,    18,    93,    75,
      80,    76,     3,   103,   104,    77,    76,   100,   102,    72,
     100,    78,   102,   145,   146,   138,    71,    79,    81,   110,
     111,   112,   113,   114,   130,    94,   129,   133,    94,    77,
      77,    77,   144,    77,    76,    76,    76,   132,    76,   143,
      72,   102,   102,    78,    78,    78,    78,     3,    78,   115,
     130,   132,     3,   130,   118,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   123,   124,   125,
     126,   127,   132,   130,    74,    75,    72,    75,    78,   146,
      72,     3,   136,    75,    78,   111,   133,     3,    72,    75,
     110,    74,   114,   142,    94,   142,   132,   132,   132,    61,
       3,   137,   140,    76,    78,    78,    71,   118,    75,    78,
      80,    94,   133,   104,    72,    78,   146,    72,    75,    80,
      72,   110,   112,   142,    78,    78,    78,    77,   140,   140,
     111,   130,   129,    72,   110,   142,   142,   142,   132,    78,
     132,    78,   132,    72,    75,    59,    78,   142,    78,   142,
      78,    72,   142,    76,   142,   142
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
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   120,   120,   120,   121,   121,   121,   122,   122,
     122,   122,   122,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   134,   135,   135,   136,   136,   137,
     137,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   148,   148,   137,   137,   137,   149,   149
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
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     2,     1,     3,
       5,     6,     1,     1,     3,     4,     3,     1,     2,     3,
       4,     3,     1,     1,     1,     1,     5,     7,     7,     5,
       2,     2,     2,     3,     6,     7,     6,     7,     5,     1,
       2,     2,     3,     2,     1,     1,     3,     4,     5,     5,
       6,     2,     2,     1,     1,     1,     1,     2
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
       0,    61,    61,    62,    63,    64,    68,    69,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    87,
      88,    92,    93,    97,    98,    99,   103,   104,   105,   106,
     107,   111,   112,   116,   117,   121,   122,   126,   127,   128,
     132,   133,   134,   135,   136,   140,   141,   142,   143,   144,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     162,   163,   164,   168,   169,   170,   171,   175,   179,   180,
     184,   185,   189,   190,   194,   195,   196,   197,   198,   199,
     204,   205,   206,   207,   208,   209,   213,   214,   218,   219,
     220,   221,   225,   226,   227,   231,   232,   233,   237,   238,
     239,   240,   241,   245,   246,   247,   251,   252,   256,   257,
     261,   262,   266,   267,   271,   272,   276,   277,   281,   282,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   300,   301,   305,   309,   313,   314,   318,   319,   323,
     324,   325,   326,   330,   331,   335,   336,   340,   341,   345,
     346,   347,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   371,
     372,   376,   377,   381,   382,   386,   387,   391,   392,   393,
     394,   398,   399,   403,   404,   405,   409,   410
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
#line 1418 "bison-parser.tab.cc" // lalr1.cc:1242
#line 412 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:1243


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

// Return the next token.
yy::parser::symbol_type yy::yylex (Parser & drv)
{
  return drv.get_next_token();
}

