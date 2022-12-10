#include "Interpreter.hh"

Interpreter::Interpreter() {
    is_tos_expression_ = false;
    tos_value_ = 0;
}

void Interpreter::setTosValue(int value) {
    is_tos_expression_ = true;
    tos_value_ = value;
}

void Interpreter::unsetTosValue() {
    is_tos_expression_ = false;
    tos_value_ = 0;
}

void Interpreter::Visit(Assignment* assignment) {
    // compute the value and assign (what if we don't have this var declared?)
    assignment->expression_->Accept(this);
    auto it = variables_.find(assignment->identifier_);
    // assert(it != variables_.end());
    if (it == variables_.end()) {
        throw std::runtime_error("Can't assign to undefined variable '" + assignment->identifier_ + "'!");
    }
    it->second = tos_value_;
    
    // why?
    unsetTosValue();
}

void Interpreter::Visit(CallToPrint* call_to_print) {
    // compute the value and print it
    call_to_print->expression_->Accept(this);
    std::cout << tos_value_ << "\n";
}

void Interpreter::Visit(Declaration* declaration) {
    // make a new variable?
    // we allow redeclarations, but is there a default value?
    variables_[declaration->identifier_] = 0;
}

void Interpreter::Visit(Statements* statements) {
    // interpret every base statement
    for (auto* base_statement : statements->statements_) {
        base_statement->Accept(this);
    }

    // why?
    unsetTosValue();
}

void Interpreter::Visit(CondClause* cond_clause) {
    // interpret every statement
    for (auto* statement : cond_clause->statements_) {
        statement->Accept(this);
    }

    // why?
    unsetTosValue();
}

void Interpreter::Visit(NumberExpression* number_expression) {
    // store the value somewhere?
    setTosValue(number_expression->value_);
}

void Interpreter::Visit(IdentifierExpr* ident_expr) {
    // extract the value from the variable and store it somewhere
    // should we check if the identifier was defined before?
    auto it = variables_.find(ident_expr->identifier_);
    // assert(it != variables_.end());
    if (it == variables_.end()) {
        throw std::runtime_error("Can't get the value of undefined variable '" + ident_expr->identifier_ + "'!");
    }

    setTosValue(it->second);
}

void Interpreter::Visit(AddExpression* add_expr) {
    // evaluate both operands, add them and store the result somewhere
    add_expr->first->Accept(this);
    int left = tos_value_;
    add_expr->second->Accept(this);
    setTosValue(left + tos_value_);
}

void Interpreter::Visit(SubExpression* sub_expr) {
    // evaluate both operands, subtract them and store the result somewhere
    sub_expr->first->Accept(this);
    int left = tos_value_;
    sub_expr->second->Accept(this);
    setTosValue(left - tos_value_);
}

void Interpreter::Visit(MultExpression* mult_expr) {
    // evaluate both operands, multiply them and store the result somewhere
    mult_expr->first->Accept(this);
    int left = tos_value_;
    mult_expr->second->Accept(this);
    setTosValue(left * tos_value_);
}

void Interpreter::Visit(IntDivExpression* int_div_expr) {
    // evaluate both operands, perform integer division with them and store the result somewhere
    int_div_expr->first->Accept(this);
    int left = tos_value_;
    int_div_expr->second->Accept(this);
    setTosValue(left / tos_value_);
}

void Interpreter::Visit(NestedExpr* nested_expr) {
    // take the value of the nested expression and store it somewhere
    nested_expr->expression_->Accept(this);
    // I don't think we need to set the stack's top here.
}

void Interpreter::Visit(EQExpression* eq_expr) {
    // evaluate both operands, compare them and store the result somewhere
    eq_expr->first->Accept(this);
    int left = tos_value_;
    eq_expr->second->Accept(this);
    setTosValue(left == tos_value_);
}

void Interpreter::Visit(NEExpression* ne_expr) {
    // evaluate both operands, compare them and store the result somewhere
    ne_expr->first->Accept(this);
    int left = tos_value_;
    ne_expr->second->Accept(this);
    setTosValue(left != tos_value_);
}

void Interpreter::Visit(LTExpression* lt_expr) {
    // evaluate both operands, compare them and store the result somewhere
    lt_expr->first->Accept(this);
    int left = tos_value_;
    lt_expr->second->Accept(this);
    setTosValue(left < tos_value_);
}

void Interpreter::Visit(GTExpression* gt_expr) {
    // evaluate both operands, compare them and store the result somewhere
    gt_expr->first->Accept(this);
    int left = tos_value_;
    gt_expr->second->Accept(this);
    setTosValue(left > tos_value_);
}

void Interpreter::Visit(LEQExpression* leq_expr) {
    // evaluate both operands, compare them and store the result somewhere
    leq_expr->first->Accept(this);
    int left = tos_value_;
    leq_expr->second->Accept(this);
    setTosValue(left <= tos_value_);
}

void Interpreter::Visit(GEQExpression* geq_expr) {
    // evaluate both operands, compare them and store the result somewhere
    geq_expr->first->Accept(this);
    int left = tos_value_;
    geq_expr->second->Accept(this);
    setTosValue(left >= tos_value_);
}

void Interpreter::Visit(Conditional* conditional) {
    // 1) evaluate the expression
    // 2) if the value is true, interpret the if-clause
    // 3) else interpret the else-clause
    conditional->expression_->Accept(this);
    if (tos_value_) {
        conditional->if_clause_->Accept(this);
    }
    else {
        conditional->else_clause_->Accept(this);
    }
}

void Interpreter::Visit(Program* program) {
    // interpret its statements
    program->statements_->Accept(this);
}

void Interpreter::GetResult(Program* program) {
    // why?
    unsetTosValue();
    
    Visit(program);
}