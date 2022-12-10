#pragma once

#include "BaseExpression.hh"

class NumberExpression : public BaseExpression {
// private:
//     int value_;
public:
    int value_;
    explicit NumberExpression(int value);

    void Accept(BaseVisitor* visitor);
};