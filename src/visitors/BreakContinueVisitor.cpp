#include "BreakContinueVisitor.hh"

void BreakContinueVisitor::Visit(Assignment*) {
    
}

void BreakContinueVisitor::Visit(CallToPrint*) {
    
}

void BreakContinueVisitor::Visit(Declaration*) {
    
}

void BreakContinueVisitor::Visit(Statements* statements) {
    for (const auto& statement: statements->statements_) {
        statement->Accept(this);
    }
}

void BreakContinueVisitor::Visit(NumberExpression*) {
    
}

void BreakContinueVisitor::Visit(IdentifierExpr*) {
    
}

void BreakContinueVisitor::Visit(AddExpression*) {
    
}

void BreakContinueVisitor::Visit(SubExpression*) {
    
}

void BreakContinueVisitor::Visit(MultExpression*) {
    
}

void BreakContinueVisitor::Visit(IntDivExpression*) {
    
}

void BreakContinueVisitor::Visit(RemainderExpression*) {
    
}

void BreakContinueVisitor::Visit(NestedExpr*) {
    
}

void BreakContinueVisitor::Visit(EQExpression*) {
    
}

void BreakContinueVisitor::Visit(NEExpression*) {
    
}

void BreakContinueVisitor::Visit(LTExpression*) {
    
}

void BreakContinueVisitor::Visit(GTExpression*) {
    
}

void BreakContinueVisitor::Visit(LEQExpression*) {
    
}

void BreakContinueVisitor::Visit(GEQExpression*) {
    
}

void BreakContinueVisitor::Visit(Conditional* conditional) {
    conditional->if_clause_->Accept(this);
    conditional->else_clause_->Accept(this);
}

void BreakContinueVisitor::Visit(PreLoop* pre_loop) {
    ++inner_loops;
    pre_loop->loop_body_->Accept(this);
    --inner_loops;
}

void BreakContinueVisitor::Visit(BreakStatement* loop_break) {
    if (!inner_loops) {
        const auto loc = loc_to_str(loop_break->location);
        throw std::runtime_error(
            "Error: break statement not within a loop (" + loc + ")"
        );
    }
}

void BreakContinueVisitor::Visit(ContinueStatement* loop_continue) {
    if (!inner_loops) {
        const auto loc = loc_to_str(loop_continue->location);
        throw std::runtime_error(
            "Error: continue statement not within a loop (" + loc + ")"
        );
    }
}

void BreakContinueVisitor::Visit(AssertStatement*) {
    
}

void BreakContinueVisitor::Visit(Program* program) {
    program->statements_->Accept(this);
}

