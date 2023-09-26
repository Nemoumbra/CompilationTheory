#include "MultExpression.hh"

MultExpression::MultExpression(std::shared_ptr<BaseExpression> expr1, std::shared_ptr<BaseExpression> expr2) : first(expr1), second(expr2) {}

void MultExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}