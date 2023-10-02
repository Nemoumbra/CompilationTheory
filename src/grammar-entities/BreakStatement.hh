#pragma once

#include "Statement.hh"

class BreakStatement : public Statement {
public:
    BreakStatement() = default;

    void Accept(BaseVisitor* visitor);
};
