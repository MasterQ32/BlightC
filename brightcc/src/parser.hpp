#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"

struct Parser
{
    void * lemon;

    explicit Parser();
    Parser(Parser const &) = delete;
    ~Parser();


    void put(Token const & tok);

    void finalize();
};

#endif // PARSER_HPP
