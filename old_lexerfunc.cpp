// Definition of Token next() function
Token Lexer::lexical_analyzer() {
	current_tok.clear();

	switch(lookahead()) {
		case ' ' : // space
			continue;
		case '+' :
			return Token(plus_tok);
		case '-' :
			return Token(minus_tok);
		case '*' :
			return Token(star_tok);
		case '/' :
			return Token(slash_tok);
		case '%' :
			return Token(percent_tok);
		case '&' :
			if(check_next('&')) {
					return Token(ampand_tok);
			}
			else
				// abort program
				abort();
		case '|' :
			consume();
		if(check_next('|')) {
			return Token(pike_tok);
		}
		else {
			return Token(or_tok);
		}
		case '!' :
			if(check_next('=')) 
				return Token(notequ_tok);
			else
				return Token(exclamation_tok);
		case '=' :
			consume();
			if(check_next('=')) {
				return Token(equal_tok);
			}
			else
				return Token(assignment_tok);
		case '<' :
			consume();
			if(check_next('=')) {
				return Token(lt_eq_tok);
			}
			else{
				return Token(lt_tok);
			}
		case '>' :
			if(check_next('=')) {
				return Token(gt_eq_tok);
			}
			else{
				return Token(gt_tok);
			}
		case '?' :
			return Token(question_tok);
		case ':' :
			return Token(colon_tok);
		case '(' :
			return Token(lparen_tok);
		case ')' :
			return Token(rparen_tok);
		case isxdigit(lookahead()) :
			consume();
			while(!end() && std::isxdigit(lookahead())){
				consume();
			}
			int n = stoi(current_tok);
			return Int_tokens(int_tok, n);

		//case '#' :  // make this case recognize the symbol and delete entire comment line
	}
	return Token(eof_tok);

}