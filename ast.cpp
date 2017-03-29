#include "ast.hpp"

// Declaration of Type class
struct Type {
  struct Visitor;
  virtual ~Type() = default;
  virtual void accept(Visitor&) { }
};

// Declaration of Bool_type and Int_type classes
struct Bool_type : Type { };
struct Int_type : Type { };

// Declaration of Expr class
struct Expr {
  struct Visitor;
  virtual ~Expr() = default;
  virtual void accept(Visitor&) = 0;
};

// Definition of Visitor class
struct Expr::Visitor
{
  virtual void visit(Bool_expr*) = 0;
  virtual void visit(Int_expr*) = 0;
  virtual void visit(And_expr*) = 0;
  virtual void visit(Or_expr*) = 0;
  virtual void visit(Not_expr*) = 0;
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
  virtual void visit(Neg_expr*) = 0;

};

struct Bool_expr : Expr {
  bool val;
  Bool_expr(bool b) : val(b) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Int_expr : Expr {
	int val;
	Int_expr(int i) : val(i) { }
	void accept(Visitor& v) { return v.visit(this); }
}

struct And_expr : Expr {
  Expr* e1;
  Expr* e2;
  And_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Or_expr : Expr {
  Expr* e1;
  Expr* e2;
  Or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Not_expr : Expr {
  Expr* e1;
  Not_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Cond_expr : Expr {
	Expr* e1;
	Expr* e2;
	Expr* e3;
	Cond_expr(Expr* e1, Expr* e2, Expr* e3) : e1(e1), e2(e2), e3(e3) { }
	void accept(Visitor &v) { return v.visit(this); }
}

struct Equal_expr : Expr{
  Expr* e1;
  Expr* e2;
  Equal_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Not_Equal_expr : Expr{
  Expr* e1;
  Expr* e2;
  Not_Equal_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Less_than_expr : Expr{
  Expr* e1;
  Expr* e2;
  Less_than_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Greater_than_expr : Expr{
  Expr* e1;
  Expr* e2;
  Greater_than_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Less_orEqual_expr : Expr{
  Expr* e1;
  Expr* e2;
  Less_orEqual_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Greater_orEqual_expr : Expr{
  Expr* e1;
  Expr* e2;
  Greater_orEqual_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Add_expr : Expr{
  Expr* e1;
  Expr* e2;
  Add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Sub_expr : Expr{
  Expr* e1;
  Expr* e2;
  Sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Mult_expr : Expr{
  Expr* e1;
  Expr* e2;
  Mult_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Div_expr : Expr{
  Expr* e1;
  Expr* e2;
  Div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Rem_expr : Expr{
  Expr* e1;
  Expr* e2;
  Rem_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) {}
  void accept(Visitor &v) {return v.visit(this); }
};
struct Neg_expr : Expr{
  Expr* e1;
  Neg_expr(Expr* e1) : e1(e1) {}
  void accept(Visitor &v) {return v.visit(this); }
};

struct Context
{
  Bool_type bool_type;
  Int_type int_type;
};
