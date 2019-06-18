%skeleton "lalr1.cc" /* -*- C++ -*- */
%language "c++"
%require "3.2"
/* %require "3.3.2" */
%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%code requires {
#include <string>
#include <vector>
struct Parser;
}

// The parsing context.
%param { Parser& drv }

%code
{
  namespace yy
  {
    // Return the next token.
    auto yylex (Parser & drv) -> parser::symbol_type
    {
      static int count = 0;
      switch (int stage = count++)
        {
        case 0:
          return parser::make_TEXT ("I have three numbers for you.");
        case 1: case 2: case 3:
          return parser::make_NUMBER (stage);
        case 4:
          return parser::make_TEXT ("And that's all!");
        default:
          return parser::symbol_type { };
        }
    }
  }
}

// %locations

%define parse.trace
%define parse.error verbose

%code {
#include "parser.hpp"
}

%code
{
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
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%printer { yyo << $$; } <*>;

%type <std::string> item
%token <std::string> TEXT
%token <int> NUMBER
// %token END_OF_FILE 0

%start result;
%type <std::vector<std::string>> list;

%%

result
  : list  { std::cout << $1 << '\n'; }
;
item
  : TEXT
  | NUMBER  { $$ = std::to_string ($1); }
;

list
  :  %empty     { /* Generates an empty string list */ }
  | list item  { $$ = $1; $$.push_back ($2); }
;

%%
void yy::parser::error (/* const location_type& l,*/ const std::string& m)
{
  // std::cerr << l << ": " << m << '\n';
  std::cerr << "error: " << m << '\n';
}
