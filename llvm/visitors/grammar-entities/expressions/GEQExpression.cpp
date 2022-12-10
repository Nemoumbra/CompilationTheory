#include "GEQExpression.hh"

GEQExpression::GEQExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void GEQExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}