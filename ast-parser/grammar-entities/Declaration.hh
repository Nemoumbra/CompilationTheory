#pragma once

#include <string>

#include "base-elements/BaseComponent.hh"
#include "expressions/BaseExpression.hh"

class Declaration : BaseComponent {
    // Grammar rule:
    // "decl" "identifier" ":" "int_type" ";" { /* code */ }

private:

public:
    std::string identifier_;
    Declaration(const std::string& identifier);

    void Accept(BaseVisitor* visitor);
};