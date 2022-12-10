#pragma once

#include "BaseExpression.hh"

class GTExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    GTExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};