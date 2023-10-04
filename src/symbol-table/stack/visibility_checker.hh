#pragma once

#include <unordered_map>
#include <string>
#include <stack>

class VisibilityChecker {
private:
    std::unordered_map<std::string, std::stack<int>> versions;
    std::stack<std::string> symbols_stack;
    int current_scope = 0;
    
public:
    void declare_var(std::string name);
    void push_scope();
    void pop_scope();
    bool is_visible(std::string name);
};