#include "IdentifierExpr.hh"

IdentifierExpr::IdentifierExpr(const std::string& identifier, yy::location loc) : identifier_(identifier) {
    location = loc;
}

void IdentifierExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}