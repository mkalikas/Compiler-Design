#ifndef AST_TYPES_HPP
#define AST_TYPES_HPP

#include "ast_expr.hpp"

// Enumeration of types
enum types {
	bool_type,
	int_type,
	function_type,
	reference_type,
	type_err
};

// Forward declaration of types
struct Bool_type;
struct Int_type;
struct Reference_type;
struct Function_type;

// Definition of Type class
struct Type {
	types ty;
	Type(types t) : ty(t) {}
	types logical_type_expr(Expr* e1, Expr* e2);
	types arithmetic_type_expr(Expr* e1, Expr* e2);
	types relational_type_expr(Expr* e1, Expr* e2);
  struct Visitor;
  virtual ~Type() = default;
  virtual void accept(Visitor&) { }
};

// Definition of Bool_type and Int_type classes
struct Bool_type : Type { 
	Bool_type(types t) : Type(bool_type) {}
};
struct Int_type : Type { 
	Int_type(types t) : Type(int_type) {}
};
struct Reference_type : Type { 
	Reference_type(types t) : Type(reference_type) {}
};
struct Function_type : Type { 
	std::std::vector<Type*> params;
	Type *ret;
};

types logical_type_expr(Expr* e1, Expr* e2) {
	// check that e1->type() is bool
	if(e1->type() == bool_type) {
	// check that e2->type() is bool
		if(e2->type() == bool_type)
			return bool_type; // if both e1 and e2 are bool, then the type is bool
	}
	else
		return type_err;
}
types arithmetic_type_expr(Expr* e1, Expr* e2) {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
types relational_type_expr(Expr* e1, Expr* e2) {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return bool_type;
	}
	else
		return type_err;
}


#endif