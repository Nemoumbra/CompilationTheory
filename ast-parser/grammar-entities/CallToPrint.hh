#pragma once

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class CallToPrint : public Statement {
    // Grammar rule:
    // "print" "(" expression ")" ";" { /* code */ }
// private:

public:
    BaseExpression* expression_;
    CallToPrint(BaseExpression* expression);
    void Accept(BaseVisitor* visitor);
};