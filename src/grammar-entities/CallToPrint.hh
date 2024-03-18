#pragma once

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class CallToPrint : public Statement {

public:
    std::shared_ptr<BaseExpression> expression_;
    CallToPrint(std::shared_ptr<BaseExpression> expression, yy::location loc);
    void Accept(BaseVisitor* visitor);
};