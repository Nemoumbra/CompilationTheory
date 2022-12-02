#pragma once

#include "BaseStatement.hh"

class Statement : public BaseStatement {
public:
    virtual void Accept(BaseVisitor* visit) = 0;
};