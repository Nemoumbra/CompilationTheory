#pragma once

#include "BaseExpression.hh"

class SubExpression : BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    SubExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};