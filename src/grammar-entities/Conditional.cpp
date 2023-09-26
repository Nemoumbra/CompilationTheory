#include "Conditional.hh"

Conditional::Conditional(std::shared_ptr<BaseExpression> expression,
                        std::shared_ptr<Statements> if_clause,
                        std::shared_ptr<Statements> else_clause) :
    expression_(expression), if_clause_(if_clause), else_clause_(else_clause) {}

void Conditional::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}