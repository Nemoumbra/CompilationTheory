#pragma once

#include "Statement.hh"

class ContinueStatement : public Statement {
public:
    ContinueStatement() = default;

    void Accept(BaseVisitor* visitor);
};

