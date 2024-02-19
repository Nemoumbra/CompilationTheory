#include "variable.hh"

bool Variable::operator==(const Variable &other) const {
    return other.name == name && other.list_index == list_index;
}

bool Variable::operator!=(const Variable &other) const {
    return other.name != name || other.list_index != list_index;
}
