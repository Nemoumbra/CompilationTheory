#include "ContinueStatement.hh"

ContinueStatement::ContinueStatement(yy::location loc) {
    location = loc;
}

void ContinueStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}
