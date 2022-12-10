#include "NumberExpression.hh"

NumberExpression::NumberExpression(int value) : value_(value) {}

void NumberExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}