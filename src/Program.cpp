#include "Program.h"

Program::Program(Statements* statements) : statements_(statements) {}


void Program::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}