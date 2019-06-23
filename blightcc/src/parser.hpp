#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <map>
#include <queue>

extern "C" typedef struct rpastat_s rpastat_t;

struct Parser
{
private:
    rpastat_t * stat;

public:
    explicit Parser();
    Parser(Parser const &) = delete;
    ~Parser();


    bool parse(std::string const & fileData);

    bool enable_blightc = true;
};

#endif // PARSER_HPP
