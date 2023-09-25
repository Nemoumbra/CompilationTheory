#include "Assignment.hh"

Assignment::Assignment(
    const std::string& identifier,
    BaseExpression* expression
) : identifier_(identifier), expression_(expression) {}

void Assignment::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}