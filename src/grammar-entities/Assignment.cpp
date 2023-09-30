#include "Assignment.hh"

Assignment::Assignment(
    const std::string& identifier,
    std::shared_ptr<BaseExpression> expression,
    yy::location loc
) : identifier_(identifier), expression_(expression)
{
    location = loc;
}

void Assignment::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}