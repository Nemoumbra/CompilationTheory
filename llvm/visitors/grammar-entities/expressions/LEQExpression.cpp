#include "LEQExpression.hh"

LEQExpression::LEQExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void LEQExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}