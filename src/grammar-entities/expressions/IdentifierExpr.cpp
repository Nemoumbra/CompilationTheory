#include "IdentifierExpr.hh"

IdentifierExpr::IdentifierExpr(
    const std::string& identifier,
    yy::location loc
    ) :
    BaseExpression(loc),
    identifier_(identifier) {}

void IdentifierExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}