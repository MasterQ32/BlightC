#include <iostream>
#include "src/lexer.hpp"
#include "src/io.hpp"
#include "src/parser.hpp"
#include <cctype>

int main(int argc, char ** argv)
{
    auto const main_file = IO::load_file(argv[1]);

    if(not main_file)
        return 1;

    Lexer lexer(main_file->data(), main_file->size());

    Parser parser;

    if(not parser.parse(lexer)) {
        std::cerr << "Failed to parse the input file!" << std::endl;
        return 1;
    }

//    std::optional<Token> tok;
//    while((tok = lexer.lex()))
//    {
//        std::cout << int(tok->type);
//        if(isprint(int(tok->type)))
//            std::cout << "/'" << char(tok->type) << "'";

//        std::cout << "\t\"" << tok->text << "\"";

//        std::visit([](auto val) {
//            if constexpr(not std::is_same_v<decltype (val), std::monostate>)
//                std::cout << "\t('" << val << "')";
//        }, tok->value);
//        std::cout << std::endl;
//    }

    return 0;
}
