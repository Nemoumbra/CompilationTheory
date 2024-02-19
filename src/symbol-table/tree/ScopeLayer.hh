#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "../../symbols/variable.hh"


class ScopeLayer {
private:
    std::vector<std::shared_ptr<ScopeLayer>> children;
    ScopeLayer* parent = nullptr;
    int list_index;

    std::unordered_map<Variable, int> variables;
public:
    bool contains(Variable& var);
    bool is_visible(Variable& var);
    std::shared_ptr<ScopeLayer> make_child(int list_index);
    ScopeLayer* get_parent() const;
    ScopeLayer* get_child(size_t index) const;
    
    bool declare_var(Variable& var);
    int& operator[](Variable& var);
};
