#pragma once

#include <map>
#include <stack>

#include "BaseVisitor.hh"
#include "../driver.hh"
#include "../includes_for_parser.hh"
#include "../symbol-table/stack/symbol_table.hh"
#include "../symbol-table/tree/ScopeLayer.hh"
#include "../utils/utils.hh"

class Interpreter : public BaseVisitor {
private:
    bool is_tos_expression_;
    int tos_value_;
    // SymbolTable variables_;
    ScopeLayer* current_scope_;
    std::stack <int> scope_indexes;

    ControlFlowType current_flow;

    const int max_loop_iterations = 1000;

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

    void Visit(Program* program) override;


    void GetResult(std::shared_ptr<Program> program);
    void SetSymbolTree(std::shared_ptr<ScopeLayer> symbol_tree);
};