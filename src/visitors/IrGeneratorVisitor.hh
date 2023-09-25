#pragma once
#include "BaseVisitor.hh"
#include "../includes_for_parser.hh"


#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <llvm/Support/raw_ostream.h>

#include <unordered_map>
#include <string>

class IrGeneratorVisitor : public BaseVisitor {
private:
    llvm::LLVMContext context_;
    llvm::IRBuilder<> builder_;
    llvm::Module module_;
    llvm::Function* printFunc_ = nullptr;
    std::unordered_map<std::string, llvm::AllocaInst*> variables;

    void DefinePrintf();
    llvm::Value* _tos_value;

public:
    IrGeneratorVisitor();

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
    void Visit(NEExpression* ne_expr) override;
    void Visit(LTExpression* lt_expr) override;
    void Visit(GTExpression* gt_expr) override;
    void Visit(LEQExpression* leq_expr) override;
    void Visit(GEQExpression* geq_expr) override;
    void Visit(Conditional* conditional) override;
    void Visit(Program* program) override;

    llvm::Module* getModule();

    void SetValue(llvm::Value* val);
    llvm::Value* Accept(BaseComponent* component);
};