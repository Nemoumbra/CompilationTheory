#include "CallToPrint.hh"

CallToPrint::CallToPrint(std::shared_ptr<BaseExpression> expression) : expression_(expression) {}

void CallToPrint::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}