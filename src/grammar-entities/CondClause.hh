#pragma once

#include <vector>
#include "base-elements/BaseComponent.hh"
#include "Statement.hh"

class CondClause : BaseComponent {
public:
    //
    std::vector <Statement*> statements_;
    void AddStatement(Statement* statement);
    void Accept(BaseVisitor* visitor);
};