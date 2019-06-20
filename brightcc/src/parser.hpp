#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <map>
#include <queue>

#include <rpa/rpa.h>
#include <rpa/rpastat.h>

struct Parser
{
private:
    rpastat_t * stat;

public:
    explicit Parser();
    Parser(Parser const &) = delete;
    ~Parser();


    bool parse(std::string const & fileData);
};

#endif // PARSER_HPP
