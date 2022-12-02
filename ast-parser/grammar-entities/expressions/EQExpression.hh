#pragma once

#include "BaseExpression.hh"

class EQExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    EQExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};