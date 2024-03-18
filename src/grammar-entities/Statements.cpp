#include "Statements.hh"

void Statements::AddStatement(std::shared_ptr<Statement> statement) {
    statements_.push_back(statement);
    // Extend the location for another statement
    location.end = statement->location.end;
}

void Statements::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}