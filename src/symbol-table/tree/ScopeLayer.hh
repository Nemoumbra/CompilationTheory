#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

class ScopeLayer {
private:
    std::vector<std::shared_ptr<ScopeLayer>> children;
    ScopeLayer* parent = nullptr;

    std::unordered_map<std::string, int> variables;
public:
    bool contains(std::string name);
    bool is_visible(std::string name);
    std::shared_ptr<ScopeLayer> make_child();
    ScopeLayer* get_parent() const;
    ScopeLayer* get_child(size_t index) const;
    
    bool declare_var(std::string name);
    int& operator[](std::string name);
};
