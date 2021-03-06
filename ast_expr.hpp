// Abstract Syntax Tree for Expressions
#ifndef AST_EXPR_HPP
#define AST_EXPR_HPP

#include <cassert>
#include "ast_types.hpp"

// Forward declaration of expressions
struct Bool_expr;
struct Int_expr;
struct And_expr;
struct Or_expr;
struct Logical_neg_expr;
struct Cond_expr;
struct Equal_expr;
struct Not_Equal_expr;
struct Less_than_expr;
struct Greater_than_expr;
struct Less_orEqual_expr;
struct Greater_orEqual_expr;
struct Add_expr;
struct Sub_expr;
struct Mult_expr;
struct Div_expr;
struct Rem_expr;
struct Arithmetic_neg_expr;
struct Reference_expr;
struct Valuation_expr;
struct Assignment_expr;
struct Function_call_expr;

struct Expr {
	struct Visitor;
  Expr(Type* t) : t(t) {}
  Type* t;
  Type* type() { return t; }
	virtual ~Expr() = default;
	virtual void accept(Visitor&) = 0;
};

// Definition of Visitor class
struct Expr::Visitor {
  virtual void visit(Bool_expr*) = 0;
  virtual void visit(Int_expr*) = 0;
  virtual void visit(And_expr*) = 0;
  virtual void visit(Or_expr*) = 0;
  virtual void visit(Logical_neg_expr*) = 0;
  virtual void visit(Cond_expr*) = 0;
  virtual void visit(Equal_expr*) = 0;
  virtual void visit(Not_Equal_expr*) = 0;
  virtual void visit(Less_than_expr*) = 0;
  virtual void visit(Greater_than_expr*) = 0;
  virtual void visit(Less_orEqual_expr*) = 0;
  virtual void visit(Greater_orEqual_expr*) = 0;
  virtual void visit(Add_expr*) = 0;
  virtual void visit(Sub_expr*) = 0;
  virtual void visit(Mult_expr*) = 0;
  virtual void visit(Div_expr*) = 0;
  virtual void visit(Rem_expr*) = 0;
  virtual void visit(Arithmetic_neg_expr*) = 0;
  virtual void visit(Reference_expr*) = 0;
  virtual void visit(Valuation_expr*) = 0;
  virtual void visit(Assignment_expr*) = 0;
  virtual void visit(Function_call_expr*) = 0;

};

// Type bool and values of true and false
struct Bool_expr : Expr {
  bool val;
  Bool_expr(bool b) : val(b) { }
  void accept(Visitor& v) override { v.visit(this); }
};

// Type integer and the value is the one indicated by the expression
struct Int_expr : Expr {
  int val;
  Int_expr(int i) : val(i) { }
  void accept(Visitor& v) override { v.visit(this); }
};

// The expressions defined below take operands of type bool and their result type is bool
struct And_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  And_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) { }
  void accept(Visitor& v) override { v.visit(this); }
};

struct Or_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Or_expr(Expr* e1, Expr* e2 Type* t) : e1(e1), e2(e2), t(t) { }
  void accept(Visitor& v) override { v.visit(this); }
};

struct Logical_neg_expr : Expr {
  Expr* e1;
  Type* t;
  Logical_neg_expr(Expr* e1, Type* t) : e1(e1), t(t) { }
  void accept(Visitor& v) override { v.visit(this); }
};

struct Equal_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Equal_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Not_Equal_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Not_Equal_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};
 // operand e1 is converted to bool, if e2 and e3 have the same type, then no other conversions are performed
struct Cond_expr : Expr {
	Expr* e1;
	Expr* e2;
	Expr* e3;
  Type* t;
	Cond_expr(Expr* e1, Expr* e2, Expr* e3, Type* t) : e1(e1), e2(e2), e3(e3),t(t) { }
	void accept(Visitor &v) { v.visit(this); }
};
 
// The following expressions take operands of type integer. The result type of the expression is bool.
struct Less_than_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Less_than_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Greater_than_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Greater_than_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Less_orEqual_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Less_orEqual_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Greater_orEqual_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t
  Greater_orEqual_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {} 
  void accept(Visitor &v) override { v.visit(this); }
};

// The expressions defined below take operands that are of type integer and their result type is integer
struct Add_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Add_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) { v.visit(this); }
};

struct Sub_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Sub_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Mult_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Mult_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Div_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Div_expr(Expr* e1, Expr* e2, Type* t)) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Rem_expr : Expr {
  Expr* e1;
  Expr* e2;
  Type* t;
  Rem_expr(Expr* e1, Expr* e2, Type* t) : e1(e1), e2(e2), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};
struct Arithmetic_neg_expr : Expr {
  Expr* e1;
  Type* t;
  Arithmetic_neg_expr(Expr* e1, Type* t) : e1(e1), t(t) {}
  void accept(Visitor &v) override { v.visit(this); }
};

struct Reference_expr : Expr {
  Decl *d;
  void accept(Visitor &v) override { v.visit(this); }
};

struct Valuation_expr : Expr {
  void accept(Visitor &v) override { v.visit(this); } 
};

struct Assignment_expr : Expr {
  void accept(Visitor &v) override { v.visit(this); } 
};

struct Function_call_expr : Expr {
  // callee 
  // arguments
  // value is the value returned by the called function
  // type is the called function's return type
  // fits the form: e(e1, e2, e3,...en) where e is the callee and e1, e2, e3,...en are the arguments
    // the called function has to have the same number of parameters as the function call
  Expr *function;
  std::std::vector<Expr*> args;
  // the called function has to have the same number of parameters as the function call

  void accept(Visitor &v) override { v.visit(this); } 
};

// Definition of Context class
struct Context
{
  Bool_type bool_type;
  Int_type int_type;
};

#endif
