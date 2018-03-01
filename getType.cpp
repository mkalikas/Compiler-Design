// Assign a type to each expression
#include "ast.hpp"

#include <iostream>

exprTypes Bool_expr::type() {
	return bool_type;
}
exprTypes Int_expr::type() {
	return int_type;
}
exprTypes And_expr::type() {
	e1->type() = bool_type;
	e2->type() = bool_type;
	return bool_type; // if both e1 and e2 are bool, then the type is bool
}
exprTypes Or_expr::type() {
	// check that e1->type() is bool
	if(e1->type() == bool_type) {
	// check that e2->type() is bool
		if(e2->type() == bool_type)
			return bool_type; // if both e1 and e2 are bool, then the type is bool
	}
	else
		return type_err;
}
exprTypes Logical_neg_expr::type() {
	// check that e1->type() is bool
	if(e1->type() == bool_type) {
			return bool_type;
	}
	else
		return type_err;
}
exprTypes Cond_expr::type() {
	// check that e1->type() is bool
	if(e1->type() == bool_type) {
		if(e2->type() == e3->type())
			return e2->type();
	}
	else
		return type_err;
}

exprTypes Equal_expr::type() {
	// get the type of e1->type()
	// check that e2->type() has the same type
	if(e1->type() == e2->type())
		return bool_type;
	else
	return type_err;
}

exprTypes Not_Equal_expr::type() {
	 // get the type of e1->type()
	if(e1->type() == e2->type())
		return bool_type;
	else
		return type_err;
}

exprTypes Greater_than_expr::type() {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return bool_type;
	}
	else
		return type_err;
}

exprTypes Less_than_expr::type() {
	 // check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return bool_type;
	}
	else
		return type_err;
}
exprTypes Greater_orEqual_expr::type() {
// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return bool_type;
	}
	else
		return type_err;
}
exprTypes Less_orEqual_expr::type() {
	 // check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return bool_type;
	}
	else
		return type_err;
}
exprTypes Add_expr::type() {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
exprTypes Sub_expr::type() {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
exprTypes Mult_expr::type() {
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
exprTypes Div_expr::type() {
	// check that e1->typ e() is int
	// check that e1->type() is int
	if(e1->type() == int_type) {
		// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
exprTypes Rem_expr::type() {
   // check that e1->type() is int
	if(e1->type() == int_type) {
	// check that e2->type() is int
		if(e2->type() == int_type)
			return int_type;
	}
	else
		return type_err;
}
exprTypes Arithmetic_neg_expr::type() {
	if(e1->type() == int_type) {
		return int_type;
	}
	else
		return type_err;
}

