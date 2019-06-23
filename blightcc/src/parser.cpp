#include "parser.hpp"
#include "io.hpp"

#include <cassert>
#include <memory>
#include <iostream>
#include <rpa/rpa.h>
#include <rpa/rpadbex.h>
#include <rpa/rpastat.h>

namespace /* private */
{
    using dbex_ptr = std::unique_ptr<rpadbex_t, decltype(&rpa_dbex_destroy)>;

    std::optional<dbex_ptr> grammar_data;

    static char const * code_to_string(long code)
    {
        switch(code) {
            case RPA_E_NONE: return "No error";
            case RPA_E_OUTOFMEM: return "Not enough memory";
            case RPA_E_NOTCOMPILED: return "The database is not yet compiled to byte code. Some of the operations are not possible until the call to @ref rpa_dbex_compile is made.";
            case RPA_E_NOTOPEN: return "The database is not open. Use @ref rpa_dbex_open to open it.";
            case RPA_E_NOTCLOSED: return "The database is not closed. Use @ref rpa_dbex_close to close it.";
            case RPA_E_NOTFOUND: return "The specified rule cannot be found";
            case RPA_E_SYNTAXERROR: return "Syntax Error. Check the BNF syntax.";
            case RPA_E_UNRESOLVEDSYMBOL: return "A rule name is used in the BNF specification, but it is not defined";
            case RPA_E_PARAM: return "Invalid parameter";
            case RPA_E_COMPILE: return "Compile error";

            case RPA_E_EXECUTION: return "Execution error";
            case RPA_E_USERABORT: return "Operation is interrupted by user";
            case RPA_E_RULEABORT: return "If a rule is set to abort with the directive #!abort, if it cannot be matched the engine will generate this error";
            case RPA_E_INVALIDINPUT: return "Invalid input was specified";
        }
        return nullptr;
    }

    static void print_error(rpa_errinfo_t const & err)
    {
        std::cerr << "error:";

        if(err.mask & RPA_ERRINFO_CODE) {
            std::cerr << " code=";
            if(auto str = code_to_string(err.code); str != nullptr)
                std::cerr << "'" << str << "'" ;
            else
                std::cerr << err.code;
        }
        if(err.mask & RPA_ERRINFO_OFFSET)
            std::cerr << " offset=" << err.offset;
        if(err.mask & RPA_ERRINFO_LINE)
            std::cerr << " line=" << err.line;
        if(err.mask & RPA_ERRINFO_RULEUID)
            std::cerr << " ruleid=" << err.ruleuid;
        if(err.mask & RPA_ERRINFO_NAME)
            std::cerr << " name=" << err.name;
        std::cerr << std::endl;
    }

    static void print_dbex_error(rpadbex_t * dbex)
    {
        rpa_errinfo_t err;
        if(rpa_dbex_lasterrorinfo(dbex, &err) < 0) {
            std::cerr << "error: failed to get error info!" << std::endl;
            return;
        }
        print_error(err);
    }

    static void print_stat_error(rpastat_t * stat)
    {
        rpa_errinfo_t err;
        if(rpa_stat_lasterrorinfo(stat, &err) < 0) {
            std::cerr << "error: failed to get error info!" << std::endl;
            return;
        }
        print_error(err);
    }

    rpadbex_t * dbex()
    {
        if(not grammar_data)
        {
            auto const data = IO::load_file("/home/felix/projects/bright-c/blightcc/src/blight-c.bnf");
            assert(data);

            dbex_ptr dbex(rpa_dbex_create(), rpa_dbex_destroy);
            assert(dbex != nullptr);

            if(rpa_dbex_open(dbex.get()) < 0) {
                print_dbex_error(dbex.get());
                return nullptr;
            }

            if(rpa_dbex_load(dbex.get(), data->data(), data->size()) < 0) {
                print_dbex_error(dbex.get());
                return nullptr;
            }

            rpa_dbex_close(dbex.get());

            if(rpa_dbex_compile(dbex.get()) < 0) {
                print_dbex_error(dbex.get());
                return nullptr;
            }

            // rpa_dbex_dumpproductions(dbex.get());

            grammar_data.emplace(std::move(dbex));
        }
        assert(grammar_data);
        return grammar_data->get();
    }
}

Parser::Parser() :
    stat(rpa_stat_create(dbex(), RPA_DEFAULT_STACKSIZE))
{
    assert(stat != nullptr);
}

Parser::~Parser()
{
    rpa_stat_destroy(stat);
}

bool Parser::parse(std::string const & fileData)
{
    std::unique_ptr<rarray_t, decltype(&rpa_records_destroy)> records(rpa_records_create(), rpa_records_destroy);
    assert(records);

    auto const start_rule = enable_blightc
        ? rpa_dbex_lookup_s(dbex(), "blightc_translation_unit")
        : rpa_dbex_lookup_s(dbex(), "lightc_translation_unit")
        ;

    auto const parse_error = rpa_stat_parse(
        stat,
        start_rule,
        RPA_ENCODING_UTF8,
        fileData.c_str(),
        fileData.c_str(),
        fileData.c_str() + fileData.size(),
        records.get()
    );
    if(parse_error < 0) {
        print_stat_error(stat);
        return false;
    }

    std::cout << parse_error << std::endl;

    for (int i = 0; i < rpa_records_length(records.get()); i++) {
        auto record = rpa_records_slot(records.get(), i);


//        if (record->type == RPA_RECORD_START)
//            fprintf(stdout, "RPA_RECORD_START   (UID: %d)  ", record->ruleuid);
//        if (record->type == RPA_RECORD_END)
//            fprintf(stdout, "RPA_RECORD_END     (UID: %d)  ", record->ruleuid);
        /*
         * record->rule points to memory allocated by rpadbex_t,
         * make sure rpadbex_t object is not destroyed while accessing this pointer.
         */
//        fprintf(stdout, "%s: ", record->rule);
//        fwrite(record->input, 1, record->inputsiz, stdout);
//        fprintf(stdout, "\n");
    }

    if(parse_error == 0) {
        print_stat_error(stat);
        return false;
    }

    if(parse_error != fileData.size()) {

        int line = 1;
        int column = 1;
        for(size_t i = 0; i < parse_error; i++)
        {
            if(fileData[i] == '\n') {
                line++;
                column = 1;
            } else {
                column += 1;
            }
        }

        std::cout << "syntax error at position " << line << ":" << column << std::endl;
        return false;
    }

    return true;
}
