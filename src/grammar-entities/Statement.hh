#pragma once

#include "base-elements/BaseComponent.hh"

class Statement : public BaseComponent {
public:
    virtual void Accept(BaseVisitor* visit) = 0;
};