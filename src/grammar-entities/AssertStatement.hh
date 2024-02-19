#pragma once

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class AssertStatement : public Statement {
public:
    std::shared_ptr<BaseExpression> expression_;

    AssertStatement(
        std::shared_ptr<BaseExpression> expression,
        yy::location loc
    );
    void Accept(BaseVisitor* visitor);
};