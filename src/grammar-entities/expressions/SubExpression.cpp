#include "SubExpression.hh"

SubExpression::SubExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void SubExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}