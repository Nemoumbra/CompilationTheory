#pragma once

#include <vector>

#include "Statement.hh"

class Statements : public BaseComponent {
public:
    std::vector <std::shared_ptr<Statement>> statements_;

    Statements(yy::location loc): BaseComponent(loc) {}
    void AddStatement(std::shared_ptr<Statement> statement);
    void Accept(BaseVisitor* visitor);
};