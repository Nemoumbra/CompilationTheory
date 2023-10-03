#include "BreakStatement.hh"

BreakStatement::BreakStatement(yy::location loc) {
    location = loc;
}

void BreakStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}
