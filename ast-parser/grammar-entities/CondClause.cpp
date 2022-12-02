#include "CondClause.hh"

void CondClause::AddStatement(Statement* statement) {
    statements_.push_back(statement);
}
void CondClause::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}