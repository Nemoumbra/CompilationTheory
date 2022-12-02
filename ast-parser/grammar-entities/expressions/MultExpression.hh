#pragma once

#include "BaseExpression.hh"

class MultExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    MultExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};