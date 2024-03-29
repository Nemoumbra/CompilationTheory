#include "LEQExpression.hh"

LEQExpression::LEQExpression(
    std::shared_ptr<BaseExpression> expr1,
    std::shared_ptr<BaseExpression> expr2,
    yy::location loc
    ) :
    BaseExpression(loc),
    first(expr1), second(expr2) {}

void LEQExpression::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}