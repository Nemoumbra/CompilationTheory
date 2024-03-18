#pragma once

#include "Statement.hh"

class ContinueStatement : public Statement {
public:
    ContinueStatement(yy::location loc): Statement(loc) {}

    void Accept(BaseVisitor* visitor);
};

