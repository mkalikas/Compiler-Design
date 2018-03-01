// Concrete syntax for statements
#include "parser.hpp"

Stmt Parser::stmt() {
	switch(lookahead()) {
		case lbrace_tok :
			return block_stmt();
		case if_tok :
			return if_stmt();
		case while_tok :
			return while_stmt();
		case break_tok :
			return break_stmt();
		case continue_tok :
			return continue_stmt();
		case return_tok :
			return continue_stmt();
		case assert_tok :
			return assert_stmt();
	}

}
Stmt Parser::block_stmt() {
	Stmt *s = stmt_seq();
	match(rbrace_tok);
	return sem.on_block_stmt(s);
}
Stmt Parser::stmt_seq() {
	Stmt *s = stmt();
	return sem.on_stmt_seq(s);
}
Stmt Parser::if_stmt() {
	match(lparen_tok);
	Expr *e = expression();
	match(rparen_tok);
	Stmt *s1 = stmt();
	match(else_tok);
	Stmt *s2 = stmt();
	return sem.on_if_stmt(e, s1, s2);
}
Stmt Parser::while_stmt() {
	match(lparen_tok);
	Expr *e = expression();
	match(rparen_tok);
	Stmt *s = stmt();
	return sem.on_while_stmt(e, s);
}
Stmt Parser::break_stmt() {
	match(semicolon_tok);
	return sem.on_break_stmt();
}
Stmt Parser::continue_stmt() {
	match(semicolon_tok);
	return sem.on_continue_stmt();
}
Stmt Parser::return_stmt() {
	Expr *e = expression();
	match(semicolon_tok);
	return sem.on_return_stmt(e);
}
Stmt Parser::assert_stmt() {
	Expr *e = expression();
	match(semicolon_tok);
	return sem.on_assert_stmt(e);
}
Stmt Parser::expr_stmt() {
	Expr *e = expression();
	match(semicolon_tok);
	return sem.on_expr_stmt(e);
}

Stmt Parser::decl_stmt() {
	var_decl();
}