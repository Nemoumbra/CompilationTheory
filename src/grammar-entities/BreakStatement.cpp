#include "BreakStatement.hh"

void BreakStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}
