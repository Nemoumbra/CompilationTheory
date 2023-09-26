#pragma once

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class CallToPrint : public Statement {

public:
    std::shared_ptr<BaseExpression> expression_;
    CallToPrint(std::shared_ptr<BaseExpression> expression);
    void Accept(BaseVisitor* visitor);
};