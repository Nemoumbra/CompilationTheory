#pragma once

#include "BaseExpression.hh"

class NEExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    NEExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};