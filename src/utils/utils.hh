#pragma once

#include <string>
#include "../generated/location.hh"

std::string pos_to_str(const yy::position& pos);
std::string loc_to_str(const yy::location& loc);

enum class ControlFlowType {
    Standard,
    Continue,
    Break
};
