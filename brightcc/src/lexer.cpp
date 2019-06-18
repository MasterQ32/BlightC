#define STB_C_LEXER_IMPLEMENTATION
#include "lexer.hpp"

#include <cstring>

Lexer::Lexer(const char *input_stream, size_t length)
{
    memset(string_store.data(), 0, string_store.size());
    stb_c_lexer_init(
        &stb,
        input_stream,
        input_stream + length,
        string_store.data(),
        string_store.size()
    );
}

std::optional<Token> Lexer::lex()
{
    //   - lexer->token is the token ID, which is unicode code point for a single-char token, < 0 for a multichar or eof or error
    //   - lexer->real_number is a double constant value for CLEX_floatlit, or CLEX_intlit if STB_C_LEX_INTEGERS_AS_DOUBLES
    //   - lexer->int_number is an integer constant for CLEX_intlit if !STB_C_LEX_INTEGERS_AS_DOUBLES, or character for CLEX_charlit
    //   - lexer->string is a 0-terminated string for CLEX_dqstring or CLEX_sqstring or CLEX_identifier
    //   - lexer->string_len is the byte length of lexer->string

    if(auto const p = stb_c_lexer_get_token(&stb); p == 0)
        return std::nullopt;
    Token tok;
    tok.type = stb.token;
    tok.text = std::string(stb.where_firstchar, stb.where_lastchar + 1);
    switch(stb.token)
    {
    case CLEX_floatlit:
        tok.value = stb.real_number;
        tok.type = Token::DoubleLiteral;
        break;
    case CLEX_intlit:
        tok.value = stb.int_number;
        tok.type = Token::IntLiteral;
        break;
    case CLEX_dqstring:
    case CLEX_id:
    // case CLEX_sqstring:
        if(stb.token == CLEX_dqstring)
            tok.type = Token::StringLiteral;
        else
            tok.type = Token::Identifier;

        tok.value = std::string(stb.string);
        break;

#define TRIVIAL(_Type, _Str) \
        case _Type: tok.type = _Str ## _tok; break

        TRIVIAL(CLEX_eq, "==");
        TRIVIAL(CLEX_noteq, "!=");
        TRIVIAL(CLEX_lesseq, "<=");
        TRIVIAL(CLEX_greatereq, ">=");
        TRIVIAL(CLEX_andand, "&&");
        TRIVIAL(CLEX_oror, "||");
        TRIVIAL(CLEX_shl, "<<");
        TRIVIAL(CLEX_shr, ">>");
        TRIVIAL(CLEX_plusplus, "++");
        TRIVIAL(CLEX_minusminus, "--");
        TRIVIAL(CLEX_pluseq, "+=");
        TRIVIAL(CLEX_minuseq, "-=");
        TRIVIAL(CLEX_muleq, "*=");
        TRIVIAL(CLEX_diveq, "/=");
        TRIVIAL(CLEX_modeq, "%=");
        TRIVIAL(CLEX_andeq, "&=");
        TRIVIAL(CLEX_oreq, "|=");
        TRIVIAL(CLEX_xoreq, "^=");
        TRIVIAL(CLEX_arrow, "->");
        // TRIVIAL(CLEX_eqarrow, "=>");

        TRIVIAL(CLEX_shleq, "<<=");
        TRIVIAL(CLEX_shreq, ">>=");
    }
    return std::move(tok);
}
