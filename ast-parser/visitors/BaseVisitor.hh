#pragma once

#include "../forward_declarations.hh"

class BaseVisitor {
public:
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(CallToPrint* call_to_print) = 0;
    virtual void Visit(Declaration* declaration) = 0;
};