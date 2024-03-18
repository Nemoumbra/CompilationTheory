#pragma once

#include "../base-elements/BaseComponent.hh"

class BaseExpression : public BaseComponent {
public:
    BaseExpression(yy::location loc): BaseComponent(loc) {}
};