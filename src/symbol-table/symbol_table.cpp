#include "symbol_table.hh"
#include <stdexcept>

int& SymbolTable::operator[](std::string name) {
    return values[name].top();
}

void SymbolTable::declare_var(std::string name) {
    auto [it, _] = values.emplace(name, std::stack<int>());
    auto& stack = it->second;

    stack.push(0);

    symbols_stack.push(name);
}

void SymbolTable::push_scope() {
    symbols_stack.push("{");
}

void SymbolTable::pop_scope() {
    while (symbols_stack.top() != "{") {
        auto& top = symbols_stack.top();

        values[top].pop();
        if (values[top].empty()) {
            values.erase(top);
        }

        symbols_stack.pop();
    }

    // And pop the scope symbol
    symbols_stack.pop();
}
