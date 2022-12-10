#pragma once
#include "BaseVisitor.hh"
#include "../includes_for_parser.hh"

#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>

#include <unordered_map>

class IrGeneratorVisitor : public BaseVisitor {
private:
    llvm::LLVMContext context_;
    llvm::IRBuilder<> builder_;
    llvm::Module module_;
    llvm::Function* printFunc_;
public:
    IrGeneratorVisitor();
    // ~IrGeneratorVisitor();

    void Visit(Assignment* assignment) override;
    void Visit(CallToPrint* call_to_print) override;
    void Visit(Declaration* declaration) override;
    void Visit(Statements* statements) override;
    void Visit(CondClause* cond_clause) override;
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
    void Visit(Program* program) override;
};