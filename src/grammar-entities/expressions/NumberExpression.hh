#pragma once

#include "BaseExpression.hh"

class NumberExpression : public BaseExpression {
public:
    int value_;
    explicit NumberExpression(int value, yy::location loc);

    void Accept(BaseVisitor* visitor);
};