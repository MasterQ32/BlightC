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
#line 37 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:435

  // Print a list of strings.
  auto
  operator<< (std::ostream& o, const std::vector<std::string>& ss)
    -> std::ostream&
  {
    o << '{';
    const char *sep = "";
    for (const auto& s: ss)
      {
        o << sep << s;
        sep = ", ";
      }
    return o << '}';
  }

#line 72 "bison-parser.tab.cc" // lalr1.cc:435


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
#line 167 "bison-parser.tab.cc" // lalr1.cc:510

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

#line 575 "bison-parser.tab.cc" // lalr1.cc:919
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


  const short parser::yypact_ninf_ = -219;

  const signed char parser::yytable_ninf_ = -23;

  const short
  parser::yypact_[] =
  {
     680,  -219,  -219,  -219,  -219,  -219,  -219,   733,   733,   733,
    -219,  -219,  -219,  -219,  -219,  -219,   -20,   721,  -219,    68,
    -219,   -39,  -219,  -219,   661,  -219,  -219,  -219,  -219,    69,
      60,  -219,  -219,   -28,   155,  -219,  -219,  -219,  -219,    97,
      50,   215,   565,   -56,  -219,   565,  -219,    44,  -219,  -219,
    -219,   597,   605,   605,  -219,  -219,   -49,   -44,   -46,   -35,
     -32,  -219,   321,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
     721,    84,  -219,  -219,    55,   712,   565,  -219,   -11,   101,
     176,    -5,   184,    38,   -40,    52,   133,   -13,  -219,  -219,
     -25,  -219,   238,    95,  -219,   585,   565,  -219,  -219,    84,
      78,   117,  -219,    77,  -219,    30,   321,  -219,   321,  -219,
    -219,   565,   565,   150,  -219,  -219,   -31,   -12,    84,   -56,
     211,  -219,  -219,   459,   565,   212,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,   565,  -219,  -219,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
    -219,  -219,  -219,  -219,   146,    39,  -219,   721,  -219,  -219,
    -219,   -30,   -27,    63,    72,   153,   480,  -219,  -219,  -219,
      74,  -219,    88,  -219,  -219,  -219,  -219,  -219,   -11,   -11,
     101,   101,   176,   176,   176,   176,    -5,    -5,   184,    38,
     -40,    52,   133,   -59,  -219,  -219,  -219,  -219,   145,   145,
     -46,   238,   565,   427,  -219,  -219,   565,  -219,   565,   175,
    -219,    75,   565,   232,   427,  -219,   125,   512,    61,  -219,
    -219,  -219,  -219,   -46,   152,  -219,   185,  -219,   127,  -219,
     336,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   374,  -219,
    -219,   512,  -219,  -219
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    22,     3,     2,    11,    12,    13,    14,     0,     0,
      15,    16,    18,    17,     4,     5,     6,     0,    19,     0,
     148,     0,   149,   150,     0,    10,     8,     9,     7,     0,
     119,    21,    20,     0,     0,   146,   147,     1,   151,   119,
       0,     0,     0,   116,   118,     0,   121,    28,    25,    26,
      27,     0,     0,     0,    23,    24,     0,     0,     0,     0,
       0,    62,     0,   136,    61,    63,    64,    65,    66,   124,
       0,     0,    29,    31,    55,    67,     0,    69,    73,    76,
      79,    84,    87,    89,    91,    93,    95,    97,    99,   112,
       0,   127,   134,     0,   126,     0,     0,   120,   142,   139,
     140,     0,    28,     0,   117,     0,     0,    59,     0,    56,
      57,     0,     0,     0,   133,   132,     0,     0,     0,   119,
       0,    37,    38,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   101,     0,    67,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   135,   137,   144,     0,     0,   138,     0,   143,   115,
     123,     0,     0,     0,     0,     0,     0,    30,    36,    33,
       0,    53,     0,    35,   100,    70,    71,    72,    74,    75,
      77,    78,    82,    83,    80,    81,    85,    86,    88,    90,
      92,    94,    96,     0,   113,   145,   122,   141,    60,     0,
       0,     0,     0,     0,    68,    34,     0,    32,     0,   131,
     128,     0,     0,     0,     0,    45,     0,     0,     0,    49,
      43,    54,    98,     0,     0,   114,     0,    52,     0,    39,
       0,    44,    48,    50,   130,   129,    51,    41,     0,    40,
      47,     0,    42,    46
  };

  const short
  parser::yypgoto_[] =
  {
    -219,  -219,    29,   172,    15,  -219,  -219,  -219,  -215,    26,
    -218,  -219,    31,  -219,   -50,  -219,   -60,    64,    83,    28,
      79,   110,   111,   109,   114,   115,  -219,   -52,  -102,  -219,
     -38,  -219,  -219,   223,   -10,    27,    56,   179,   -21,  -219,
     -89,  -219,  -219,   249,  -219
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    16,    70,    18,    71,    72,    73,    74,   225,   226,
     227,   228,   229,   180,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   137,
      90,   236,    43,    44,    33,    91,    92,    93,    94,   100,
     101,    21,    22,    23,    24
  };

  const short
  parser::yytable_[] =
  {
      36,   107,   109,   110,   103,   157,   164,   105,   147,   148,
       2,     3,   241,    31,    31,    19,   139,    31,    42,    40,
     159,   181,   251,   111,   117,   250,   138,    20,   112,    17,
     251,    34,    29,   250,   218,   184,   253,   113,    34,    19,
      32,    32,   176,   208,    32,    28,   209,   -22,    14,    15,
     154,    20,    45,    17,   159,    35,    99,   204,   165,   114,
     140,   177,   115,   120,   121,   122,    46,   159,   117,   160,
     117,    30,    39,   173,   174,   141,   142,   116,   207,   158,
     185,   186,   187,   149,   150,   118,   182,   119,   -22,   166,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,    40,   159,
      99,   230,    31,    31,   231,   -22,   214,   -22,   159,   153,
     203,   171,   230,   172,   170,   230,   138,   123,    31,   124,
      96,   125,    41,   206,    42,   222,   210,   223,   230,    32,
      32,   242,   159,   155,    97,   211,   230,   215,   234,   230,
     156,   159,   169,   216,   159,    32,   159,   167,    47,    48,
      49,    50,    51,   217,    52,    53,   232,   159,   138,    95,
     235,    42,   138,   162,   221,   192,   193,   194,   195,    25,
      26,    27,    99,   143,   144,     2,     3,   145,   146,   219,
     168,     4,     5,     6,     7,     8,     9,    10,    11,   151,
     152,    12,    13,   239,   240,   247,   248,   188,   189,    54,
      55,   175,   244,    56,   178,   183,    57,    58,     1,   205,
      59,    60,   213,    14,    15,   212,    61,    62,   190,   191,
     196,   197,    34,    63,   233,   237,    64,    65,    66,    67,
      68,    47,    48,    49,    50,    51,   245,    52,    53,    69,
     238,     4,     5,     6,     7,     8,     9,    10,    11,   243,
     246,    12,    13,   198,   200,   199,   104,   220,     2,     3,
     201,   161,   202,    38,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,    12,    13,     0,     0,    98,     0,
       0,     0,    54,    55,     0,     0,    56,     0,     0,    57,
      58,     0,     0,    59,    60,     0,    14,    15,     0,    61,
      62,     0,     0,     0,     0,    34,     0,     0,     0,    64,
      65,    66,    67,    68,    47,    48,    49,    50,    51,     0,
      52,    53,    69,     0,     0,     0,     0,     0,     0,   102,
      48,    49,    50,    51,     0,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,    12,    13,     0,
       0,     0,     0,     0,     0,    54,    55,   102,    48,    49,
      50,    51,     0,    52,    53,     0,     0,     0,     0,     0,
      54,    55,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    61,    62,     0,
     222,     0,   223,   224,   249,     0,     0,    64,    65,    66,
      67,    68,     0,     0,     0,     0,     0,     0,    54,    55,
     102,    48,    49,    50,    51,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,    61,    62,     0,   222,     0,
     223,   224,   252,     0,     0,    64,    65,    66,    67,    68,
       0,     0,   102,    48,    49,    50,    51,     0,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    55,   102,    48,    49,    50,    51,     0,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,   222,     0,   223,   224,     0,     0,     0,    64,    65,
      66,    67,    68,    54,    55,   102,    48,    49,    50,    51,
       0,    52,    53,     0,     0,     0,     0,     0,     0,     0,
      61,    62,   179,     0,    54,    55,     0,     0,     0,     0,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,    61,    62,     0,     0,     0,     0,   213,     0,     0,
       0,    64,    65,    66,    67,    68,    54,    55,   102,    48,
      49,    50,    51,     0,    52,    53,     0,     0,     0,     0,
       0,     0,     0,    61,    62,     0,     0,     0,     1,   224,
       0,     0,     0,    64,    65,    66,    67,    68,     0,     0,
     102,    48,    49,    50,    51,     0,    52,    53,   102,    48,
      49,    50,    51,     0,    52,    53,     0,     0,     0,    54,
      55,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,    12,    13,     0,     0,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    54,    55,     0,     0,     0,     0,     0,   163,    54,
      55,    37,     0,     0,     1,     0,     0,     0,    61,   106,
       0,     0,     0,     0,     0,     0,    61,   108,    64,    65,
      66,    67,    68,     1,     0,     0,    64,    65,    66,    67,
      68,     2,     3,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,    12,    13,     0,
       2,     3,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,     1,     0,    12,    13,     0,    14,
      15,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,    12,    13,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136
  };

  const short
  parser::yycheck_[] =
  {
      21,    51,    52,    53,    42,    18,    95,    45,    13,    14,
      30,    31,   227,    44,    44,     0,    76,    44,    74,    29,
      79,   123,   240,    72,    62,   240,    76,     0,    72,     0,
     248,    77,    17,   248,    93,   137,   251,    58,    77,    24,
      71,    71,    73,    73,    71,    16,    73,     3,    68,    69,
      90,    24,    80,    24,    79,    94,    41,   159,    96,    94,
      71,    73,    94,     8,     9,    10,    94,    79,   106,    94,
     108,     3,     3,   111,   112,    86,    87,    62,   167,    92,
     140,   141,   142,    88,    89,    70,   124,     3,    44,    99,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   118,    79,
      95,   213,    44,    44,   216,    71,   176,    73,    79,    81,
     158,   106,   224,   108,    94,   227,   176,    72,    44,    74,
      80,    76,    72,    94,    74,    74,    73,    76,   240,    71,
      71,    80,    79,    91,    94,    73,   248,    73,    73,   251,
      17,    79,    75,    79,    79,    71,    79,    79,     3,     4,
       5,     6,     7,    75,     9,    10,   218,    79,   218,    72,
     222,    74,   222,    78,   212,   147,   148,   149,   150,     7,
       8,     9,   167,    82,    83,    30,    31,    11,    12,   210,
      73,    36,    37,    38,    39,    40,    41,    42,    43,    15,
      16,    46,    47,    78,    79,    78,    79,   143,   144,    54,
      55,    61,   233,    58,     3,     3,    61,    62,     3,    73,
      65,    66,    77,    68,    69,    72,    71,    72,   145,   146,
     151,   152,    77,    78,    59,     3,    81,    82,    83,    84,
      85,     3,     4,     5,     6,     7,    94,     9,    10,    94,
     224,    36,    37,    38,    39,    40,    41,    42,    43,   228,
      75,    46,    47,   153,   155,   154,    43,   211,    30,    31,
     156,    92,   157,    24,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    73,    -1,
      -1,    -1,    54,    55,    -1,    -1,    58,    -1,    -1,    61,
      62,    -1,    -1,    65,    66,    -1,    68,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,     3,     4,     5,     6,     7,    -1,
       9,    10,    94,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      54,    55,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    71,    72,    -1,
      74,    -1,    76,    77,    78,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    54,    55,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    54,    55,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    54,    55,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,     3,    77,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    54,
      55,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    54,    55,    -1,    -1,    -1,    -1,    -1,    73,    54,
      55,     0,    -1,    -1,     3,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    81,    82,
      83,    84,    85,     3,    -1,    -1,    81,    82,    83,    84,
      85,    30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,     3,    -1,    46,    47,    -1,    68,
      69,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    30,    31,    36,    37,    38,    39,    40,    41,
      42,    43,    46,    47,    68,    69,    96,    97,    98,    99,
     130,   136,   137,   138,   139,    98,    98,    98,    97,    99,
       3,    44,    71,   129,    77,    94,   133,     0,   138,     3,
     129,    72,    74,   127,   128,    80,    94,     3,     4,     5,
       6,     7,     9,    10,    54,    55,    58,    61,    62,    65,
      66,    71,    72,    78,    81,    82,    83,    84,    85,    94,
      97,    99,   100,   101,   102,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     125,   130,   131,   132,   133,    72,    80,    94,    73,    99,
     134,   135,     3,   125,   128,   125,    72,   109,    72,   109,
     109,    72,    72,   133,    94,    94,    99,   125,    99,     3,
       8,     9,    10,    72,    74,    76,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    80,   124,   109,   111,
      71,    86,    87,    82,    83,    11,    12,    13,    14,    88,
      89,    15,    16,    81,    90,    91,    17,    18,    92,    79,
      94,   132,    78,    73,   135,   125,   129,    79,    73,    75,
      94,    99,    99,   125,   125,    61,    73,    73,     3,    73,
     108,   123,   125,     3,   123,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   115,   115,   116,   117,
     118,   119,   120,   125,   123,    73,    94,   135,    73,    73,
      73,    73,    72,    77,   111,    73,    79,    75,    93,   133,
     131,   125,    74,    76,    77,   103,   104,   105,   106,   107,
     123,   123,   122,    59,    73,   122,   126,     3,   104,    78,
      79,   103,    80,   107,   133,    94,    75,    78,    79,    78,
     103,   105,    78,   103
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    95,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   115,
     115,   115,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   126,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     3,     4,     3,     3,     2,     2,     6,
       7,     3,     4,     1,     2,     1,     4,     3,     2,     1,
       2,     3,     2,     1,     3,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     2,     1,
       4,     3,     6,     5,     1,     2,     1,     1,     5,     7,
       7,     5,     2,     2,     1,     2,     2,     3,     2,     1,
       1,     3,     4,     5,     5,     6,     2,     2,     1,     1,
       1,     2
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
  "AWAIT", "'*'", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'='", "'&'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "';'", "$accept", "linkage_modifier",
  "linkage_modifiers", "primitive_type", "type", "literal",
  "primary_expression", "postfix_expression", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expr", "constexpr", "array_size_modifier", "array_size_modifiers",
  "scalar_or_array_name", "variable_declaration", "statement",
  "statement_list", "block", "parameter", "parameter_list",
  "function_signature", "function_declaration", "declaration",
  "translation_unit", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,    79,    79,    80,    81,    82,    86,    87,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   105,
     106,   107,   108,   112,   113,   114,   115,   116,   120,   121,
     122,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   140,   141,   142,   146,   147,   148,   149,   153,   157,
     158,   162,   163,   167,   168,   172,   173,   174,   175,   176,
     177,   182,   183,   184,   185,   186,   187,   191,   192,   196,
     197,   198,   199,   203,   204,   205,   209,   210,   211,   215,
     216,   217,   218,   219,   223,   224,   225,   229,   230,   234,
     235,   239,   240,   244,   245,   249,   250,   254,   255,   259,
     260,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   278,   279,   283,   287,   291,   292,   296,   297,
     301,   302,   303,   304,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   321,   322,   326,   327,   331,   332,
     336,   337,   341,   342,   343,   344,   348,   349,   353,   354,
     358,   359
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
#line 1265 "bison-parser.tab.cc" // lalr1.cc:1242
#line 361 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:1243


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

// Return the next token.
yy::parser::symbol_type yy::yylex (Parser & drv)
{
  return drv.get_next_token();
}

