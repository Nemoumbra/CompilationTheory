#pragma once

#include "BaseExpression.hh"

class NumberExpression {
private:
    int value_;
public:
    explicit NumberExpression(int value);

    void Accept(BaseVisitor* visitor);
};