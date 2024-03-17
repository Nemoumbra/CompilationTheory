
#include "utils.hh"


std::string pos_to_str(const yy::position& pos) {
    std::string res;
    if (pos.filename) {
        (res += *pos.filename) += ":";
    }
    ((res += std::to_string(pos.line)) += ".") += std::to_string(pos.column);

    return res;
}

std::string loc_to_str(const yy::location& loc) {
    // We assume the start and end lie in the same file
    std::string res;
    const auto& start = loc.begin;
    const auto& end = loc.end;

    if (start.filename) {
        (res += *start.filename) += ":";
    }
    ((res += std::to_string(start.line)) += ".") += std::to_string(start.column);
    res += "-";
    ((res += std::to_string(end.line)) += ".") += std::to_string(end.column);
    return res;
}
