#include "IdentifierExpr.hh"

IdentifierExpr::IdentifierExpr(const std::string& identifier) {

}
void IdentifierExpr::Accept(BaseVisitor* visitor) {
    visitor->Visit(this);
}