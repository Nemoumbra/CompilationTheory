#include "SymbolTableVisitor.hh"

SymbolTableVisitor::SymbolTableVisitor() : current(std::make_shared<ScopeLayer>()) {}

std::shared_ptr<ScopeLayer> SymbolTableVisitor::get_root() const {
    return current;
}

void SymbolTableVisitor::Visit(Assignment* assignment) {
    if (!current->is_visible(assignment->identifier_)) {
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
    if (!current->declare_var(declaration->identifier_)) {
        const auto loc = loc_to_str(declaration->location);       
        throw std::runtime_error(
            "Variable '" + declaration->identifier_ +
            "' can't be redeclared in the same scope (" + loc + ")"
        );
    }
}

void SymbolTableVisitor::Visit(Statements* statements) {
    for (const auto& statement: statements->statements_) {
        statement->Accept(this);
    }
}

void SymbolTableVisitor::Visit(NumberExpression*) {
    
}

void SymbolTableVisitor::Visit(IdentifierExpr* ident_expr) {
    if (!current->is_visible(ident_expr->identifier_)) {
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

void SymbolTableVisitor::Visit(RemainderExpression* rem_expr) {
    rem_expr->first->Accept(this);
    rem_expr->second->Accept(this);    
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

    auto copy = current;

    current = current->make_child();
    conditional->if_clause_->Accept(this);
    current = copy;

    current = current->make_child();
    conditional->else_clause_->Accept(this);
    current = copy;
}

void SymbolTableVisitor::Visit(PreLoop* pre_loop) {
    pre_loop->expression_->Accept(this);

    auto copy = current;

    current = current->make_child();
    pre_loop->loop_body_->Accept(this);
    current = copy;
}

void SymbolTableVisitor::Visit(BreakStatement*) {
    
}

void SymbolTableVisitor::Visit(ContinueStatement*) {
    
}

void SymbolTableVisitor::Visit(Program* program) {
    program->statements_->Accept(this);
}
