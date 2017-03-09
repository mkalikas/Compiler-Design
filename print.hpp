#ifndef PRINT_HPP
#define PRINT_HPP

#include "ast.hpp"

#include <iostream>

bool
needs_parens(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = false; }
    void visit(And_expr* e) { r = true; }
    void visit(Or_expr* e) { r = true; }
    void visit(Not_expr* e) { r = true; }
    void visit(Equal_expr* e) { r = true; }
    void visit(Not_Equal_expr* e) { r = true; }
    void visit(Less_than_expr* e) { r = true; }
    void visit(Greater_than_expr* e) { r = true; }
    void visit(Less_orEqual_expr* e) { r = true; }
    void visit(Greater_orEqual_expr* e) { r = true; }
    void visit(Add_expr* e) { r = true; }
    void visit(Sub_expr* e) { r = true; }
    void visit(Mult_expr* e) { r = true; }
    void visit(Div_expr* e) { r = true; }
    void visit(Rem_expr* e) { r = true; }
    void visit(Neg_expr* e) { r = true; }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}

void
print(Expr* e)
{
  struct V : Expr::Visitor {
    void print_enclosed(Expr* e) {
      if (needs_parens(e)) {
        std::cout << '(';
        print(e);
        std::cout << ')';
      }
      else {
        print(e);
      }
    }

    void visit(Bool_expr* e) {
      if (e->val)
        std::cout << "true";
      else
        std::cout << "false";
    }
    void visit(And_expr* e) {
      print_enclosed(e->e1);
      std::cout << " & ";
      print_enclosed(e->e2);
    }
    void visit(Or_expr* e) {
      print_enclosed(e->e1);
      std::cout << " | ";
      print_enclosed(e->e2);
    }
    void visit(Not_expr* e) {
      std::cout << '!';
      print_enclosed(e->e1);
    }
    void visit(Equal_expr* e) {
      print_enclosed(e->e1);
      std::cout << "==";
      print_enclosed(e->e2);
    }
    void visit(Not_Equal_expr* e){
      print_enclosed(e->e1);
      std::cout << "!=";
      print_enclosed(e->e2);
    }
    void visit(Less_than_expr* e) {
      print_enclosed(e->e1);
      std::cout << '<';
      print_enclosed(e->e2);
    }
    void visit(Greater_than_expr* e) {
      print_enclosed(e->e1);
      std::cout << '>';
      print_enclosed(e->e2);
    }
    void visit(Less_orEqual_expr* e) {
      print_enclosed(e->e1);
      std::cout << "<=";
      print_enclosed(e->e2);
    }
    void visit(Greater_orEqual_expr* e) {
      print_enclosed(e->e1);
      std::cout << ">=";
      print_enclosed(e->e2);
    }
    void visit(Add_expr* e) {
      print_enclosed(e->e1);
      std::cout << '+';
      print_enclosed(e->e2);
    }
    void visit(Sub_expr* e) {
      print_enclosed(e->e1);
      std::cout << '-';
      print_enclosed(e->e2);
    }
    void visit(Mult_expr* e) {
      print_enclosed(e->e1);
      std::cout << '*';
      print_enclosed(e->e2);
    }
    void visit(Div_expr* e) {
      print_enclosed(e->e1);
      std::cout << '/';
      print_enclosed(e->e2);
    }
    void visit(Rem_expr* e) {
      print_enclosed(e->e1);
      std::cout << '%';
      print_enclosed(e->e2);
    }
    void visit(Neg_expr* e){
    print_enclosed(0);
    std::cout << '-';
    print_enclosed(e->e1);
    }
  };
  V vis;
  e->accept(vis);
}

#define