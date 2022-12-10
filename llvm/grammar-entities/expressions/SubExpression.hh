#pragma once

#include "BaseExpression.hh"

class SubExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    SubExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};