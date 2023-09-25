#pragma once

#include <string>

#include "BaseStatement.hh"
#include "expressions/BaseExpression.hh"

class Declaration : public BaseStatement {
    // Grammar rule:
    // "decl" "identifier" ":" "int_type" ";" { /* code */ }

private:

public:
    std::string identifier_;
    Declaration(const std::string& identifier);

    void Accept(BaseVisitor* visitor);
};