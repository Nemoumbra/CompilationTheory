#pragma once

#include "../forward_declarations.hh"

class BaseVisitor {
public:
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(CallToPrint* call_to_print) = 0;
    virtual void Visit(Declaration* declaration) = 0;
    virtual void Visit(Statements* statements) = 0;
    virtual void Visit(CondClause* cond_clause) = 0;
    virtual void Visit(NumberExpression* number_expression) = 0;
    virtual void Visit(IdentifierExpr* ident_expr) = 0;
    virtual void Visit(AddExpression* add_expr) = 0;
    virtual void Visit(SubExpression* sub_expr) = 0;
    virtual void Visit(MultExpression* mult_expr) = 0;
    virtual void Visit(IntDivExpression* int_div_expr) = 0;
    virtual void Visit(NestedExpr* nested_expr) = 0;
    virtual void Visit(EQExpression* eq_expr) = 0;
    virtual void Visit(NEExpression* eq_expr) = 0;
    virtual void Visit(LTExpression* eq_expr) = 0;
    virtual void Visit(GTExpression* eq_expr) = 0;
    virtual void Visit(LEQExpression* eq_expr) = 0;
    virtual void Visit(GEQExpression* eq_expr) = 0;

    virtual void Visit(Conditional* conditional) = 0;

    virtual void Visit(Program* program) = 0;
};