#include "NestedExpression.hh"

NestedExpr::NestedExpr(std::shared_ptr<BaseExpression> expression) : expression_(expression) {}

void NestedExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}