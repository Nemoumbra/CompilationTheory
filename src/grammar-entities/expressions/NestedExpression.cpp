#include "NestedExpression.hh"

NestedExpr::NestedExpr(
    std::shared_ptr<BaseExpression> expression,
    yy::location loc
    ) :
    BaseExpression(loc),
    expression_(expression) {}


void NestedExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}