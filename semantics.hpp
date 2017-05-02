#ifndef SEMANTICS_HPP
#define SEMANTICS_HPP

#include "tok.hpp"

struct Semantics {
	Expr* on_int(Token *);
	Expr* on_bool(Token *);
	Expr* on_id(Token *);
	Expr* on_add(Expr* e1, Expr* e2);
	Expr* on_sub(Expr* e1, Expr* e2);
	Expr* on_mult(Expr* e1, Expr* e2);
	Expr* on_div(Expr* e1, Expr* e2);
	Expr* on_rem(Expr* e1, Expr* e2);
	Expr* on_negation(Expr* e1);
	Expr* on_and(Expr* e1, Expr* e2);
	Expr* on_or(Expr* e1, Expr* e2);
	Expr* on_exclamation(Expr* e1);
	Expr* on_conditional(Expr* e1, Expr* e2, Expr* e3);
	Expr* on_assignment(Expr* e1, Expr* e2);
	Expr* on_equal(Expr* e1, Expr* e2);
	Expr* on_not_eq(Expr* e1, Expr* e2);
	Expr* on_lt(Expr* e1, Expr* e2);
	Expr* on_gt(Expr* e1, Expr* e2);
	Expr* on_lt_eq(Expr* e1, Expr* e2);
	Expr* on_gt_eq(Expr* e1, Expr* e2);
	std::string on_id(Token *id);
	Stmt* on_block_stmt(Stmt *s);
	Stmt* on_stmt_seq(Stmt *s);
	Stmt* on_if_stmt(Expr *e, Stmt* s1, Stmt* s2);
	Stmt* on_while_stmt(Expr *e, Stmt *s);
	Stmt* on_break_stmt();
	Stmt* on_contintue_stmt();
	Stmt* on_return_stmt();
	Stmt* on_assert_stmt();
	Stmt* on_expr_stmt(Expr *e);
	Stmt* on_decl_stmt(Decl *d);
	Stmt* on_var_decl(Type t, Expr *e)
	
};

#endif
