#pragma once

#include <string>

#include "BaseExpression.hh"

class NestedExpr : BaseExpression {
public:
    BaseExpression* expression_;

    NestedExpr(BaseExpression* expression);

    void Accept(BaseVisitor* visitor);
};