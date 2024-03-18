#pragma once

#include "base-elements/BaseComponent.hh"

class Statement : public BaseComponent {
public:
    Statement(yy::location loc): BaseComponent(loc) {}
    virtual void Accept(BaseVisitor* visit) = 0;
};