#include "visibility_checker.hh"

#include <stdexcept>

void VisibilityChecker::declare_var(std::string name) {
    auto [it, _] = versions.emplace(name, std::stack<int>());
    auto& stack = it->second;

    if (stack.empty()) {
        stack.push(current_scope);
    }
    else {
        if (stack.top() == current_scope) {
            throw std::runtime_error("Variable '" + name + "' can't be redeclared in the same scope!");
        }
        stack.push(current_scope);
    }
    
    symbols_stack.push(name);
}

void VisibilityChecker::push_scope() {
    ++current_scope;
    symbols_stack.push("{");
}

void VisibilityChecker::pop_scope() {
    while (symbols_stack.top() != "{") {
        auto& top = symbols_stack.top();

        versions[top].pop();
        if (versions[top].empty()) {
            versions.erase(top);
        }
        
        symbols_stack.pop();
    }

    // And pop the scope symbol
    symbols_stack.pop();
    --current_scope;
}

bool VisibilityChecker::is_visible(std::string name) {
    return versions.find(name) != versions.end();
}
