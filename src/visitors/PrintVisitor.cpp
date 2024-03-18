#include "PrintVisitor.hh"

#include "utils/utils.hh"


PrintVisitor::PrintVisitor(const std::string& filename) : stream_(filename) {}

void PrintVisitor::PrintTabs() {
    const uint8_t spaces_in_tab = 4;
    stream_ << std::string(spaces_in_tab * num_tabs_, ' ');
}

void PrintVisitor::PrintLocation(BaseComponent* component) {
    if (print_locations) {
        stream_ << "(" << loc_to_str(component->location) + ")";
    }
}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}

void PrintVisitor::setPrintLocations(bool value) {
    print_locations = value;
}

bool PrintVisitor::getPrintLocations() const {
    return print_locations;
}



void PrintVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->identifier_ << " ";
    PrintLocation(assignment);
    stream_ << "\n";

    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(CallToPrint* call_to_print) {
    PrintTabs();

    stream_ << "CallToPrint: ";
    PrintLocation(call_to_print);
    stream_ << "\n";

    ++num_tabs_;
    call_to_print->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Declaration* declaration) {
    PrintTabs();
    stream_ << "Declaration: " << declaration->identifier_ << " ";
    PrintLocation(declaration);
    stream_ << "\n";
}

void PrintVisitor::Visit(Statements* statements) {
    PrintTabs();
    stream_ << "Statements: ";
    PrintLocation(statements);
    stream_ << "\n";

    ++num_tabs_;
    for (std::shared_ptr<Statement> statement : statements->statements_) {
        statement->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(NumberExpression* number_expression) {
    PrintTabs();
    stream_ << "NumberExpression: " << number_expression->value_ << " ";
    PrintLocation(number_expression);
    stream_ << "\n";
}

void PrintVisitor::Visit(IdentifierExpr* ident_expr) {
    PrintTabs();
    stream_ << "IdentifierExpr: " << ident_expr->identifier_ << " ";
    PrintLocation(ident_expr);
    stream_ << "\n";
}

void PrintVisitor::Visit(AddExpression* add_expr) {
    PrintTabs();
    stream_ << "AddExpression: ";
    PrintLocation(add_expr);
    stream_ << "\n";

    ++num_tabs_;
    add_expr->first->Accept(this);
    add_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(SubExpression* sub_expr) {
    PrintTabs();
    stream_ << "SubExpression: ";
    PrintLocation(sub_expr);
    stream_ << "\n";

    ++num_tabs_;
    sub_expr->first->Accept(this);
    sub_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(MultExpression* mult_expr) {
    PrintTabs();
    stream_ << "MultExpression: ";
    PrintLocation(mult_expr);
    stream_ << "\n";

    ++num_tabs_;
    mult_expr->first->Accept(this);
    mult_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(IntDivExpression* int_div_expr) {
    PrintTabs();
    stream_ << "IntDivExpression: ";
    PrintLocation(int_div_expr);
    stream_ << "\n";

    ++num_tabs_;
    int_div_expr->first->Accept(this);
    int_div_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(RemainderExpression* rem_expr) {
    PrintTabs();
    stream_ << "IntDivExpression: ";
    PrintLocation(rem_expr);
    stream_ << "\n";

    ++num_tabs_;
    rem_expr->first->Accept(this);
    rem_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(NestedExpr* nested_expr) {
    PrintTabs();
    stream_ << "NestedExpr: ";
    PrintLocation(nested_expr);
    stream_ << "\n";

    ++num_tabs_;
    nested_expr->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(EQExpression* eq_expr) {
    PrintTabs();
    stream_ << "EQExpression: ";
    PrintLocation(eq_expr);
    stream_ << "\n";

    ++num_tabs_;
    eq_expr->first->Accept(this);
    eq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(NEExpression* ne_expr) {
    PrintTabs();
    stream_ << "NEExpression: ";
    PrintLocation(ne_expr);
    stream_ << "\n";

    ++num_tabs_;
    ne_expr->first->Accept(this);
    ne_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(LTExpression* lt_expr) {
    PrintTabs();
    stream_ << "LTExpression: ";
    PrintLocation(lt_expr);
    stream_ << "\n";

    ++num_tabs_;
    lt_expr->first->Accept(this);
    lt_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(GTExpression* gt_expr) {
    PrintTabs();
    stream_ << "GTExpression: ";
    PrintLocation(gt_expr);
    stream_ << "\n";

    ++num_tabs_;
    gt_expr->first->Accept(this);
    gt_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(LEQExpression* leq_expr) {
    PrintTabs();
    stream_ << "LEQExpression: ";
    PrintLocation(leq_expr);
    stream_ << "\n";

    ++num_tabs_;
    leq_expr->first->Accept(this);
    leq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(GEQExpression* geq_expr) {
    PrintTabs();
    stream_ << "GEQExpression: ";
    PrintLocation(geq_expr);
    stream_ << "\n";

    ++num_tabs_;
    geq_expr->first->Accept(this);
    geq_expr->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Conditional* conditional) {
    PrintTabs();
    stream_ << "Conditional: ";
    PrintLocation(conditional);
    stream_ << "\n";

    ++num_tabs_;
    conditional->expression_->Accept(this);
    conditional->if_clause_->Accept(this);
    conditional->else_clause_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(PreLoop* loop) {
    PrintTabs();
    stream_ << "PreLoop: ";
    PrintLocation(loop);
    stream_ << "\n";

    ++num_tabs_;
    loop->expression_->Accept(this);
    loop->loop_body_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(BreakStatement* loop_break) {
    PrintTabs();
    stream_ << "BreakStatement ";
    PrintLocation(loop_break);
    stream_ << "\n";
}

void PrintVisitor::Visit(ContinueStatement* loop_continue) {
    PrintTabs();
    stream_ << "ContinueStatement ";
    PrintLocation(loop_continue);
    stream_ << "\n";
}

void PrintVisitor::Visit(AssertStatement* assertion) {
    PrintTabs();
    stream_ << "AssertStatement ";
    PrintLocation(assertion);
    stream_ << "\n";

    ++num_tabs_;
    assertion->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(Program* program) {
    PrintTabs();
    stream_ << "Program: \n";
    // Program is not a BaseComponent, so we don't print the location

    ++num_tabs_;
    program->statements_->Accept(this);
    --num_tabs_;
}