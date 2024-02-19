#pragma once

#include <string>

class Variable {
public:
    std::string name;
    int list_index;

    bool operator==(const Variable& other) const;
    bool operator!=(const Variable& other) const;
};

namespace std {
    template <>
    struct hash<Variable> {
        size_t operator()(const Variable& var) const {
            return hash<std::string>()(var.name);
        }
    };
}
