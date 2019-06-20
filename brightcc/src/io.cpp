#include "io.hpp"
#include <cstdio>

std::optional<IO::buffer> IO::load_file(std::filesystem::path const & path)
{
    std::error_code error;
    if(not std::filesystem::exists(path, error))
        return std::nullopt;
    if(error)
        return std::nullopt;
    auto const size = std::filesystem::file_size(path, error);
    if(error)
        return std::nullopt;
    if(size == 0)
        return buffer { };

    buffer buf(size);

    FILE * f = fopen(path.c_str(), "rb");
    if(f == nullptr)
        return std::nullopt;

    if(fread(buf.data(), buf.size(), 1, f) == 0)
        return std::nullopt;

    fclose(f);

    return std::move(buf);
}
