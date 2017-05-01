// Concrete syntax for expressions

void Parser::expression() {
	assignment_expr();
}

void Parser::assignment_expr() {
	conditional_expr(); // Expr* e1

	if(match_if(question_tok)) {
		expression(); // Expr* e2
		match(colon_tok);
		expression(); // Expr *e3
		// return sem.on_conditional(e1, e2, e3);
	}
	else if(match_if(equal_tok)) {
		assignment_expr(); // Expr *e2
		// return sem.on_assignment(e1, e2);
	}
	// return e1;
}

void Parser::conditional_expr() {
	logical_or_expr(); // Expr* e1
	if(match_if(question_tok)) {
		expression(); // Expr *e2
		match(colon_tok);
		expression(); // Expr *e3
		// return sem.on_conditional(e1, e2, e3);
	}
	//else
		//return e1;
}

void Parser::logical_or_expr() {
	logical_and_expr(); // Expr* e1
	
	while(true) {
		if(match_if(pike_tok)) {
			logical_and_expr(); // Expr *e2
			e1 = sem.on_or(e1, e2);
		}
		else 
			break;
	}
	return e1;
}

void Parser::logical_and_expr() {
	eq_expr(); // Expr* e1
	while(true) {
		if(match_if(ampand_tok)) {
			match(ampand_tok);
			eq_expr(); // Expr* e2
			// e1 = sem.on_and(e1, e2);
		}
		else break;
	}
	//return e1;
}

void Parser::equal_expr(){
	ordering_expr(); // Expr* e1
	while(true) {
		if(match_if(equal_tok) == equal_tok) { 
			match_if(equal_tok); 
				ordering_expr(); // Expr* e2;
			// e1 = sem.on_equal(e1, e2);
		}
		else if(match_if(exclamation_tok)) {
			if(match_if() == equal_tok) {
				match(equal_tok);
				ordering_expr(); // Expr* e2
				//e1 = sem.on_exclamation(e1, e2);
			}
		}
		else break;
	}
	//return e1;
}

void Parser::ordering_expr() {
	additive_expr(); // Expr *e1;
	while(true) {
		if(match_if(lt_tok)) { // have to do something with match_if if for <=
			add_expr();// Expr* e2 =
			//e1 = sem.on_lt(e1, e2);
		}
		else if(match_if(gt_tok)) { // match_if if for >=
			add_expr(); // Expr* e2 =
			//e1 = sem.on_gt(e1, e2);
		}
		else break;

	}
	//return e1;

}

void Parser::additive_expr() {
	multiplicative_expr(); // Expr* e1 =
	while(true) {
		if(match_if(plus_tok)) {
				multiplicative_expr(); // Expr* e2 =
				//e1 = sem.on_add(e1, e2);
		}
		else if(match_if(minus_tok)) {
			multiplicative_expr(); // Expr* e2 =
			//e1 = sem.on_sub(e1, e2);
		}
		else break;
	}
	//return e1;
}

void Parser::multiplicative_expr() {
	unary_expr(); // Expr* e1
	while(true) {
		if(match_if(star_tok)) {
			unary_expr();// Expr* e2 =
			// e1 = sem.on_mult(e1, e2);
		}
		else if(match_if(slash_tok)) {
			unary_expr(); // Expr* e2 =
			//e1 = sem.on_div(e1, e2);
		}
		else if(match_if(percent_to)) {
			unary_expr(); // Expr* e2 =
			//e1 = sem.on_rem(e1, e2);
		}
		else break;
	}
	//return e1;
}

Expr* Parser::unary_expr() {
    Expr* e1 = primary_expr(); // 

	if(match_if(exclamation_tok)) {
       = unary_expr(); 
      e1 = on_exclamation(e1); // xor
	}
	else if(match_if(minus_tok)) {
		e1 = sem.on_neg(e1);
	}
	return e1;
}


Expr* Parser::primary_expr() {
	// boolean literal
	//integer literal
	// ID expr
	// expression enclosed in parentheses
    switch(lookahead()) {
	case bool_tok :
		return sem.on_bool(e);
	case int_tok :
		return sem.on_int(e);
    case id_tok :
        return id_expr();
    case lparen_tok :
        consume();
        Expr* e = expression();
		match(rparen_tok);
		return e;
    default
        break;
    }
    
}

void Parser::id_expr() {
      

}