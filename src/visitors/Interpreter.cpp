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
    // Compute the value and assign
    assignment->expression_->Accept(this);

    variables_[assignment->identifier_] = tos_value_;
    
    // Why?
    unsetTosValue();
}

void Interpreter::Visit(CallToPrint* call_to_print) {
    // Compute the value and print it
    call_to_print->expression_->Accept(this);
    std::cout << tos_value_ << "\n";
}

void Interpreter::Visit(Declaration* declaration) {
    // Make a new variable?
    // We allow redeclarations, but is there a default value?

    variables_.declare_var(declaration->identifier_);
}

void Interpreter::Visit(Statements* statements) {
    // Interpret every base statement
    for (std::shared_ptr<Statement> statement : statements->statements_) {
        statement->Accept(this);
    }

    // Why?
    unsetTosValue();
}

void Interpreter::Visit(NumberExpression* number_expression) {
    // Store the value somewhere?
    setTosValue(number_expression->value_);
}

void Interpreter::Visit(IdentifierExpr* ident_expr) {
    // Extract the value from the variable and store it somewhere
    setTosValue(variables_[ident_expr->identifier_]);
}

void Interpreter::Visit(AddExpression* add_expr) {
    // Evaluate both operands, add them and store the result somewhere
    add_expr->first->Accept(this);
    int left = tos_value_;

    add_expr->second->Accept(this);
    setTosValue(left + tos_value_);
}

void Interpreter::Visit(SubExpression* sub_expr) {
    // Evaluate both operands, subtract them and store the result somewhere
    sub_expr->first->Accept(this);
    int left = tos_value_;

    sub_expr->second->Accept(this);
    setTosValue(left - tos_value_);
}

void Interpreter::Visit(MultExpression* mult_expr) {
    // Evaluate both operands, multiply them and store the result somewhere
    mult_expr->first->Accept(this);
    int left = tos_value_;

    mult_expr->second->Accept(this);
    setTosValue(left * tos_value_);
}

void Interpreter::Visit(IntDivExpression* int_div_expr) {
    // Evaluate both operands, perform integer division with them and store the result somewhere
    int_div_expr->first->Accept(this);
    int left = tos_value_;

    int_div_expr->second->Accept(this);
    setTosValue(left / tos_value_);
}

void Interpreter::Visit(NestedExpr* nested_expr) {
    // Take the value of the nested expression and store it somewhere
    nested_expr->expression_->Accept(this);
    // I don't think we need to set the stack's top here.
}

void Interpreter::Visit(EQExpression* eq_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    eq_expr->first->Accept(this);
    int left = tos_value_;

    eq_expr->second->Accept(this);
    setTosValue(left == tos_value_);
}

void Interpreter::Visit(NEExpression* ne_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    ne_expr->first->Accept(this);
    int left = tos_value_;

    ne_expr->second->Accept(this);
    setTosValue(left != tos_value_);
}

void Interpreter::Visit(LTExpression* lt_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    lt_expr->first->Accept(this);
    int left = tos_value_;

    lt_expr->second->Accept(this);
    setTosValue(left < tos_value_);
}

void Interpreter::Visit(GTExpression* gt_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    gt_expr->first->Accept(this);
    int left = tos_value_;

    gt_expr->second->Accept(this);
    setTosValue(left > tos_value_);
}

void Interpreter::Visit(LEQExpression* leq_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    leq_expr->first->Accept(this);
    int left = tos_value_;

    leq_expr->second->Accept(this);
    setTosValue(left <= tos_value_);
}

void Interpreter::Visit(GEQExpression* geq_expr) {
    // Evaluate both operands, compare them and store the result somewhere
    geq_expr->first->Accept(this);
    int left = tos_value_;

    geq_expr->second->Accept(this);
    setTosValue(left >= tos_value_);
}

void Interpreter::Visit(Conditional* conditional) {
    // 1) Evaluate the expression
    // 2) if the value is true, interpret the if-clause
    // 3) else interpret the else-clause
    conditional->expression_->Accept(this);

    variables_.push_scope();
    if (tos_value_) {
        conditional->if_clause_->Accept(this);
    }
    else {
        conditional->else_clause_->Accept(this);
    }
    variables_.pop_scope();
}

void Interpreter::Visit(PreLoop* loop) {
    int iterations_count = 0;

    loop->expression_->Accept(this);
    while (tos_value_ && iterations_count < max_loop_iterations) {
        variables_.push_scope();
        loop->loop_body_->Accept(this);
        variables_.pop_scope();

        loop->expression_->Accept(this);
        ++iterations_count;
    }

    if (iterations_count == max_loop_iterations) {
        throw std::runtime_error(
            "Number of loop iterations reached max allowed value of " + std::to_string(max_loop_iterations)
        );
    }
}

void Interpreter::Visit(Program* program) {
    // Interpret its statements
    program->statements_->Accept(this);
}

void Interpreter::GetResult(std::shared_ptr<Program> program) {
    // Why?
    unsetTosValue();
    
    this->Visit(program.get());
}