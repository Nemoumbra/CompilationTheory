#include "LTExpression.hh"

LTExpression::LTExpression(std::shared_ptr<BaseExpression> expr1, std::shared_ptr<BaseExpression> expr2) : first(expr1), second(expr2) {}

void LTExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}