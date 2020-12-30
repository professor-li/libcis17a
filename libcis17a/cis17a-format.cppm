export module cis17a.format;
import std.core;
import std.memory;

namespace cis17a {
    export template<typename ... Args>
        std::string format(const std::string& format, Args ... args)
    {
        int size = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        if (size <= 0) { throw std::runtime_error("Error during formatting."); }
        // use std::unique_ptr?
        char* buf{ new char[size] };
        try {
            std::snprintf(buf, size, format.c_str(), args ...);
        }
        catch (...)
        {
            delete[] buf;
            throw;
        }
        return std::string(buf, buf + size - 1); // We don't want the '\0' inside
    }
}
