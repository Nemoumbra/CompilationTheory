#include "ScopeLayer.hh"

#include <stdexcept>

std::shared_ptr<ScopeLayer> ScopeLayer::make_child() {
    auto child = std::make_shared<ScopeLayer>();
    child->parent = this;

    children.push_back(child);
    return child;
}

ScopeLayer* ScopeLayer::get_parent() const {
    return parent;
}

ScopeLayer* ScopeLayer::get_child(size_t index) const {
    return children.at(index).get();
}

bool ScopeLayer::contains(std::string name) {
    return variables.find(name) != variables.end();
}

bool ScopeLayer::is_visible(std::string name) {
    ScopeLayer* current = this;
    while (!current->contains(name) && current->parent != nullptr) {
        current = current->parent;
    }
    return current->contains(name);
}

bool ScopeLayer::declare_var(std::string name) {
    if (this->contains(name)) {
        // Redeclarations in the same scope are not allowed
        return false;
    }
    variables[name] = 0;
    return true;
}

int& ScopeLayer::operator[](std::string name) {
    ScopeLayer* current = this;
    while (!current->contains(name) && current->parent != nullptr) {
        current = current->parent;
    }

    auto it = current->variables.find(name);
    if (it != current->variables.end()) {
        return it->second;
    }
    else {
        // This part is just me being extra cautious as it shouldn't happen
        throw std::runtime_error(
            "Variable '" + name + "' used before declaration"
        );
    }
}