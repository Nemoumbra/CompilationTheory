#pragma once

#include "Statement.hh"

class BreakStatement : public Statement {
public:
    BreakStatement(yy::location loc): Statement(loc) {}

    void Accept(BaseVisitor* visitor);
};
