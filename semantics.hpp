#ifndef SEMANTICS_HPP
#define SEMANTICS_HPP

#include "ast.hpp"
#include "tok.hpp"

class Semantics {
	Expr* on_int(Token *);
	Expr* on_bool(Token *);
	Expr* on_add(Expr* e1, Expr* e2);
	Expr* on_sub(Expr* e1, Expr* e2);
	Expr* on_mult(Expr* e1, Expr* e2);
	Expr* on_div(Expr* e1, Expr* e2);
	Expr* on_rem(Expr* e1, Expr* e2);
	Expr* on_neg(Expr* e1);
	Expr* on_and(Expr* e1, Expr* e2);
	Expr* on_or(Expr* e1, Expr* e2);
	Expr* on_exclamation(Expr* e1);
	Expr* on_conditional(Expr* e1, Expr* e2, Expr* e3);
	Expr* on_equal(Expr* e1, Expr* e2);
	Expr* on_not_eq(Expr* e1, Expr* e2);
	Expr* on_lt(Expr* e1, Expr* e2);
	Expr* on_gt(Expr* e1, Expr* e2);
	Expr* on_lt_eq(Expr* e1, Expr* e2);
	Expr* on_gt_eq(Expr* e1, Expr* e2);

};

#endif
