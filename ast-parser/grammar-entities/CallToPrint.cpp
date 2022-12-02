#include "CallToPrint.hh"

CallToPrint::CallToPrint(BaseExpression* expression) : expression_(expression) {}

void CallToPrint::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}