// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file bison-parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_BISON_PARSER_TAB_HH_INCLUDED
# define YY_YY_BISON_PARSER_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 9 "/home/felix/projects/bright-c/brightcc/src/bison-parser.yy" // lalr1.cc:401

#include <string>
#include <vector>
struct Parser;

#line 54 "bison-parser.tab.hh" // lalr1.cc:401

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 170 "bison-parser.tab.hh" // lalr1.cc:401



  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_IDENTIFIER = 258,
        TOK_CONSTANT = 259,
        TOK_STRING_LITERAL = 260,
        TOK_SIZEOF = 261,
        TOK_PTR_OP = 262,
        TOK_INC_OP = 263,
        TOK_DEC_OP = 264,
        TOK_LEFT_OP = 265,
        TOK_RIGHT_OP = 266,
        TOK_LE_OP = 267,
        TOK_GE_OP = 268,
        TOK_EQ_OP = 269,
        TOK_NE_OP = 270,
        TOK_AND_OP = 271,
        TOK_OR_OP = 272,
        TOK_MUL_ASSIGN = 273,
        TOK_DIV_ASSIGN = 274,
        TOK_MOD_ASSIGN = 275,
        TOK_ADD_ASSIGN = 276,
        TOK_SUB_ASSIGN = 277,
        TOK_LEFT_ASSIGN = 278,
        TOK_RIGHT_ASSIGN = 279,
        TOK_AND_ASSIGN = 280,
        TOK_XOR_ASSIGN = 281,
        TOK_OR_ASSIGN = 282,
        TOK_TYPEDEF = 283,
        TOK_EXTERN = 284,
        TOK_STATIC = 285,
        TOK_AUTO = 286,
        TOK_REGISTER = 287,
        TOK_INLINE = 288,
        TOK_RESTRICT = 289,
        TOK_CHAR = 290,
        TOK_SHORT = 291,
        TOK_INT = 292,
        TOK_LONG = 293,
        TOK_SIGNED = 294,
        TOK_UNSIGNED = 295,
        TOK_FLOAT = 296,
        TOK_DOUBLE = 297,
        TOK_CONST = 298,
        TOK_VOLATILE = 299,
        TOK_VOID = 300,
        TOK_BOOL = 301,
        TOK_COMPLEX = 302,
        TOK_IMAGINARY = 303,
        TOK_STRUCT = 304,
        TOK_UNION = 305,
        TOK_ENUM = 306,
        TOK_ELLIPSIS = 307,
        TOK_CASE = 308,
        TOK_DEFAULT = 309,
        TOK_IF = 310,
        TOK_ELSE = 311,
        TOK_SWITCH = 312,
        TOK_WHILE = 313,
        TOK_DO = 314,
        TOK_FOR = 315,
        TOK_GOTO = 316,
        TOK_CONTINUE = 317,
        TOK_BREAK = 318,
        TOK_RETURN = 319,
        TOK_EXPORT = 320,
        TOK_ASYNC = 321,
        TOK_AWAIT = 322
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YYASSERT (tok == 0 || tok == token::TOK_IDENTIFIER || tok == token::TOK_CONSTANT || tok == token::TOK_STRING_LITERAL || tok == token::TOK_SIZEOF || tok == token::TOK_PTR_OP || tok == token::TOK_INC_OP || tok == token::TOK_DEC_OP || tok == token::TOK_LEFT_OP || tok == token::TOK_RIGHT_OP || tok == token::TOK_LE_OP || tok == token::TOK_GE_OP || tok == token::TOK_EQ_OP || tok == token::TOK_NE_OP || tok == token::TOK_AND_OP || tok == token::TOK_OR_OP || tok == token::TOK_MUL_ASSIGN || tok == token::TOK_DIV_ASSIGN || tok == token::TOK_MOD_ASSIGN || tok == token::TOK_ADD_ASSIGN || tok == token::TOK_SUB_ASSIGN || tok == token::TOK_LEFT_ASSIGN || tok == token::TOK_RIGHT_ASSIGN || tok == token::TOK_AND_ASSIGN || tok == token::TOK_XOR_ASSIGN || tok == token::TOK_OR_ASSIGN || tok == token::TOK_TYPEDEF || tok == token::TOK_EXTERN || tok == token::TOK_STATIC || tok == token::TOK_AUTO || tok == token::TOK_REGISTER || tok == token::TOK_INLINE || tok == token::TOK_RESTRICT || tok == token::TOK_CHAR || tok == token::TOK_SHORT || tok == token::TOK_INT || tok == token::TOK_LONG || tok == token::TOK_SIGNED || tok == token::TOK_UNSIGNED || tok == token::TOK_FLOAT || tok == token::TOK_DOUBLE || tok == token::TOK_CONST || tok == token::TOK_VOLATILE || tok == token::TOK_VOID || tok == token::TOK_BOOL || tok == token::TOK_COMPLEX || tok == token::TOK_IMAGINARY || tok == token::TOK_STRUCT || tok == token::TOK_UNION || tok == token::TOK_ENUM || tok == token::TOK_ELLIPSIS || tok == token::TOK_CASE || tok == token::TOK_DEFAULT || tok == token::TOK_IF || tok == token::TOK_ELSE || tok == token::TOK_SWITCH || tok == token::TOK_WHILE || tok == token::TOK_DO || tok == token::TOK_FOR || tok == token::TOK_GOTO || tok == token::TOK_CONTINUE || tok == token::TOK_BREAK || tok == token::TOK_RETURN || tok == token::TOK_EXPORT || tok == token::TOK_ASYNC || tok == token::TOK_AWAIT || tok == 42 || tok == 59);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YYASSERT (tok == 0 || tok == token::TOK_IDENTIFIER || tok == token::TOK_CONSTANT || tok == token::TOK_STRING_LITERAL || tok == token::TOK_SIZEOF || tok == token::TOK_PTR_OP || tok == token::TOK_INC_OP || tok == token::TOK_DEC_OP || tok == token::TOK_LEFT_OP || tok == token::TOK_RIGHT_OP || tok == token::TOK_LE_OP || tok == token::TOK_GE_OP || tok == token::TOK_EQ_OP || tok == token::TOK_NE_OP || tok == token::TOK_AND_OP || tok == token::TOK_OR_OP || tok == token::TOK_MUL_ASSIGN || tok == token::TOK_DIV_ASSIGN || tok == token::TOK_MOD_ASSIGN || tok == token::TOK_ADD_ASSIGN || tok == token::TOK_SUB_ASSIGN || tok == token::TOK_LEFT_ASSIGN || tok == token::TOK_RIGHT_ASSIGN || tok == token::TOK_AND_ASSIGN || tok == token::TOK_XOR_ASSIGN || tok == token::TOK_OR_ASSIGN || tok == token::TOK_TYPEDEF || tok == token::TOK_EXTERN || tok == token::TOK_STATIC || tok == token::TOK_AUTO || tok == token::TOK_REGISTER || tok == token::TOK_INLINE || tok == token::TOK_RESTRICT || tok == token::TOK_CHAR || tok == token::TOK_SHORT || tok == token::TOK_INT || tok == token::TOK_LONG || tok == token::TOK_SIGNED || tok == token::TOK_UNSIGNED || tok == token::TOK_FLOAT || tok == token::TOK_DOUBLE || tok == token::TOK_CONST || tok == token::TOK_VOLATILE || tok == token::TOK_VOID || tok == token::TOK_BOOL || tok == token::TOK_COMPLEX || tok == token::TOK_IMAGINARY || tok == token::TOK_STRUCT || tok == token::TOK_UNION || tok == token::TOK_ENUM || tok == token::TOK_ELLIPSIS || tok == token::TOK_CASE || tok == token::TOK_DEFAULT || tok == token::TOK_IF || tok == token::TOK_ELSE || tok == token::TOK_SWITCH || tok == token::TOK_WHILE || tok == token::TOK_DO || tok == token::TOK_FOR || tok == token::TOK_GOTO || tok == token::TOK_CONTINUE || tok == token::TOK_BREAK || tok == token::TOK_RETURN || tok == token::TOK_EXPORT || tok == token::TOK_ASYNC || tok == token::TOK_AWAIT || tok == 42 || tok == 59);
      }
#endif
    };

    /// Build a parser object.
    parser (Parser& drv_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER ()
      {
        return symbol_type (token::TOK_IDENTIFIER);
      }
#else
      static
      symbol_type
      make_IDENTIFIER ()
      {
        return symbol_type (token::TOK_IDENTIFIER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTANT ()
      {
        return symbol_type (token::TOK_CONSTANT);
      }
#else
      static
      symbol_type
      make_CONSTANT ()
      {
        return symbol_type (token::TOK_CONSTANT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL ()
      {
        return symbol_type (token::TOK_STRING_LITERAL);
      }
#else
      static
      symbol_type
      make_STRING_LITERAL ()
      {
        return symbol_type (token::TOK_STRING_LITERAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF ()
      {
        return symbol_type (token::TOK_SIZEOF);
      }
#else
      static
      symbol_type
      make_SIZEOF ()
      {
        return symbol_type (token::TOK_SIZEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTR_OP ()
      {
        return symbol_type (token::TOK_PTR_OP);
      }
#else
      static
      symbol_type
      make_PTR_OP ()
      {
        return symbol_type (token::TOK_PTR_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC_OP ()
      {
        return symbol_type (token::TOK_INC_OP);
      }
#else
      static
      symbol_type
      make_INC_OP ()
      {
        return symbol_type (token::TOK_INC_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC_OP ()
      {
        return symbol_type (token::TOK_DEC_OP);
      }
#else
      static
      symbol_type
      make_DEC_OP ()
      {
        return symbol_type (token::TOK_DEC_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP ()
      {
        return symbol_type (token::TOK_LEFT_OP);
      }
#else
      static
      symbol_type
      make_LEFT_OP ()
      {
        return symbol_type (token::TOK_LEFT_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP ()
      {
        return symbol_type (token::TOK_RIGHT_OP);
      }
#else
      static
      symbol_type
      make_RIGHT_OP ()
      {
        return symbol_type (token::TOK_RIGHT_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE_OP ()
      {
        return symbol_type (token::TOK_LE_OP);
      }
#else
      static
      symbol_type
      make_LE_OP ()
      {
        return symbol_type (token::TOK_LE_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE_OP ()
      {
        return symbol_type (token::TOK_GE_OP);
      }
#else
      static
      symbol_type
      make_GE_OP ()
      {
        return symbol_type (token::TOK_GE_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP ()
      {
        return symbol_type (token::TOK_EQ_OP);
      }
#else
      static
      symbol_type
      make_EQ_OP ()
      {
        return symbol_type (token::TOK_EQ_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE_OP ()
      {
        return symbol_type (token::TOK_NE_OP);
      }
#else
      static
      symbol_type
      make_NE_OP ()
      {
        return symbol_type (token::TOK_NE_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP ()
      {
        return symbol_type (token::TOK_AND_OP);
      }
#else
      static
      symbol_type
      make_AND_OP ()
      {
        return symbol_type (token::TOK_AND_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP ()
      {
        return symbol_type (token::TOK_OR_OP);
      }
#else
      static
      symbol_type
      make_OR_OP ()
      {
        return symbol_type (token::TOK_OR_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN ()
      {
        return symbol_type (token::TOK_MUL_ASSIGN);
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN ()
      {
        return symbol_type (token::TOK_MUL_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN ()
      {
        return symbol_type (token::TOK_DIV_ASSIGN);
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN ()
      {
        return symbol_type (token::TOK_DIV_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ASSIGN ()
      {
        return symbol_type (token::TOK_MOD_ASSIGN);
      }
#else
      static
      symbol_type
      make_MOD_ASSIGN ()
      {
        return symbol_type (token::TOK_MOD_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ASSIGN ()
      {
        return symbol_type (token::TOK_ADD_ASSIGN);
      }
#else
      static
      symbol_type
      make_ADD_ASSIGN ()
      {
        return symbol_type (token::TOK_ADD_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_ASSIGN ()
      {
        return symbol_type (token::TOK_SUB_ASSIGN);
      }
#else
      static
      symbol_type
      make_SUB_ASSIGN ()
      {
        return symbol_type (token::TOK_SUB_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_ASSIGN ()
      {
        return symbol_type (token::TOK_LEFT_ASSIGN);
      }
#else
      static
      symbol_type
      make_LEFT_ASSIGN ()
      {
        return symbol_type (token::TOK_LEFT_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_ASSIGN ()
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN);
      }
#else
      static
      symbol_type
      make_RIGHT_ASSIGN ()
      {
        return symbol_type (token::TOK_RIGHT_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ASSIGN ()
      {
        return symbol_type (token::TOK_AND_ASSIGN);
      }
#else
      static
      symbol_type
      make_AND_ASSIGN ()
      {
        return symbol_type (token::TOK_AND_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN ()
      {
        return symbol_type (token::TOK_XOR_ASSIGN);
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN ()
      {
        return symbol_type (token::TOK_XOR_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ASSIGN ()
      {
        return symbol_type (token::TOK_OR_ASSIGN);
      }
#else
      static
      symbol_type
      make_OR_ASSIGN ()
      {
        return symbol_type (token::TOK_OR_ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF ()
      {
        return symbol_type (token::TOK_TYPEDEF);
      }
#else
      static
      symbol_type
      make_TYPEDEF ()
      {
        return symbol_type (token::TOK_TYPEDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERN ()
      {
        return symbol_type (token::TOK_EXTERN);
      }
#else
      static
      symbol_type
      make_EXTERN ()
      {
        return symbol_type (token::TOK_EXTERN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC ()
      {
        return symbol_type (token::TOK_STATIC);
      }
#else
      static
      symbol_type
      make_STATIC ()
      {
        return symbol_type (token::TOK_STATIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO ()
      {
        return symbol_type (token::TOK_AUTO);
      }
#else
      static
      symbol_type
      make_AUTO ()
      {
        return symbol_type (token::TOK_AUTO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER ()
      {
        return symbol_type (token::TOK_REGISTER);
      }
#else
      static
      symbol_type
      make_REGISTER ()
      {
        return symbol_type (token::TOK_REGISTER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE ()
      {
        return symbol_type (token::TOK_INLINE);
      }
#else
      static
      symbol_type
      make_INLINE ()
      {
        return symbol_type (token::TOK_INLINE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESTRICT ()
      {
        return symbol_type (token::TOK_RESTRICT);
      }
#else
      static
      symbol_type
      make_RESTRICT ()
      {
        return symbol_type (token::TOK_RESTRICT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR ()
      {
        return symbol_type (token::TOK_CHAR);
      }
#else
      static
      symbol_type
      make_CHAR ()
      {
        return symbol_type (token::TOK_CHAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT ()
      {
        return symbol_type (token::TOK_SHORT);
      }
#else
      static
      symbol_type
      make_SHORT ()
      {
        return symbol_type (token::TOK_SHORT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT ()
      {
        return symbol_type (token::TOK_INT);
      }
#else
      static
      symbol_type
      make_INT ()
      {
        return symbol_type (token::TOK_INT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG ()
      {
        return symbol_type (token::TOK_LONG);
      }
#else
      static
      symbol_type
      make_LONG ()
      {
        return symbol_type (token::TOK_LONG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGNED ()
      {
        return symbol_type (token::TOK_SIGNED);
      }
#else
      static
      symbol_type
      make_SIGNED ()
      {
        return symbol_type (token::TOK_SIGNED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED ()
      {
        return symbol_type (token::TOK_UNSIGNED);
      }
#else
      static
      symbol_type
      make_UNSIGNED ()
      {
        return symbol_type (token::TOK_UNSIGNED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT ()
      {
        return symbol_type (token::TOK_FLOAT);
      }
#else
      static
      symbol_type
      make_FLOAT ()
      {
        return symbol_type (token::TOK_FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE ()
      {
        return symbol_type (token::TOK_DOUBLE);
      }
#else
      static
      symbol_type
      make_DOUBLE ()
      {
        return symbol_type (token::TOK_DOUBLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::TOK_CONST);
      }
#else
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::TOK_CONST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOLATILE ()
      {
        return symbol_type (token::TOK_VOLATILE);
      }
#else
      static
      symbol_type
      make_VOLATILE ()
      {
        return symbol_type (token::TOK_VOLATILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID ()
      {
        return symbol_type (token::TOK_VOID);
      }
#else
      static
      symbol_type
      make_VOID ()
      {
        return symbol_type (token::TOK_VOID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL ()
      {
        return symbol_type (token::TOK_BOOL);
      }
#else
      static
      symbol_type
      make_BOOL ()
      {
        return symbol_type (token::TOK_BOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEX ()
      {
        return symbol_type (token::TOK_COMPLEX);
      }
#else
      static
      symbol_type
      make_COMPLEX ()
      {
        return symbol_type (token::TOK_COMPLEX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMAGINARY ()
      {
        return symbol_type (token::TOK_IMAGINARY);
      }
#else
      static
      symbol_type
      make_IMAGINARY ()
      {
        return symbol_type (token::TOK_IMAGINARY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT ()
      {
        return symbol_type (token::TOK_STRUCT);
      }
#else
      static
      symbol_type
      make_STRUCT ()
      {
        return symbol_type (token::TOK_STRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION ()
      {
        return symbol_type (token::TOK_UNION);
      }
#else
      static
      symbol_type
      make_UNION ()
      {
        return symbol_type (token::TOK_UNION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::TOK_ENUM);
      }
#else
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::TOK_ENUM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS ()
      {
        return symbol_type (token::TOK_ELLIPSIS);
      }
#else
      static
      symbol_type
      make_ELLIPSIS ()
      {
        return symbol_type (token::TOK_ELLIPSIS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE ()
      {
        return symbol_type (token::TOK_CASE);
      }
#else
      static
      symbol_type
      make_CASE ()
      {
        return symbol_type (token::TOK_CASE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::TOK_DEFAULT);
      }
#else
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::TOK_DEFAULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::TOK_IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::TOK_IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::TOK_ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::TOK_ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::TOK_SWITCH);
      }
#else
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::TOK_SWITCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::TOK_WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::TOK_WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::TOK_DO);
      }
#else
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::TOK_DO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::TOK_FOR);
      }
#else
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::TOK_FOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::TOK_GOTO);
      }
#else
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::TOK_GOTO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::TOK_CONTINUE);
      }
#else
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::TOK_CONTINUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::TOK_BREAK);
      }
#else
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::TOK_BREAK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::TOK_RETURN);
      }
#else
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::TOK_RETURN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPORT ()
      {
        return symbol_type (token::TOK_EXPORT);
      }
#else
      static
      symbol_type
      make_EXPORT ()
      {
        return symbol_type (token::TOK_EXPORT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASYNC ()
      {
        return symbol_type (token::TOK_ASYNC);
      }
#else
      static
      symbol_type
      make_ASYNC ()
      {
        return symbol_type (token::TOK_ASYNC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AWAIT ()
      {
        return symbol_type (token::TOK_AWAIT);
      }
#else
      static
      symbol_type
      make_AWAIT ()
      {
        return symbol_type (token::TOK_AWAIT);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const signed char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 122,     ///< Last index in yytable_.
      yynnts_ = 8,  ///< Number of nonterminal symbols.
      yyfinal_ = 29, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 70  ///< Number of tokens.
    };


    // User arguments.
    Parser& drv;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
    };
    const unsigned user_token_number_max_ = 322;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    42,    59
    };
    return token_type (yytoken_number_[type]);
  }


} // yy
#line 2142 "bison-parser.tab.hh" // lalr1.cc:401




#endif // !YY_YY_BISON_PARSER_TAB_HH_INCLUDED