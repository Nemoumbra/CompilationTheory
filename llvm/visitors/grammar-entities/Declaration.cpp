#include "Declaration.hh"

Declaration::Declaration(const std::string& identifier) : identifier_(identifier) {}

void Declaration::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}