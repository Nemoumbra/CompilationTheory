#pragma once
#include <string>

#include "Statement.hh"
#include "expressions/BaseExpression.hh"

class Assignment : public Statement {
public:
    std::string identifier_;
    std::shared_ptr<BaseExpression> expression_;
    
    Assignment(const std::string& identifier,
               std::shared_ptr<BaseExpression> expression,
               yy::location loc
    );

    void Accept(BaseVisitor* visitor);
};