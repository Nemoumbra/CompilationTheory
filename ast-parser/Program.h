#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

class Program {
private:
    StatementList* assignments_;
    Expression* expression_;
 public:
    Program(StatementList* assignments, Expression* expression);
    int eval(Driver& driver);
};