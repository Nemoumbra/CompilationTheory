#pragma once
#include <string>

#include "Statement.hh"
#include "CondClause.hh"
#include "expressions/BaseExpression.hh"

class Conditional : Statement {
    
public:
    BaseExpression* expression_;
    CondClause* if_clause_;
    CondClause* else_clause_;

    Conditional(BaseExpression* expression, CondClause* if_clause, CondClause* else_clause);

    void Accept(BaseVisitor* visitor);
};