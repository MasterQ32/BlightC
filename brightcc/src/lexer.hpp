#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <optional>
#include <array>
#include <variant>
#include "c_lexer.h"

constexpr static uint32_t operator"" _tok(char const * str, size_t len)
{
    switch(len)
    {
    case 0:  return 0;
    case 1:  return uint32_t(str[0]);
    case 2:  return uint32_t(str[0]) | (uint32_t(str[1]) << 8);
    case 3:  return uint32_t(str[0]) | (uint32_t(str[1]) << 8) | (uint32_t(str[2]) << 16);
    default: return uint32_t(str[0]) | (uint32_t(str[1]) << 8) | (uint32_t(str[2]) << 16) | (uint32_t(str[3]) << 24);
    }
}

struct Location
{
    int line, column;
};

struct Token
{
    uint32_t static constexpr Undefined        = 0;
    uint32_t static constexpr StringLiteral    = ~1U;
    uint32_t static constexpr CharacterLiteral = ~2U;
    uint32_t static constexpr DoubleLiteral    = ~3U;
    uint32_t static constexpr IntLiteral       = ~4U;
    uint32_t static constexpr Identifier       = ~5U;

    uint32_t type;
    std::string text;
    std::variant<std::monostate, std::string, double, long> value;
    Location start, end;
};

struct Lexer
{
    stb_lexer stb;
    std::array<char, 4096> string_store;
    char const * last_parsepoint;
    int curcol, curline;

    explicit Lexer(const char *input_stream, size_t length);

    std::optional<Token> lex();

    void seek_to(char * pos);
};

#endif // LEXER_HPP
