//Parser
#ifndef PARSER_HPP
#define PARSER_HPP


#include "tok.hpp"
#include "lexer.hpp"
#include "ast.hpp"
#include "semantics.hpp"
#include <stack>

struct Parser {
	Lexer lexer;
	Semantics sem;
	tok_kind lookahead();
	Token consume();
	Token match(tok_kind);
	Token match_if(tok_kind);
	void stmt();
	Expr* expression(); // productions
	Expr* conditional_expr();
	Expr* logical_or_expr();
	Expr* logical_and_expr();
	Expr* eq_expr();
	Expr* ordering_expr();
	Expr* add_expr();
	Expr* mult_expr();
	Expr* unary_expr();
	Expr* primary_expr();
	std::stack<Token*> tokens;
	bool empty() { return t.empty(); }
	Token *peek() { return !t.empty() ? t.top() : nullptr; }
};

#endif





