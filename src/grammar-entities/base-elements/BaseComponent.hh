#pragma once

#include <memory>
#include "../../visitors/BaseVisitor.hh"

class BaseComponent {
public:
    virtual void Accept(BaseVisitor* visitor) = 0;
    virtual ~BaseComponent() = default;
};