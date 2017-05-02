//Parser
#ifndef PARSER_HPP
#define PARSER_HPP


#include "tok.hpp"
#include "lexer.hpp"
#include "ast_expr.hpp"
#include "ast_stmt.hpp"
#include "semantics.hpp"
#include <vector>
#include <string>

struct Parser {
	Parser(std::unordered_map<std::string, Token*> *i, std::unordered_map<std::string, Token *> *kstd::std::vector<Token*> toks;);
	Lexer lexer;
	Semantics sem;
	tok_kind lookahead();
	Token* consume();
	Token* match(tok_kind);
	Token* match_if(tok_kind);

	// functions for statements
	Stmt stmt();
	Stmt block_stmt();
	Stmt stmt_seq();
	Stmt if_stmt();
	Stmt while_stmt();
	Stmt break_stmt();
	Stmt continue_stmt();
	Stmt return_stmt();
	Stmt assert_stmt();
	Stmt expr_stmt();
	Stmt decl_stmt();

	// functions for expressions
	Expr expression(); // productions change return to ast
	Expr assignment_expr();
	Expr conditional_expr();
	Expr logical_or_expr();
	Expr logical_and_expr();
	Expr equal_expr();
	Expr ordering_expr();
	Expr additive_expr();
	Expr multiplicative_expr();
	Expr unary_expr();
	Expr primary_expr();
	Expr id_expr();

	std::vector<Token*> tokens;
	bool empty() { return tokens.empty(); }
	Token *peek() { return !tokens.empty() ? tokens.top() : nullptr; }
};

#endif





