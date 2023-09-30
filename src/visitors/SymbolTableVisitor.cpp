#include "SymbolTableVisitor.hh"

void SymbolTableVisitor::Visit(Assignment* assignment) {
    if (!checker.is_visible(assignment->identifier_)) {
        const auto loc = loc_to_str(assignment->location);
        throw std::runtime_error(
            "Variable '" + assignment->identifier_ +
            "' used before declaration (" + loc + ")!"
        );
        
    }
    assignment->expression_->Accept(this);
}

void SymbolTableVisitor::Visit(CallToPrint* call_to_print) {
    call_to_print->expression_->Accept(this);
}

void SymbolTableVisitor::Visit(Declaration* declaration) {
    checker.declare_var(declaration->identifier_);
}

void SymbolTableVisitor::Visit(Statements* statements) {
    for (const auto& statement: statements->statements_) {
        statement->Accept(this);
    }
}

void SymbolTableVisitor::Visit(NumberExpression* number_expression) {
    // No code
}

void SymbolTableVisitor::Visit(IdentifierExpr* ident_expr) {
    if (!checker.is_visible(ident_expr->identifier_)) {
        const auto loc = loc_to_str(ident_expr->location);
        throw std::runtime_error(
            "Variable '" + ident_expr->identifier_ +
            "' used before declaration (" + loc + ")!"
        );
    }
}

void SymbolTableVisitor::Visit(AddExpression* add_expr) {
    add_expr->first->Accept(this);
    add_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(SubExpression* sub_expr) {
    sub_expr->first->Accept(this);
    sub_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(MultExpression* mult_expr) {
    mult_expr->first->Accept(this);
    mult_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(IntDivExpression* int_div_expr) {
    int_div_expr->first->Accept(this);
    int_div_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(NestedExpr* nested_expr) {
    nested_expr->expression_->Accept(this);
}

void SymbolTableVisitor::Visit(EQExpression* eq_expr) {
    eq_expr->first->Accept(this);
    eq_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(NEExpression* ne_expr) {
    ne_expr->first->Accept(this);
    ne_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(LTExpression* lt_expr) {
    lt_expr->first->Accept(this);
    lt_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(GTExpression* gt_expr) {
    gt_expr->first->Accept(this);
    gt_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(LEQExpression* leq_expr) {
    leq_expr->first->Accept(this);
    leq_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(GEQExpression* geq_expr) {
    geq_expr->first->Accept(this);
    geq_expr->second->Accept(this);
}

void SymbolTableVisitor::Visit(Conditional* conditional) {
    conditional->expression_->Accept(this);

    checker.push_scope();
    conditional->if_clause_->Accept(this);
    checker.pop_scope();

    checker.push_scope();
    conditional->else_clause_->Accept(this);
    checker.pop_scope();
}

void SymbolTableVisitor::Visit(PreLoop* loop) {
    loop->expression_->Accept(this);

    checker.push_scope();
    loop->loop_body_->Accept(this);
    checker.pop_scope();
}

void SymbolTableVisitor::Visit(Program* program) {
    program->statements_->Accept(this);
}

