#include "Statements.hh"

void Statements::AddStatement(std::shared_ptr<Statement> statement) {
    statements_.push_back(statement);
}

void Statements::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}