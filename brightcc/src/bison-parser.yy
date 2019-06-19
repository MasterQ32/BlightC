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
    parser::symbol_type yylex (Parser & drv);
  }
}

%locations

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

// %printer { yyo << $$; } <*>;
%token IDENTIFIER INT_CONSTANT REAL_CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token TRUE FALSE
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

/* BrightC tokens and keywords */
%token EXPORT ASYNC
%token AWAIT

%start translation_unit
%%

linkage_modifier
    : STATIC
    | EXTERN
    | EXPORT
    | ASYNC
;

linkage_modifiers
    : linkage_modifier
    | linkage_modifier linkage_modifiers
;

primitive_type
    : SIGNED primitive_type
    | UNSIGNED primitive_type
    | LONG primitive_type
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | BOOL
    | VOID
;

type
    : primitive_type
    | type '*'
    | type CONST
    | IDENTIFIER
;

literal
    : TRUE
    | FALSE
    | INT_CONSTANT
    | REAL_CONSTANT
    | STRING_LITERAL
    ;

value_expr
    : literal
    | IDENTIFIER
;

expr_list
    : expr
    | expr ',' expr_list
;

expr
    : value_expr
    | value_expr '(' ')'
    | value_expr '(' expr_list ')'
    | value_expr '[' expr_list ']'
;

array_size_modifier
    : '[' expr ']'
;

array_size_modifiers
    : array_size_modifier
    | array_size_modifier array_size_modifiers
;

scalar_or_array_name
    : IDENTIFIER array_size_modifiers
    | IDENTIFIER
;

variable_declaration
    : linkage_modifiers type scalar_or_array_name ';'
    | type scalar_or_array_name ';'
    | linkage_modifiers type scalar_or_array_name '=' expr ';'
    | type scalar_or_array_name '=' expr ';'
;

statement
    : ';'
    | expr ';'
    | block
    | variable_declaration
    | WHILE '(' expr ')' statement
;

statement_list
    : statement
    | statement statement_list
;

block
    :'{' '}'
    |'{' statement_list '}'
;

parameter
    : type scalar_or_array_name
    | type
;

parameter_list
    : parameter
    | parameter ',' parameter_list
;

function_signature
    : type IDENTIFIER '(' ')'
    | type IDENTIFIER '(' parameter_list ')'
    | linkage_modifiers type IDENTIFIER '(' ')'
    | linkage_modifiers type IDENTIFIER '(' parameter_list ')'
;

function_declaration
    : function_signature ';'
    | function_signature block
;

declaration
    : variable_declaration
    | function_declaration
;

translation_unit
    : declaration
    | translation_unit declaration
;
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

// Return the next token.
yy::parser::symbol_type yy::yylex (Parser & drv)
{
  return drv.get_next_token();
}

