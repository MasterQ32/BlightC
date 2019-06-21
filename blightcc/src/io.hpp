#ifndef IO_HPP
#define IO_HPP

#include <optional>
#include <vector>
#include <filesystem>

namespace IO
{
    using buffer = std::vector<char>;

    std::optional<buffer> load_file(std::filesystem::path const & path);
}

#endif // IO_HPP
