#include "PreLoop.hh"

PreLoop::PreLoop(std::shared_ptr<BaseExpression> expression,
                 std::shared_ptr<Statements> body) :
    expression_(expression), loop_body_(body) {}

void PreLoop::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}