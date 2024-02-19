#include "AssertStatement.hh"

AssertStatement::AssertStatement(
    std::shared_ptr<BaseExpression> expression,
    yy::location loc
) : expression_(expression)
{
    location = loc;
}

void AssertStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}