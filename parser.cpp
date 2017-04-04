#include "parser.hpp"


// definition of match member function

// definition of lookahead member function
tok_kind Parser::lookahead() {
	Token *tok = peek();

	return tok->kind;

}

// definition of consume member funciton
Token Parser::consume() {
	Token* t = tokens.top();
	tokens.pop();

	if(tokens.empty()) {
		if(Token* t = lexer.next())
			tokens.push(t);
	}
	return t;
}

/*
Token* Parser::match(tok_kind k) {
	if(lookahead() == k)
		return consume();
	//else
		//std::cout << "Expected: " << k << "\n";
		// need to throw an error
	else break;
}
*/

Token Parser::match_if(tok_kind k) {
	if(lookahead() == k)
		return consume();
	else
		return nullptr;
}

/*
// definition of stmt member function
void Parser::stmt() {

	switch(lookahead()) {
		case :



	}



}
*/

Expr* Parser::expression() {
	Expr* e1 = conditional_expr();
	return e1;
}

Expr* Parser::conditional_expr() {
	Expr* e1 = logical_or_expr();
	while(true) {
		if(lookahead() == question_tok) {
			match_if(question_tok);
			Expr* e2 = expression();
			match_if(colon_tok);
			Expr* e3 = expression();
			e1 = sem.on_conditional(e1, e2, e3);
		}
		else
			return logical_or_expr();
	}
}

Expr* Parser::logical_or_expr() {
	Expr* e1 = logical_and_expr();
	while(true) {
		if(lookahead() == pike_tok) {
			match_if(pike_tok);
			match_if(pike_tok);
			Expr* e2 = logical_and_expr();
			e1 = sem.on_or(e1, e2);
		}
		else break;
	}
	return e1;
}

Expr* Parser::logical_and_expr() {
	Expr* e1 = eq_expr();
	while(true) {
		if(lookahead() == ampand_tok) {
			match_if(ampand_tok);
			match_if(ampand_tok);
			Expr* e2 = eq_expr();
			e1 = sem.on_and(e1, e2);
		}
		else break;
	}
	return e1;
}

Expr* Parser::eq_expr(){
	Expr* e1 = relational_expr();
	while(true) {
		if(lookahead() == equal_tok) { // might do switch instead?
			match_if(equal_tok); // potentially have to do another lookahead call for second equal sign
			match_if(equal_tok);
			Expr* e2 = relational_expr();
			e1 = sem.on_equal(e1, e2);
		}
		else if(lookahead() == exclamation_tok) {
			match_if(exclamation_tok);
			if(lookahead() == equal_tok) {
				match_if(equal_tok);
				Expr* e2 = relational_expr();
				e1 = sem.on_exclamation(e1, e2);
			}
		}
		else break;
	}
	return e1;
}

Expr* Parser::relational_expr() {
	Expr* e1 = add_expr();
	while(true) {
		if(lookahead() == lt_tok) { // have to do something with match_if if for <=
			match_if(lt_tok);
			Expr* e2 = add_expr();
			e1 = sem.on_lt(e1, e2);
		}
		else if(lookahead() == gt_tok) { // match_if if for >=
			match_if(gt_tok);
			Expr* e2 = add_expr();
			e1 = sem.on_gt(e1, e2);
		}
		else break;

	}
	return e1;

}

Expr* Parser::add_expr() {
	Expr* e1 = mult_expr();
		while(true) {
			if(lookahead() == plus_tok) {
				match_if(plus_tok);
				Expr* e2 = mult_expr();
				e1 = sem.on_add(e1, e2);
			}
			else if(lookahead() == minus_tok) {
				match_if(minus_tok);
				Expr* e2 = mult_expr();
				e1 = sem.on_sub(e1, e2);
			}
			else break;
		}
		return e1;
}

Expr* Parser::mult_expr() {
	Expr* e1 = unary_expr();
	while(true) {
		if(lookahead() == star_tok) {
			match_if(star_tok);
			Expr* e2 = unary_expr();
			e1 = sem.on_mult(e1, e2);
		}
		else if(lookahead() ==	slash_tok) {
			match_if(slash_tok);
			Expr* e2 = unary_expr();
			e1 = sem.on_div(e1, e2);
		}
		else if(lookahead() == percent_tok) {
			match_if(percent_tok);
			Expr* e2 = unary_expr();
			e1 = sem.on_rem(e1, e2);
		}
		else break;
	}
	return e1;
}

Expr* Parser::unary_expr() {
	Expr* e1 = primary_expr();

	if(lookahead() == exclamation_tok) {
		e1 = on_exclamation(e1);
	}
	else if(lookahead() == minus_tok) {
		e1 = sem.on_neg(e1);
	}

	return e1;
}

/*
Expr* Parser::primary_expr() {
	// boolean literal
	//integer literal
	// expression enclosed in parentheses

}
*/
