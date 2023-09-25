#include "AddExpression.hh"

AddExpression::AddExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void AddExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}