#pragma once

#include <vector>

#include "Statement.hh"

class Statements : BaseComponent {
public:
    std::vector <std::shared_ptr<Statement>> statements_;

    void AddStatement(std::shared_ptr<Statement> statement);
    void Accept(BaseVisitor* visitor);
};