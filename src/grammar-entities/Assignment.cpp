#include "Assignment.hh"

Assignment::Assignment(
    const std::string& identifier,
    std::shared_ptr<BaseExpression> expression
) : identifier_(identifier), expression_(expression) {}

void Assignment::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}