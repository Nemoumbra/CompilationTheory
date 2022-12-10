#pragma once

#include "BaseExpression.hh"

class LTExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    LTExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};