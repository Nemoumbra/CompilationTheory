#pragma once

#include "BaseExpression.hh"

class AddExpression : BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    AddExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};