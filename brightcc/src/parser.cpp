#include "parser.hpp"

#include <cassert>

Parser::Parser() :
    bison(*this)
{

}

Parser::~Parser()
{

}

void Parser::parse()
{
    auto const result = bison.parse();
}
