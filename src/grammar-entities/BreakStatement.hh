#pragma once

#include "Statement.hh"

class BreakStatement : public Statement {
public:
    BreakStatement(yy::location loc);

    void Accept(BaseVisitor* visitor);
};
