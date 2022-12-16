#include "IrGeneratorVisitor.hh"

// #include <iostream>

#include <llvm/ADT/APInt.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>


IrGeneratorVisitor::IrGeneratorVisitor() :
    builder_(context_),
    module_("file", context_) {}

// IrGeneratorVisitor::~IrGeneratorVisitor() {

// }


void IrGeneratorVisitor::SetValue(llvm::Value* val) {
    _tos_value = val;
}

llvm::Value* IrGeneratorVisitor::Accept(BaseComponent* component) {
    component->Accept(this);
    return _tos_value;
}


void IrGeneratorVisitor::DefinePrintf() {
    auto pointer_type = builder_.getInt8PtrTy();

    auto printfType = llvm::FunctionType::get(
        builder_.getInt32Ty(),
        {pointer_type},
        true
    );

    printFunc_ = llvm::Function::Create(
        printfType, llvm::Function::ExternalLinkage,
        "printf",
        module_
    );
}


void IrGeneratorVisitor::Visit(Assignment* assignment) {
    auto pointer = Accept(assignment->expression_);

    auto value = builder_.CreateLoad(builder_.getInt32Ty(), pointer);

    auto variable = variables[assignment->identifier_];

    builder_.CreateStore(value, variable);
}

void IrGeneratorVisitor::Visit(CallToPrint* call_to_print) {
    if (printFunc_ == nullptr) {
        DefinePrintf();
    }

    std::string string = "%d\n";
    auto fmt = llvm::ConstantDataArray::getString(context_, string);

    auto alloca = builder_.CreateAlloca(fmt->getType());
    builder_.CreateStore(fmt, alloca);

    // cast to char*
    auto formatted_string = builder_.CreateBitCast(alloca, builder_.getInt8PtrTy());

    auto pointer = Accept(call_to_print->expression_);

    auto value = builder_.CreateLoad(builder_.getInt32Ty(), pointer);


    SetValue(
        builder_.CreateCall(printFunc_, {formatted_string, value}, "printCall")
    );
}

void IrGeneratorVisitor::Visit(Declaration* declaration) {
    auto function = builder_.GetInsertBlock()->getParent();
    llvm::BasicBlock &block = function->getEntryBlock();
    
    llvm::IRBuilder<> tmp(&block, block.begin());

    auto variable = tmp.CreateAlloca(builder_.getInt32Ty(), nullptr, declaration->identifier_);

    variables[declaration->identifier_] = variable;
}

void IrGeneratorVisitor::Visit(Statements* statements) {
    for (auto* base_statement : statements->statements_) {
        Accept(base_statement);
    }
}

void IrGeneratorVisitor::Visit(CondClause* cond_clause) {
    for (auto* statement : cond_clause->statements_) {
        Accept(statement);
    }
}

void IrGeneratorVisitor::Visit(NumberExpression* number_expression) {
    auto alloca = builder_.CreateAlloca(builder_.getInt32Ty());

    llvm::Value* value = builder_.getInt32(number_expression->value_);
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(IdentifierExpr* ident_expr) {
    SetValue(variables[ident_expr->identifier_]);
}

void IrGeneratorVisitor::Visit(AddExpression* add_expr) {
    auto left = Accept(add_expr->first);
    auto right = Accept(add_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);
    auto value = builder_.CreateAdd(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );  
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(SubExpression* sub_expr) {
    auto left = Accept(sub_expr->first);
    auto right = Accept(sub_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);
    auto value = builder_.CreateSub(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );  
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(MultExpression* mult_expr) {
    auto left = Accept(mult_expr->first);
    auto right = Accept(mult_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);
    auto value = builder_.CreateMul(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );  
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(IntDivExpression* int_div_expr) {
    auto left = Accept(int_div_expr->first);
    auto right = Accept(int_div_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);
    auto value = builder_.CreateSDiv(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );  
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(NestedExpr* nested_expr) {
    Accept(nested_expr->expression_);
}

void IrGeneratorVisitor::Visit(EQExpression* eq_expr) {
    auto left = Accept(eq_expr->first);
    auto right = Accept(eq_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpEQ(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(NEExpression* ne_expr) {
    auto left = Accept(ne_expr->first);
    auto right = Accept(ne_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpNE(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(LTExpression* lt_expr) {
    auto left = Accept(lt_expr->first);
    auto right = Accept(lt_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpSLT(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(GTExpression* gt_expr) {
    auto left = Accept(gt_expr->first);
    auto right = Accept(gt_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpSGT(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(LEQExpression* leq_expr) {
    auto left = Accept(leq_expr->first);
    auto right = Accept(leq_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpSLE(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(GEQExpression* geq_expr) {
    auto left = Accept(geq_expr->first);
    auto right = Accept(geq_expr->second);

    auto int_ty = builder_.getInt32Ty();
    auto alloca = builder_.CreateAlloca(int_ty);

    auto bool_val = builder_.CreateICmpSGE(
        builder_.CreateLoad(int_ty, left),
        builder_.CreateLoad(int_ty, right)
    );
    auto value = builder_.CreateIntCast(
        bool_val,
        int_ty,
        false
    );
    builder_.CreateStore(value, alloca);
    SetValue(alloca);
}

void IrGeneratorVisitor::Visit(Conditional* conditional) {
    auto block = builder_.GetInsertBlock()->getParent();
    auto int_ty = builder_.getInt32Ty();

    auto true_entry = llvm::BasicBlock::Create(context_, "btrue", block);
    auto false_entry = llvm::BasicBlock::Create(context_, "bfalse", block);
    auto end_entry = llvm::BasicBlock::Create(context_, "bend", block);

    auto cond = Accept(conditional->expression_);

    auto zero = builder_.CreateAlloca(int_ty);
    builder_.CreateStore(
        llvm::ConstantInt::get(int_ty, llvm::APInt(32, 0)),
        zero
    );

    builder_.CreateCondBr(
        builder_.CreateICmpNE(
            builder_.CreateLoad(int_ty, cond),
            builder_.CreateLoad(int_ty, zero)
        ),
        true_entry,
        false_entry
    );

    builder_.SetInsertPoint(true_entry);
    conditional->if_clause_->Accept(this);
    builder_.CreateBr(end_entry);

    builder_.SetInsertPoint(false_entry);
    conditional->else_clause_->Accept(this);
    builder_.CreateBr(end_entry);

    builder_.SetInsertPoint(end_entry);
}

void IrGeneratorVisitor::Visit(Program* program) {
    auto function_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context_), false
    );

    auto function_llvm = llvm::Function::Create(
        function_type,
        llvm::Function::ExternalLinkage,
        "main",
        module_
    );

    auto entry = llvm::BasicBlock::Create(context_, "entry", function_llvm);
    builder_.SetInsertPoint(entry);

    // Accept(program->statements_);
    program->statements_->Accept(this);

    builder_.CreateRetVoid();
}



llvm::Module* IrGeneratorVisitor::getModule() {
    return &module_;
}
