#pragma once
#include "BaseVisitor.hh"
#include "../includes_for_parser.hh"
#include "../utils/utils.hh"

#include "../symbol-table/stack/visibility_checker.hh"

class VisibilityCheckVisitor : public BaseVisitor {
private:
    VisibilityChecker checker;
public:
    // VisibilityCheckVisitor();
    // ~VisibilityCheckVisitor();

    void Visit(Assignment* assignment) override;
    void Visit(CallToPrint* call_to_print) override;
    void Visit(Declaration* declaration) override;
    void Visit(Statements* statements) override;
    void Visit(NumberExpression* number_expression) override;
    void Visit(IdentifierExpr* ident_expr) override;
    void Visit(AddExpression* add_expr) override;
    void Visit(SubExpression* sub_expr) override;
    void Visit(MultExpression* mult_expr) override;
    void Visit(IntDivExpression* int_div_expr) override;
    void Visit(RemainderExpression* rem_expr) override;
    void Visit(NestedExpr* nested_expr) override;
    void Visit(EQExpression* eq_expr) override;
    void Visit(NEExpression* ne_expr) override;
    void Visit(LTExpression* lt_expr) override;
    void Visit(GTExpression* gt_expr) override;
    void Visit(LEQExpression* leq_expr) override;
    void Visit(GEQExpression* geq_expr) override;
    void Visit(Conditional* conditional) override;
    void Visit(PreLoop* loop) override;
    void Visit(BreakStatement* loop_break) override;
    void Visit(ContinueStatement* loop_continue) override;
    void Visit(AssertStatement* assertion) override;
    void Visit(Program* program) override;
};