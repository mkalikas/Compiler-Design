//Parser
#ifndef PARSER_HPP
#define PARSER_HPP


#include "tok.hpp"
#include "lexer.cpp"
#include "ast.hpp"
#include "semantics.hpp"
#include <stack>
#include <string>

struct Parser {
	Parser(std::string &)
	Lexer lexer;
	Semantics sem;
	tok_kind lookahead();
	Token* consume();
	Token* match(tok_kind);
	Token* match_if(tok_kind);
	void stmt();
	void expression(); // productions change return to ast
	void assignment_expr();
	void conditional_expr();
	void logical_or_expr();
	void logical_and_expr();
	void equal_expr();
	void ordering_expr();
	void additive_expr();
	void multiplicative_expr();
	void unary_expr();
	void primary_expr();
	void id_expr();
	std::stack<Token*> tokens;
	bool empty() { return t.empty(); }
	Token *peek() { return !t.empty() ? t.top() : nullptr; }
};

#endif





