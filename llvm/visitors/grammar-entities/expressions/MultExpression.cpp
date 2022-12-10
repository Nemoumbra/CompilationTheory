#include "MultExpression.hh"

MultExpression::MultExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void MultExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}