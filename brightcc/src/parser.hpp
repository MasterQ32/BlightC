#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "bison-parser.tab.hh"

#include <string>
#include <map>

struct Parser
{
    yy::parser bison;

    explicit Parser();
    Parser(Parser const &) = delete;
    ~Parser();


    void parse();

    int result;
    std::map<std::string, int> variables;
};

#endif // PARSER_HPP
