#include "PrintVisitor.hh"

PrintVisitor::PrintVisitor(const std::string& filename) : stream_(filename) {}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}



void PrintVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->identifier_ << "\n";

    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(CallToPrint* call_to_print) {
    PrintTabs();
    stream_ << "CallToPrint: \n";

    ++num_tabs_;
    call_to_print->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Declaration* declaration) {
    PrintTabs();
    stream_ << "Declaration: " << declaration->identifier_ << "\n";
}

void PrintVisitor::Visit(Statements* statements) {
    PrintTabs();
    stream_ << "Statements: \n";

    ++num_tabs_;
    for (std::shared_ptr<Statement> statement : statements->statements_) {
        statement->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(NumberExpression* number_expression) {
    PrintTabs();
    stream_ << "NumberExpression: " << number_expression->value_ << "\n";
}

void PrintVisitor::Visit(IdentifierExpr* ident_expr) {
    PrintTabs();
    stream_ << "IdentifierExpr: " << ident_expr->identifier_ << "\n";
}

void PrintVisitor::Visit(AddExpression* add_expr) {
    PrintTabs();
    stream_ << "AddExpression: \n";

    ++num_tabs_;
    add_expr->first->Accept(this);
    add_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(SubExpression* sub_expr) {
    PrintTabs();
    stream_ << "SubExpression: \n";

    ++num_tabs_;
    sub_expr->first->Accept(this);
    sub_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(MultExpression* mult_expr) {
    PrintTabs();
    stream_ << "MultExpression: \n";

    ++num_tabs_;
    mult_expr->first->Accept(this);
    mult_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(IntDivExpression* int_div_expr) {
    PrintTabs();
    stream_ << "IntDivExpression: \n";

    ++num_tabs_;
    int_div_expr->first->Accept(this);
    int_div_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(NestedExpr* nested_expr) {
    PrintTabs();
    stream_ << "NestedExpr: \n";

    ++num_tabs_;
    nested_expr->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(EQExpression* eq_expr) {
    PrintTabs();
    stream_ << "EQExpression: \n";

    ++num_tabs_;
    eq_expr->first->Accept(this);
    eq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(NEExpression* ne_expr) {
    PrintTabs();
    stream_ << "NEExpression: \n";

    ++num_tabs_;
    ne_expr->first->Accept(this);
    ne_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(LTExpression* lt_expr) {
    PrintTabs();
    stream_ << "LTExpression: \n";

    ++num_tabs_;
    lt_expr->first->Accept(this);
    lt_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(GTExpression* gt_expr) {
    PrintTabs();
    stream_ << "GTExpression: \n";

    ++num_tabs_;
    gt_expr->first->Accept(this);
    gt_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(LEQExpression* leq_expr) {
    PrintTabs();
    stream_ << "LEQExpression: \n";

    ++num_tabs_;
    leq_expr->first->Accept(this);
    leq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(GEQExpression* geq_expr) {
    PrintTabs();
    stream_ << "GEQExpression: \n";

    ++num_tabs_;
    geq_expr->first->Accept(this);
    geq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Conditional* conditional) {
    PrintTabs();
    stream_ << "Conditional: \n";

    ++num_tabs_;
    conditional->expression_->Accept(this);
    conditional->if_clause_->Accept(this);
    conditional->else_clause_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Program* program) {
    PrintTabs();
    stream_ << "Program: \n";

    ++num_tabs_;
    program->statements_->Accept(this);
    --num_tabs_;
}