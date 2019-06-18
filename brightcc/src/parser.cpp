#include "parser.hpp"

#include <cassert>

Parser::Parser() :
    bison(*this)
{

}

Parser::~Parser()
{

}

void Parser::parse(Lexer & lex)
{
    lexer = &lex;
    auto const result = bison.parse();
    lexer = nullptr;
}

yy::parser::symbol_type Parser::get_next_token()
{
    assert(lexer != nullptr);
    auto const tok = lexer->lex();
    if(not tok)
        return yy::parser::symbol_type { 0 };

    std::cout << "[" << tok->text << "]";

    switch(tok->type)
    {
    case Token::Identifier:
        // %token AUTO REGISTER RESTRICT
        // %token ELLIPSIS

        if(tok->text == "extern")
            return yy::parser::make_EXTERN();
        else if(tok->text == "export")
            return yy::parser::make_EXPORT();
        else if(tok->text == "static")
            return yy::parser::make_STATIC();
        else if(tok->text == "while")
            return yy::parser::make_WHILE();
        else if(tok->text == "if")
            return yy::parser::make_IF();
        else if(tok->text == "for")
            return yy::parser::make_FOR();
        else if(tok->text == "else")
            return yy::parser::make_ELSE();
        else if(tok->text == "do")
            return yy::parser::make_DO();
        else if(tok->text == "switch")
            return yy::parser::make_SWITCH();
        else if(tok->text == "bool")
            return yy::parser::make_BOOL();
        else if(tok->text == "char")
            return yy::parser::make_CHAR();
        else if(tok->text == "short")
            return yy::parser::make_SHORT();
        else if(tok->text == "int")
            return yy::parser::make_INT();
        else if(tok->text == "long")
            return yy::parser::make_LONG();
        else if(tok->text == "unsigned")
            return yy::parser::make_UNSIGNED();
        else if(tok->text == "signed")
            return yy::parser::make_SIGNED();
        else if(tok->text == "float")
            return yy::parser::make_FLOAT();
        else if(tok->text == "double")
            return yy::parser::make_DOUBLE();
        else if(tok->text == "const")
            return yy::parser::make_CONST();
        else if(tok->text == "volatile")
            return yy::parser::make_VOLATILE();
        else if(tok->text == "void")
            return yy::parser::make_VOID();
        else if(tok->text == "inline")
            return yy::parser::make_INLINE();
        else if(tok->text == "typedef")
            return yy::parser::make_TYPEDEF();
        else if(tok->text == "inline")
            return yy::parser::make_INLINE();
        else if(tok->text == "struct")
            return yy::parser::make_STRUCT();
        else if(tok->text == "union")
            return yy::parser::make_UNION();
        else if(tok->text == "enum")
            return yy::parser::make_ENUM();
        else if(tok->text == "case")
            return yy::parser::make_CASE();
        else if(tok->text == "default")
            return yy::parser::make_DEFAULT();
        else if(tok->text == "goto")
            return yy::parser::make_GOTO();
        else if(tok->text == "continue")
            return yy::parser::make_CONTINUE();
        else if(tok->text == "break")
            return yy::parser::make_BREAK();
        else if(tok->text == "return")
            return yy::parser::make_RETURN();
        else if(tok->text == "async")
            return yy::parser::make_ASYNC();
        else if(tok->text == "await")
            return yy::parser::make_AWAIT();

        return yy::parser::make_IDENTIFIER();


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
        return yy::parser::symbol_type(tok->type);
    case "->"_tok:
        return yy::parser::make_PTR_OP();

    default:
        assert(false and "unhandled token type!");
    }
}
