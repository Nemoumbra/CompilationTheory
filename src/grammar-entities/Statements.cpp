#include "Statements.hh"

void Statements::AddStatement(BaseStatement* statement) {
    statements_.push_back(statement);
}
void Statements::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}