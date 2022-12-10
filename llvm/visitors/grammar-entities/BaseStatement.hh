#pragma once

#include "base-elements/BaseComponent.hh"

class BaseStatement : public BaseComponent {
public:
    virtual void Accept(BaseVisitor* visitor) = 0;
};