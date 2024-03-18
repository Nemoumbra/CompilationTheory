#include "ContinueStatement.hh"

void ContinueStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}
