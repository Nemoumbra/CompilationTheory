#pragma once

#include "driver.hh"


#include "grammar-entities/Statements.hh"

class Program {
 public:
    std::shared_ptr<Statements> statements_;
    Program(std::shared_ptr<Statements> statements);
    void Accept(BaseVisitor* visitor);
};