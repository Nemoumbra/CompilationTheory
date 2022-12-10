#pragma once

#include "driver.hh"

//#include "assignments/AssignmentList.h"
//#include "expressions/Expression.h"

#include "grammar-entities/Statements.hh"

class Program {
 public:
    Statements* statements_;
    Program(Statements* statements);
    void Accept(BaseVisitor* visitor);
};