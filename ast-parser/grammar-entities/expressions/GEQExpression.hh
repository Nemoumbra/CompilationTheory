#pragma once

#include "BaseExpression.hh"

class GEQExpression : public BaseExpression {
public:
    BaseExpression* first;
    BaseExpression* second;

    GEQExpression(BaseExpression* expr1, BaseExpression* expr2);
    void Accept(BaseVisitor* visitor);
};