#pragma once
#include <string>

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class Assignment : Statement {
    // Grammar rule:
    // assignment: "identifier" "=" expression ";" { /* code */ }
private:
    std::string identifier_;
    BaseExpression* expression_;
public:
    Assignment(const std::string& identifier, BaseExpression* expression);

    void Accept(BaseVisitor* visitor);
};