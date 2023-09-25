#include "Conditional.hh"

Conditional::Conditional(BaseExpression* expression, CondClause* if_clause, CondClause* else_clause) :
    expression_(expression), if_clause_(if_clause), else_clause_(else_clause) {}

void Conditional::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}