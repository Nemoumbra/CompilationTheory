#include "AssertStatement.hh"

AssertStatement::AssertStatement(
    std::shared_ptr<BaseExpression> expression,
    yy::location loc
    ) : 
    Statement(loc),
    expression_(expression) {}


void AssertStatement::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}