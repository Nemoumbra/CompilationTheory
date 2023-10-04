#include "RemainderExpression.hh"

RemainderExpression::RemainderExpression(std::shared_ptr<BaseExpression> expr1, std::shared_ptr<BaseExpression> expr2) : first(expr1), second(expr2) {}


void RemainderExpression::Accept(BaseVisitor *visitor)
{
    visitor->Visit(this);
}