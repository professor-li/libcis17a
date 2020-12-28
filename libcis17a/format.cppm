export module cis17a.format;

import std.core;
import std.memory;

namespace cis17a {
    export template<typename ... Args>
    std::string format(const std::string& format, Args ... args)
    {
        int size = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        if (size <= 0) { throw std::runtime_error("Error during formatting."); }
        std::unique_ptr<char[]> buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }
}
