
#include "utils.hh"

std::string loc_to_str(const yy::location& loc) {
    std::string res;
    const auto& start = loc.begin;

    if (start.filename) {
        (res += *start.filename) += ":";
    }
    ((res += std::to_string(start.line)) += ".") += std::to_string(start.column);
    return res;
}
