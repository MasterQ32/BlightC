#include "parser.hpp"

#include <cassert>

Parser::Parser() :
    bison(*this)
{

}

Parser::~Parser()
{

}

bool Parser::parse(Lexer & lex)
{
    lexer = &lex;
    auto const result = bison.parse();
    lexer = nullptr;

    return result == 0;
}

yy::parser::symbol_type Parser::get_next_token()
{
    assert(lexer != nullptr);
    auto const tok = lexer->lex();
    if(not tok)
        return yy::parser::symbol_type { 0, yy::location { } };

    std::cout << "[" << tok->text << "]" << std::flush;

    yy::position const start(nullptr, tok->start.line, tok->start.column);
    yy::position const end(nullptr, tok->end.line, tok->end.column);

    yy::location const loc(start, end);

    switch(tok->type)
    {
    case Token::IntLiteral:
        return yy::parser::make_INT_CONSTANT(loc);
    case Token::DoubleLiteral:
        return yy::parser::make_REAL_CONSTANT(loc);
    case Token::StringLiteral:
        return yy::parser::make_STRING_LITERAL(loc);

    case Token::Identifier:
        // %token AUTO REGISTER RESTRICT
        // %token ELLIPSIS

        if(tok->text == "extern")
            return yy::parser::make_EXTERN(loc);
        else if(tok->text == "export")
            return yy::parser::make_EXPORT(loc);
        else if(tok->text == "static")
            return yy::parser::make_STATIC(loc);
        else if(tok->text == "while")
            return yy::parser::make_WHILE(loc);
        else if(tok->text == "if")
            return yy::parser::make_IF(loc);
        else if(tok->text == "for")
            return yy::parser::make_FOR(loc);
        else if(tok->text == "else")
            return yy::parser::make_ELSE(loc);
        else if(tok->text == "do")
            return yy::parser::make_DO(loc);
        else if(tok->text == "switch")
            return yy::parser::make_SWITCH(loc);
        else if(tok->text == "bool")
            return yy::parser::make_BOOL(loc);
        else if(tok->text == "char")
            return yy::parser::make_CHAR(loc);
        else if(tok->text == "short")
            return yy::parser::make_SHORT(loc);
        else if(tok->text == "int")
            return yy::parser::make_INT(loc);
        else if(tok->text == "long")
            return yy::parser::make_LONG(loc);
        else if(tok->text == "unsigned")
            return yy::parser::make_UNSIGNED(loc);
        else if(tok->text == "signed")
            return yy::parser::make_SIGNED(loc);
        else if(tok->text == "float")
            return yy::parser::make_FLOAT(loc);
        else if(tok->text == "double")
            return yy::parser::make_DOUBLE(loc);
        else if(tok->text == "const")
            return yy::parser::make_CONST(loc);
        else if(tok->text == "volatile")
            return yy::parser::make_VOLATILE(loc);
        else if(tok->text == "void")
            return yy::parser::make_VOID(loc);
        else if(tok->text == "inline")
            return yy::parser::make_INLINE(loc);
        else if(tok->text == "typedef")
            return yy::parser::make_TYPEDEF(loc);
        else if(tok->text == "inline")
            return yy::parser::make_INLINE(loc);
        else if(tok->text == "struct")
            return yy::parser::make_STRUCT(loc);
        else if(tok->text == "union")
            return yy::parser::make_UNION(loc);
        else if(tok->text == "enum")
            return yy::parser::make_ENUM(loc);
        else if(tok->text == "case")
            return yy::parser::make_CASE(loc);
        else if(tok->text == "default")
            return yy::parser::make_DEFAULT(loc);
        else if(tok->text == "goto")
            return yy::parser::make_GOTO(loc);
        else if(tok->text == "continue")
            return yy::parser::make_CONTINUE(loc);
        else if(tok->text == "break")
            return yy::parser::make_BREAK(loc);
        else if(tok->text == "return")
            return yy::parser::make_RETURN(loc);
        else if(tok->text == "async")
            return yy::parser::make_ASYNC(loc);
        else if(tok->text == "await")
            return yy::parser::make_AWAIT(loc);

        return yy::parser::make_IDENTIFIER(loc);


    case "("_tok:
    case ")"_tok:
    case "["_tok:
    case "]"_tok:
    case "{"_tok:
    case "}"_tok:
    case "*"_tok:
    case "+"_tok:
    case "-"_tok:
    case "/"_tok:
    case "%"_tok:
    case "&"_tok:
    case "|"_tok:
    case "^"_tok:
    case ";"_tok:
    case "="_tok:
    case "!"_tok:
    case ","_tok:
    case "?"_tok:
    case ":"_tok:
    case ">"_tok:
    case "<"_tok:
        return yy::parser::symbol_type(tok->type, loc);

    case "++"_tok: return yy::parser::make_INC_OP(loc);
    case "--"_tok: return yy::parser::make_DEC_OP(loc);

    case "->"_tok: return yy::parser::make_PTR_OP(loc);
    case "=="_tok: return yy::parser::make_EQ_OP(loc);
    case "!="_tok: return yy::parser::make_NE_OP(loc);
    case ">="_tok: return yy::parser::make_GE_OP(loc);
    case "<="_tok: return yy::parser::make_LE_OP(loc);

    case "+="_tok: return yy::parser::make_ADD_ASSIGN(loc);
    case "-="_tok: return yy::parser::make_SUB_ASSIGN(loc);
    case "*="_tok: return yy::parser::make_MUL_ASSIGN(loc);
    case "/="_tok: return yy::parser::make_DIV_ASSIGN(loc);
    case "%="_tok: return yy::parser::make_MOD_ASSIGN(loc);
    case "|="_tok: return yy::parser::make_OR_ASSIGN(loc);
    case "&="_tok: return yy::parser::make_AND_ASSIGN(loc);
    case "^="_tok: return yy::parser::make_XOR_ASSIGN(loc);
    case "<<="_tok: return yy::parser::make_LEFT_ASSIGN(loc);
    case ">>="_tok: return yy::parser::make_RIGHT_ASSIGN(loc);

    default:
        assert(false and "unhandled token type!");
    }
}
