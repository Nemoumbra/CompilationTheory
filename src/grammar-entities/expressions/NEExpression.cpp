#include "NEExpression.hh"

NEExpression::NEExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void NEExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}