#pragma once
#include <string>

#include "Statement.hh"
#include "Statements.hh"
#include "expressions/BaseExpression.hh"

class Conditional : public Statement {
public:
    std::shared_ptr<BaseExpression> expression_;
    std::shared_ptr<Statements> if_clause_;
    std::shared_ptr<Statements> else_clause_;

    Conditional(std::shared_ptr<BaseExpression> expression, 
                std::shared_ptr<Statements> if_clause,
                std::shared_ptr<Statements> else_clause,
                yy::location loc);

    void Accept(BaseVisitor* visitor);
};