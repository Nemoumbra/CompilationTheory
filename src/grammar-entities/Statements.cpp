#include "Statements.hh"

void Statements::AddStatement(std::shared_ptr<Statement> statement) {
    auto& placed = statements_.emplace_back(statement);
    placed->index_in_list = statements_.size() - 1;
}

void Statements::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}