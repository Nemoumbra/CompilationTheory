#pragma once

#include "BaseExpression.hh"

class IntDivExpression : BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    IntDivExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};