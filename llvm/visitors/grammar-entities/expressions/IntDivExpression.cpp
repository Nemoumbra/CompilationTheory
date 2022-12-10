#include "IntDivExpression.hh"

IntDivExpression::IntDivExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void IntDivExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}