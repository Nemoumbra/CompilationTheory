#pragma once

#include "driver.hh"


#include "grammar-entities/Statements.hh"

class Program {
 public:
    Statements* statements_;
    Program(Statements* statements);
    void Accept(BaseVisitor* visitor);
};