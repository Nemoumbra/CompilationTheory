#pragma once

#include "BaseExpression.hh"

class LEQExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    LEQExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};