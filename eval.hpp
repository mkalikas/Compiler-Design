#ifndef EVAL_HPP
#define EVAL_HPP
#endif

#include "ast.cpp"

bool eval(Expr* e) {
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = e->val; }
    void visit(Int_expr* e) { r = e->val; }
    void visit(And_expr* e) { r = eval(e->e1) && eval(e->e2); }
    void visit(Or_expr* e) { r = eval(e->e1) || eval(e->e2); }
    void visit(Logical_neg_expr* e) { r = !eval(e->e1); }
    void visit(Equal_expr* e) { r = eval(e->e1) == eval(e->e2); }
    void visit(Not_Equal_expr* e) { r = eval(e->e1) != eval(e->e2); }
    void visit(Cond_expr* e) { r = eval(e->e1) ? eval(e->e2) : eval(e->e3); }
    void visit(Less_than_expr* e) { r = eval(e->e1) < eval(e->e2); }
    void visit(Greater_than_expr* e) { r = eval(e->e1) > eval(e->e2); }
    void visit(Less_orEqual_expr* e) { r = eval(e->e1) <= eval(e->e2); }
    void visit(Greater_orEqual_expr* e) { r = eval(e->e1) >= eval(e->e2); }
    void visit(Add_expr* e) { r = eval(e->e1) + eval(e->e2); }
    void visit(Sub_expr* e) { r = eval(e->e1) - eval(e->e2); }
    void visit(Mult_expr* e) { r = eval(e->e1) * eval(e->e2); }
    void visit(Div_expr* e) { r = eval(e->e1) / eval(e->e2); }
    void visit(Rem_expr* e) { r = eval(e->e1) % eval(e->e2); }
    void visit(Arithmetic_neg_expr* e) { r = -eval(e->e1); }
    void visit(Reference_expr*) = { r = eval(); }
    void visit(Valuation_expr*) = { r = eval(); }
    void visit(Assignment_expr*) = { r = eval(); }
    void visit(Function_call_expr*) = { r = eval(); }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}

#endif
