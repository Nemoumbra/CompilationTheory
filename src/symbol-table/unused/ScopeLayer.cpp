#include "ScopeLayer.hh"

#include <stdexcept>

std::shared_ptr<ScopeLayer> ScopeLayer::make_child(int list_index) {
    auto child = std::make_shared<ScopeLayer>();
    child->parent = this;
    child->list_index = list_index;

    children.push_back(child);
    return child;
}

ScopeLayer* ScopeLayer::get_parent() const {
    return parent;
}

ScopeLayer* ScopeLayer::get_child(size_t index) const {
    return children.at(index).get();
}

bool ScopeLayer::contains(Variable& var) {
    auto it = variables.find(var);
    if (it == variables.end()) {
        return false;
    }

    int index = it->first.list_index;
    return index < var.list_index;
}

bool ScopeLayer::is_visible(Variable& var) {
    ScopeLayer* current = this;
    while (!current->contains(var) && current->parent != nullptr) {
        var.list_index = current->list_index;
        current = current->parent;
    }
    return current->contains(var);
}

bool ScopeLayer::declare_var(Variable& var) {
    if (this->contains(var)) {
        // Redeclarations in the same scope are not allowed
        return false;
    }
    variables[var] = 0;
    return true;
}

int& ScopeLayer::operator[](Variable& var) {
    ScopeLayer* current = this;
    while (!current->contains(var) && current->parent != nullptr) {
        current = current->parent;
    }

    auto it = current->variables.find(var);
    if (it != current->variables.end()) {
        return it->second;
    }
    else {
        // This part is just me being extra cautious as it shouldn't happen
        throw std::runtime_error(
            "Variable '" + var.name + "' used before declaration"
        );
    }
}