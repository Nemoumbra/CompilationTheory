#include "EQExpression.hh"

EQExpression::EQExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void EQExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}