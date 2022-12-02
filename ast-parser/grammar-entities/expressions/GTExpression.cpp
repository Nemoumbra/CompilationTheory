#include "GTExpression.hh"

GTExpression::GTExpression(BaseExpression* expr1, BaseExpression* expr2) : first(expr1), second(expr2) {}

void GTExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}