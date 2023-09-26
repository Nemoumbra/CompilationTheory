#pragma once

#include <map>

#include "BaseVisitor.hh"
#include "../driver.hh"
#include "../includes_for_parser.hh"

class Interpreter : public BaseVisitor {
private:
    std::map <std::string, int> variables_;
    bool is_tos_expression_; // unused?
    int tos_value_; // Top Of Stack?

    int scope_cnt; // For now

    void setTosValue(int value);
    void unsetTosValue();
public:
    Interpreter();

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
    void Visit(NestedExpr* nested_expr) override;
    void Visit(EQExpression* eq_expr) override;
    void Visit(NEExpression* ne_expr) override;
    void Visit(LTExpression* lt_expr) override;
    void Visit(GTExpression* gt_expr) override;
    void Visit(LEQExpression* leq_expr) override;
    void Visit(GEQExpression* geq_expr) override;
    void Visit(Conditional* conditional) override;

    void Visit(Program* program) override;


    void GetResult(Program* program);
};