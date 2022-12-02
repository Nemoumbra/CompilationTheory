#pragma once

#include <vector>

#include "BaseStatement.hh"
//#include "Declaration.hh"

class Statements : BaseComponent {
//private:
public:
    std::vector <BaseStatement*> statements_;

    void AddStatement(BaseStatement* statement);
    void Accept(BaseVisitor* visitor);
};