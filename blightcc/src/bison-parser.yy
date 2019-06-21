%skeleton "lalr1.cc" /* -*- C++ -*- */
%language "c++"
%require "3.2"
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

// %verbose
%define parse.trace
%define parse.error verbose

%code {
#include "parser.hpp"
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

struct_or_union
    : STRUCT
    | UNION
;

struct_declaration_list
    : variable_declaration
    | variable_declaration  struct_declaration_list
;

struct_or_union_specifier
    : struct_or_union '{' struct_declaration_list '}'
    | struct_or_union IDENTIFIER '{' struct_declaration_list '}'
    | struct_or_union IDENTIFIER
;

type
    : primitive_type
    | type '*'
    | type CONST
    | struct_or_union_specifier
    | IDENTIFIER
;

enum_member
    : IDENTIFIER
    | IDENTIFIER '=' constexpr
;

enum_members
    : enum_member
    | enum_member ',' enum_members
;

enum_specifier
    : ENUM IDENTIFIER '{' enum_members '}';
    | ENUM IDENTIFIER '{' enum_members ',' '}';
;

type_declaration
    : struct_or_union_specifier ';'
    | TYPEDEF type IDENTIFIER ';'
    | enum_specifier ';'
;

literal
    : TRUE
    | FALSE
    | INT_CONSTANT
    | REAL_CONSTANT
    | STRING_LITERAL
    ;

primary_expression
    : IDENTIFIER
    | literal
    | '(' expr ')'
    | '(' IDENTIFIER ')'
    | '(' literal ')'
    ;


postfix_expression
	: primary_expression
	| postfix_expression '[' expr ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type ')' '{' initializer_list '}'
	| '(' type ')' '{' initializer_list ',' '}'
	;

initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constexpr ']'
	| '.' IDENTIFIER
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type ')'
	// | ALIGNOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
    | AWAIT
	;

cast_expression
	: unary_expression
	| '(' type ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expr ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expr
	: assignment_expression
	| expr ',' assignment_expression
	;

constexpr
	: conditional_expression	/* with constraints */
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

declaration
    : scalar_or_array_name '=' expr
    | scalar_or_array_name '=' '{' initializer_list '}'
    | scalar_or_array_name '=' '{' initializer_list ',' '}'
    | scalar_or_array_name
;

declaration_list
    : declaration
    | declaration ',' declaration_list
;

variable_declaration
    : linkage_modifiers type declaration_list ';'
    | type declaration_list ';'
;

expression_statement
    : ';'
    | expr ';'
;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constexpr ':' statement
	| DEFAULT ':' statement
	;

statement
    : expression_statement
    | labeled_statement
    | block
    | variable_declaration
    | WHILE '(' expr ')' statement
    | DO block WHILE '(' expr ')' ';'
    | IF '(' expr ')' statement ELSE statement
    | IF '(' expr ')' statement
    | BREAK ';'
    | CONTINUE ';'
    | RETURN ';'
    | RETURN expr ';'
    | FOR '(' expression_statement expression_statement ')' statement
    | FOR '(' expression_statement expression_statement expr ')' statement
    | FOR '(' declaration expression_statement ')' statement
    | FOR '(' declaration expression_statement expr ')' statement
    | SWITCH '(' expr ')' statement
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
    | type_declaration
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

