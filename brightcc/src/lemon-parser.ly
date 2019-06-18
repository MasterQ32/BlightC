%name BrightCParser
%start_symbol brightc_file
%token_prefix LTOK_

%include {#include <assert.h>}

primary_expression ::= IDENTIFIER.
primary_expression ::= CONSTANT.
primary_expression ::= STRING_LITERAL.
primary_expression ::= LPARENS expression RPARENS.

postfix_expression ::= primary_expression.
postfix_expression ::= postfix_expression LBRACKET expression RBRACKET.
postfix_expression ::= postfix_expression LPARENS RPARENS.
postfix_expression ::= postfix_expression LPARENS argument_expression_list RPARENS.
postfix_expression ::= postfix_expression DOT IDENTIFIER.
postfix_expression ::= postfix_expression PTR_OP IDENTIFIER.
postfix_expression ::= postfix_expression INC_OP.
postfix_expression ::= postfix_expression DEC_OP.

argument_expression_list ::= assignment_expression.
argument_expression_list ::= argument_expression_list COMMA assignment_expression.


unary_expression ::= postfix_expression.
unary_expression ::= INC_OP unary_expression.
unary_expression ::= DEC_OP unary_expression.
unary_expression ::= unary_operator cast_expression.
unary_expression ::= SIZEOF unary_expression.
unary_expression ::= SIZEOF LPARENS type_name RPARENS.

unary_operator ::= AND.
unary_operator ::= MULT.
unary_operator ::= PLUS.
unary_operator ::= MINUS.
unary_operator ::= TILDE.
unary_operator ::= BANG.

cast_expression ::= unary_expression.
cast_expression ::= LPARENS type_name RPARENS cast_expression.


multiplicative_expression ::= cast_expression.
multiplicative_expression ::= multiplicative_expression MULT cast_expression.
multiplicative_expression ::=  multiplicative_expression DIV cast_expression.
multiplicative_expression ::= multiplicative_expression MOD cast_expression.

additive_expression ::= multiplicative_expression.
additive_expression ::= additive_expression PLUS multiplicative_expression.
additive_expression ::= additive_expression MINUS multiplicative_expression.


shift_expression ::= additive_expression.
shift_expression ::= shift_expression LEFT_OP additive_expression.
shift_expression ::= shift_expression RIGHT_OP additive_expression.


relational_expression ::= shift_expression.
relational_expression ::= relational_expression LESS shift_expression.
relational_expression ::= relational_expression MORE shift_expression.
relational_expression ::= relational_expression LE_OP shift_expression.
relational_expression ::= relational_expression GE_OP shift_expression.


equality_expression ::= relational_expression.
equality_expression ::=equality_expression EQ_OP relational_expression.
equality_expression ::=equality_expression NE_OP relational_expression.


and_expression ::= equality_expression.
and_expression ::= and_expression AND equality_expression.


exclusive_or_expression ::= and_expression.
exclusive_or_expression ::= exclusive_or_expression XOR and_expression.


inclusive_or_expression ::= exclusive_or_expression.
inclusive_or_expression ::= inclusive_or_expression OR exclusive_or_expression.


logical_and_expression ::= inclusive_or_expression.
logical_and_expression ::= logical_and_expression ANDAND_OP inclusive_or_expression.


logical_or_expression ::= logical_and_expression.
logical_or_expression ::= logical_or_expression OROR_OP logical_and_expression.


conditional_expression ::= logical_or_expression.
conditional_expression ::= logical_or_expression QUESTIONMARK expression COLON conditional_expression.


assignment_expression ::= conditional_expression.
assignment_expression ::= unary_expression assignment_operator assignment_expression.


assignment_operator ::= EQUALS.
assignment_operator ::= MUL_ASSIGN.
assignment_operator ::= DIV_ASSIGN.
assignment_operator ::= MOD_ASSIGN.
assignment_operator ::= ADD_ASSIGN.
assignment_operator ::= SUB_ASSIGN.
assignment_operator ::= LEFT_ASSIGN.
assignment_operator ::= RIGHT_ASSIGN.
assignment_operator ::= AND_ASSIGN.
assignment_operator ::= XOR_ASSIGN.
assignment_operator ::= OR_ASSIGN.


expression ::= assignment_expression.
expression ::= expression COMMA assignment_expression.

constant_expression ::= conditional_expression.


declaration ::= declaration_specifiers SEMICOLON.
declaration ::= declaration_specifiers init_declarator_list SEMICOLON.

declaration_specifiers ::= storage_class_specifier.
declaration_specifiers ::= storage_class_specifier declaration_specifiers.
declaration_specifiers ::= type_specifier.
declaration_specifiers ::= type_specifier declaration_specifiers.
declaration_specifiers ::= type_qualifier.
declaration_specifiers ::= type_qualifier declaration_specifiers.


init_declarator_list ::= init_declarator.
init_declarator_list ::= init_declarator_list COMMA init_declarator.


init_declarator ::= declarator.
init_declarator ::= declarator EQUALS initializer.


storage_class_specifier ::= TYPEDEF.
storage_class_specifier ::= EXTERN.
storage_class_specifier ::= STATIC.
/*
storage_class_specifier ::= AUTO.
storage_class_specifier ::= REGISTER.
*/


type_specifier ::= VOID.
type_specifier ::= CHAR.
type_specifier ::= SHORT.
type_specifier ::= INT.
type_specifier ::= LONG.
type_specifier ::= FLOAT.
type_specifier ::= DOUBLE.
type_specifier ::= SIGNED.
type_specifier ::= UNSIGNED.
type_specifier ::= struct_or_union_specifier.
type_specifier ::= enum_specifier.
type_specifier ::= TYPE_NAME.


struct_or_union_specifier ::= struct_or_union IDENTIFIER LBRACE struct_declaration_list RBRACE.
struct_or_union_specifier ::= struct_or_union LBRACE struct_declaration_list RBRACE.
struct_or_union_specifier ::= struct_or_union IDENTIFIER.


struct_or_union ::= STRUCT.
struct_or_union ::= UNION.


struct_declaration_list ::= struct_declaration.
struct_declaration_list ::= struct_declaration_list struct_declaration.


struct_declaration ::= specifier_qualifier_list struct_declarator_list SEMICOLON.


specifier_qualifier_list ::= type_specifier specifier_qualifier_list.
specifier_qualifier_list ::= type_specifier.
specifier_qualifier_list ::= type_qualifier specifier_qualifier_list.
specifier_qualifier_list ::= type_qualifier.


struct_declarator_list ::= struct_declarator.
struct_declarator_list ::= struct_declarator_list COMMA struct_declarator.

struct_declarator ::= declarator.
struct_declarator ::= COLON constant_expression.
struct_declarator ::= declarator COLON constant_expression.


enum_specifier ::= ENUM LBRACE enumerator_list RBRACE.
enum_specifier ::= ENUM IDENTIFIER LBRACE enumerator_list RBRACE.
enum_specifier ::= ENUM IDENTIFIER.


enumerator_list ::= enumerator.
enumerator_list ::= enumerator_list COMMA enumerator.


enumerator ::= IDENTIFIER.
enumerator ::= IDENTIFIER EQUALS constant_expression.

type_qualifier ::= CONST.
type_qualifier ::= VOLATILE.


declarator ::= pointer direct_declarator.
declarator ::= direct_declarator.


direct_declarator ::= IDENTIFIER.
direct_declarator ::= LPARENS declarator RPARENS.
direct_declarator ::= direct_declarator LBRACKET constant_expression RBRACE.
direct_declarator ::= direct_declarator LBRACKET RBRACE.
direct_declarator ::= direct_declarator LPARENS parameter_type_list RPARENS.
direct_declarator ::= direct_declarator LPARENS identifier_list RPARENS.
direct_declarator ::= direct_declarator LPARENS RPARENS.

pointer  ::= MULT.
pointer  ::= MULT type_qualifier_list.
pointer  ::= MULT pointer.
pointer  ::= MULT type_qualifier_list pointer.


type_qualifier_list ::= type_qualifier.
type_qualifier_list ::= type_qualifier_list type_qualifier.


parameter_type_list ::= parameter_list.
parameter_type_list ::= parameter_list COMMA ELLIPSIS.


parameter_list ::= parameter_declaration.
parameter_list ::= parameter_list COMMA parameter_declaration.


parameter_declaration ::= declaration_specifiers declarator.
parameter_declaration ::= declaration_specifiers abstract_declarator.
parameter_declaration ::= declaration_specifiers.


identifier_list ::= IDENTIFIER.
identifier_list ::= identifier_list COMMA IDENTIFIER.


type_name ::= specifier_qualifier_list.
type_name ::= specifier_qualifier_list abstract_declarator.


abstract_declarator ::= pointer.
abstract_declarator ::= direct_abstract_declarator.
abstract_declarator ::= pointer direct_abstract_declarator.


direct_abstract_declarator ::= LPARENS abstract_declarator RPARENS.
direct_abstract_declarator ::= LBRACE RBRACE.
direct_abstract_declarator ::= LBRACE constant_expression RBRACE.
direct_abstract_declarator ::= direct_abstract_declarator LBRACE RBRACE.
direct_abstract_declarator ::= direct_abstract_declarator LBRACE constant_expression RBRACE.
direct_abstract_declarator ::= LPARENS RPARENS.
direct_abstract_declarator ::= LPARENS parameter_type_list RPARENS.
direct_abstract_declarator ::= direct_abstract_declarator LPARENS RPARENS.
direct_abstract_declarator ::= direct_abstract_declarator LPARENS parameter_type_list RPARENS.


initializer ::= assignment_expression.
initializer ::= LBRACKET initializer_list RBRACKET.
initializer ::= LBRACKET initializer_list COMMA RBRACKET.


initializer_list ::= initializer.
initializer_list ::= initializer_list COMMA initializer.


statement ::= labeled_statement.
statement ::= compound_statement.
statement ::= expression_statement.
statement ::= selection_statement.
statement ::= iteration_statement.
statement ::= jump_statement.


labeled_statement ::= IDENTIFIER COLON statement.
labeled_statement ::= CASE constant_expression COLON statement.
labeled_statement ::= DEFAULT COLON statement.


compound_statement ::= LBRACKET RBRACKET.
compound_statement ::= LBRACKET statement_list RBRACKET.
compound_statement ::= LBRACKET declaration_list RBRACKET.
compound_statement ::= LBRACKET declaration_list statement_list RBRACKET.


declaration_list ::= declaration.
declaration_list ::= declaration_list declaration.


statement_list ::= statement.
statement_list ::= statement_list statement.


expression_statement ::= SEMICOLON.
expression_statement ::= expression SEMICOLON.


selection_statement ::= IF LPARENS expression RPARENS statement.
selection_statement ::= IF LPARENS expression RPARENS statement ELSE statement.
selection_statement ::= SWITCH LPARENS expression RPARENS statement.


iteration_statement ::= WHILE LPARENS expression RPARENS statement.
iteration_statement ::= DO statement WHILE LPARENS expression RPARENS SEMICOLON.
iteration_statement ::= FOR LPARENS expression_statement expression_statement RPARENS statement.
iteration_statement ::= FOR LPARENS expression_statement expression_statement expression RPARENS statement.


jump_statement ::= GOTO IDENTIFIER SEMICOLON.
jump_statement ::= CONTINUE SEMICOLON.
jump_statement ::= BREAK SEMICOLON.
jump_statement ::= RETURN SEMICOLON.
jump_statement ::= RETURN expression SEMICOLON.

brightc_file ::= translation_unit.

translation_unit ::= external_declaration.
translation_unit ::= translation_unit external_declaration.


external_declaration ::= function_definition.
external_declaration ::= declaration.


function_definition ::= declaration_specifiers declarator declaration_list compound_statement.
function_definition ::= declaration_specifiers declarator compound_statement.
function_definition ::= declarator declaration_list compound_statement.
function_definition ::= declarator compound_statement.
