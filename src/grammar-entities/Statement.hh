#pragma once

#include "base-elements/BaseComponent.hh"

class Statement : public BaseComponent {
public:
    int index_in_list;
    virtual void Accept(BaseVisitor* visit) = 0;
};