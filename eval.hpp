#ifndef EVAL_HPP
#define EVAL_HPP

#include "ast.hpp"

bool
eval(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = e->val; }
    void visit(And_expr* e) { r = eval(e->e1) & eval(e->e2); }
    void visit(Or_expr* e) { r = eval(e->e1) | eval(e->e2); }
    void visit(Not_expr* e) { r = !eval(e->e1); }
    void visit(Equal_expr* e) { r = eval(e->e1) == eval(e->e2); }
    void visit(Not_Equal_expr* e) {r = eval(e->e1 != eval(e->e2); }
    void visit(Less_than_expr* e) { r = eval(e->e1) < eval(e->e2); }
    void visit(Greater_than_expr* e) { r = eval(e->e1) > eval(e->e2); }
    void visit(Less_orEqual_expr* e) { r = eval(e->e1) <= eval(e->e2); }
    void visit(Greater_orEqual_expr* e) { r = eval(e->e1) >= eval(e->e2); }
    void visit(Add_expr* e) { r = eval(e->e1) + eval(e->e2); }
    void visit(Sub_expr* e) { r = eval(e->e1) - eval(e->e2); }
    void visit(Mult_expr* e) { r = eval(e->e1) * eval(e->e2); }
    void visit(Div_expr* e) { r = eval(e->e1) / eval(e->e2); }
    void visit(Rem_expr* e) { r = eval(e->e1) % eval(e->e2); }
    void visit(Neg_expr* e) { r = eval(0) - eval(e->e1); }
  };
  V vis;
  e->accept(vis);
  return vis.r;

}

#endif