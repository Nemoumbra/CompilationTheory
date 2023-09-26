#include "Conditional.hh"

Conditional::Conditional(BaseExpression* expression, Statements* if_clause, Statements* else_clause) :
    expression_(expression), if_clause_(if_clause), else_clause_(else_clause) {}

void Conditional::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}