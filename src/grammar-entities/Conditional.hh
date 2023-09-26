#pragma once
#include <string>

#include "Statement.hh"
#include "Statements.hh"
#include "expressions/BaseExpression.hh"

class Conditional : public Statement {
public:
    BaseExpression* expression_;
    Statements* if_clause_;
    Statements* else_clause_;

    Conditional(BaseExpression* expression, Statements* if_clause, Statements* else_clause);

    void Accept(BaseVisitor* visitor);
};