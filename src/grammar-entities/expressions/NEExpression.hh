#pragma once

#include "BaseExpression.hh"

class NEExpression : public BaseExpression {
public:
    std::shared_ptr<BaseExpression> first;
    std::shared_ptr<BaseExpression> second;

    NEExpression(
        std::shared_ptr<BaseExpression> expr1,
        std::shared_ptr<BaseExpression> expr2,
        yy::location loc);
    
    void Accept(BaseVisitor* visitor);
};