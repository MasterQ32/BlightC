#include "parser.hpp"
#include "lemon-parser.h"

#include <cassert>

extern "C"
{
    void * BrightCParserAlloc(void *(*mallocProc)(size_t));
    void BrightCParser(
      void *yyp,                   /* The parser */
      int yymajor,                 /* The major token code number */
      void * yyminor       /* The value for the token */
      /* Optional %extra_argument parameter */
    );
    void BrightCParserFree(void *p,void (*freeProc)(void*));
}

Parser::Parser() :
    lemon(BrightCParserAlloc(malloc))
{
    assert(lemon != nullptr);
}

Parser::~Parser()
{
    BrightCParserFree(lemon, free);
}

void Parser::put(Token const & tok)
{
    BrightCParser(lemon, tok.type, nullptr);
}

void Parser::finalize()
{
    BrightCParser(lemon, 0, 0);
}
