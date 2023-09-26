#pragma once

#include <string>

#include "BaseExpression.hh"

class NestedExpr : public BaseExpression {
public:
    std::shared_ptr<BaseExpression> expression_;

    NestedExpr(std::shared_ptr<BaseExpression> expression);

    void Accept(BaseVisitor* visitor);
};