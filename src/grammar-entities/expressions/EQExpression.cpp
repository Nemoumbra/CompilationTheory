#include "EQExpression.hh"

EQExpression::EQExpression(
    std::shared_ptr<BaseExpression> expr1,
    std::shared_ptr<BaseExpression> expr2,
    yy::location loc
    ) :
    BaseExpression(loc),
    first(expr1), second(expr2) {}

void EQExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}