#pragma once

#include <fstream>
#include <string>

#include "BaseVisitor.hh"

#include "../includes_for_parser.hh"

class PrintVisitor : public BaseVisitor {
private:
    std::ofstream stream_;
    int num_tabs_ = 0;

    void PrintTabs();
public:
    PrintVisitor(const std::string& filename);
    ~PrintVisitor();

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
    void Visit(NEExpression* eq_expr) override;
    void Visit(LTExpression* eq_expr) override;
    void Visit(GTExpression* eq_expr) override;
    void Visit(LEQExpression* eq_expr) override;
    void Visit(GEQExpression* eq_expr) override;
    
    void Visit(Conditional* conditional) override;
    void Visit(PreLoop* loop) override;

    void Visit(Program* program) override;
};