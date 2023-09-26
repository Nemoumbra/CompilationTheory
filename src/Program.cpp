#include "Program.h"

Program::Program(std::shared_ptr<Statements> statements) : statements_(statements) {}


void Program::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}