#pragma once

#include "../forward_declarations.hh"

class BaseVisitor {
public:
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(CallToPrint* call_to_print) = 0;
    virtual void Visit(Declaration* declaration) = 0;
    virtual void Visit(Statements* statements) = 0;
    virtual void Visit(NumberExpression* number_expression) = 0;
    virtual void Visit(IdentifierExpr* ident_expr) = 0;
    virtual void Visit(AddExpression* add_expr) = 0;
    virtual void Visit(SubExpression* sub_expr) = 0;
    virtual void Visit(MultExpression* mult_expr) = 0;
    virtual void Visit(IntDivExpression* int_div_expr) = 0;
    virtual void Visit(NestedExpr* nested_expr) = 0;
    virtual void Visit(EQExpression* eq_expr) = 0;
    virtual void Visit(NEExpression* ne_expr) = 0;
    virtual void Visit(LTExpression* lt_expr) = 0;
    virtual void Visit(GTExpression* gt_expr) = 0;
    virtual void Visit(LEQExpression* leq_expr) = 0;
    virtual void Visit(GEQExpression* geq_expr) = 0;

    virtual void Visit(Conditional* conditional) = 0;

    virtual void Visit(Program* program) = 0;
};