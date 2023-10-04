#pragma once

#include <string>
#include <unordered_map>
#include <stack>



class SymbolTable {
private:
    // For the interpreter
    std::unordered_map<std::string, std::stack<int>> values;

    std::stack<std::string> symbols_stack;

public:
    int& operator[](std::string name);
    void declare_var(std::string name);

    void push_scope();
    void pop_scope();
};