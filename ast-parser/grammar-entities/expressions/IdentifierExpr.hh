#pragma once

#include <string>

#include "BaseExpression.hh"

class IdentifierExpr : BaseExpression {
public:
    std::string identifier_;

    IdentifierExpr(const std::string& identifier);

    void Accept(BaseVisitor* visitor);
};