#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "bison-parser.tab.hh"

#include <string>
#include <map>

struct Parser
{
private:
    yy::parser bison;
    Lexer * lexer;

public:
    explicit Parser();
    Parser(Parser const &) = delete;
    ~Parser();


    void parse(Lexer & lex);

    yy::parser::symbol_type get_next_token();

    int result;
    std::map<std::string, int> variables;
};

#endif // PARSER_HPP
