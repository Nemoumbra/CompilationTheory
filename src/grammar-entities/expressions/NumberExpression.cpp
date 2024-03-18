#include "NumberExpression.hh"

NumberExpression::NumberExpression(
    int value,
    yy::location loc
    ) :
    BaseExpression(loc),
    value_(value) {}

void NumberExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}