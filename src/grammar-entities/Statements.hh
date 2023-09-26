#pragma once

#include <vector>

#include "Statement.hh"

class Statements : BaseComponent {
public:
    std::vector <Statement*> statements_;

    void AddStatement(Statement* statement);
    void Accept(BaseVisitor* visitor);
};