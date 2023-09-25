#include "LTExpression.hh"

LTExpression::LTExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void LTExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}