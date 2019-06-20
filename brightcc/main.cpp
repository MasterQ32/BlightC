#include <iostream>
#include "src/io.hpp"
#include "src/parser.hpp"
#include <cctype>

int main(int argc, char ** argv)
{
    auto const main_file = IO::load_file(argv[1]);

    if(not main_file)
        return 1;

    std::string source(main_file->data(), main_file->size());

    Parser parser;

    if(not parser.parse(source)) {
        std::cerr << "Failed to parse the input file!" << std::endl;
        return 1;
    }

    return 0;
}
