#pragma once

#include <string>

#include "grammar-entities/Statement.hh"
#include "expressions/BaseExpression.hh"

class Declaration : public Statement {
public:
    std::string identifier_;
    Declaration(const std::string& identifier, yy::location loc);

    void Accept(BaseVisitor* visitor);
};