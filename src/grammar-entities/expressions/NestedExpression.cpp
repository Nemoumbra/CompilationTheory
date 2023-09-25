#include "NestedExpression.hh"

NestedExpr::NestedExpr(BaseExpression* expression) : expression_(expression) {}

void NestedExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}