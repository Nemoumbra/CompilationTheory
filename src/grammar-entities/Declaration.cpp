#include "Declaration.hh"

Declaration::Declaration(
    const std::string& identifier,
    yy::location loc
    ) :
    Statement(loc),
    identifier_(identifier) {}

void Declaration::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}