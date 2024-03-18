#pragma once

#include <memory>
#include "../../visitors/BaseVisitor.hh"

#include "../../generated/location.hh"

class BaseComponent {
public:
    yy::location location;
    
    BaseComponent(yy::location loc): location(loc) {}
    virtual void Accept(BaseVisitor* visitor) = 0;
    virtual ~BaseComponent() = default;
};