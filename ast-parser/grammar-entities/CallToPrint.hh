#pragma once

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class CallToPrint : Statement {
    // Grammar rule:
    // "print" "(" expression ")" ";" { /* code */ }
private:
    BaseExpression* expression_;
public:
    CallToPrint(BaseExpression* expression);
    void Accept(BaseVisitor* visitor);
};