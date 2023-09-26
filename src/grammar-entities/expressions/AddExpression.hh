#pragma once

#include "BaseExpression.hh"

class AddExpression : public BaseExpression {
public:
    std::shared_ptr<BaseExpression> first;
    std::shared_ptr<BaseExpression> second;

    AddExpression(std::shared_ptr<BaseExpression> expr1, std::shared_ptr<BaseExpression> expr2);
    void Accept(BaseVisitor* visitor);
};