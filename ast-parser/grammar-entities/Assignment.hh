#pragma once
#include <string>

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class Assignment : public Statement {
    // Grammar rule:
    // assignment: "identifier" "=" expression ";" { /* code */ }
private:
public:
    std::string identifier_;
    BaseExpression* expression_;
    
    Assignment(const std::string& identifier, BaseExpression* expression);

    void Accept(BaseVisitor* visitor);
};