#pragma once

#include "Statement.hh"
#include "Statements.hh"
#include "expressions/BaseExpression.hh"

class PreLoop : public Statement {
public:
    std::shared_ptr<BaseExpression> expression_;
    std::shared_ptr<Statements> loop_body_;
    PreLoop(
        std::shared_ptr<BaseExpression> expression,
        std::shared_ptr<Statements> body,
        yy::location loc
        );
    
    void Accept(BaseVisitor* visitor);
};