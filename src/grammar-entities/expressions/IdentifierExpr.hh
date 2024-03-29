#pragma once

#include <string>

#include "BaseExpression.hh"

class IdentifierExpr : public BaseExpression {
public:
    std::string identifier_;

    IdentifierExpr(const std::string& identifier, yy::location loc);

    void Accept(BaseVisitor* visitor);
};