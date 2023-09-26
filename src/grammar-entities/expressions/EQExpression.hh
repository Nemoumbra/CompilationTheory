#pragma once

#include "BaseExpression.hh"

class EQExpression : public BaseExpression {
public:
    std::shared_ptr<BaseExpression> first;
    std::shared_ptr<BaseExpression> second;

    EQExpression(std::shared_ptr<BaseExpression> expr1, std::shared_ptr<BaseExpression> expr2);
    void Accept(BaseVisitor* visitor);
};