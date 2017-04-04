#include "tok.hpp"
#include "lexer.hpp"

#include <iostream>
#include <exception>


// Definition of consume() function
// This function gets the character at the current position
std::vector<Token>& getTokens(Token t) {
	std::vector<Token> tokens;
	while(t = next()) {
		tokens.push_back(t);
	}
	return &tokens;
}

char Lexer::consume(){
	if(eof())
		return 0;
	buf += *first++;
	++column;
	return buf.back();
}

// Definition of Token next() function
Token Lexer::next() {
	buf.clear();
	ignore();

	switch(lookahead()) {
		case '+' :
			consume();
			return Token(plus_tok);
		case '-' :
			consume();
			return Token(minus_tok);
		case '*' :
			consume();
			return Token(star_tok);
		case '/' :
			consume();
			return Token(slash_tok);
		case '%' :
			consume();
			return Token(percent_tok);
		case '&' :
			consume();
			if(lookahead() == '&'){
					consume();
					return Token(ampand_tok);
			}
			else
				// abort program
				abort();
		case '|' :
			consume();
		if(lookahead() == '|'){
			consume();
			return Token(pike_tok);
		}
		else {
			return Token(or_tok);
		}
		else
			// abort program
			abort();
		case '!' :
			consume();
			if(lookahead() == '='){
				consume();
				return Token(notequ_tok);
			else
				return Token(exclamation_tok);
			}
		case '=' :
			consume();
			if(lookahead() == '='){
				consume();
				return Token(equal_tok);
			}
			else
					abort(); // invalid input
		case '<' :
			consume();
			if(lookahead() == '='){
				consume();
				return Token(lt_eq_tok);
			}
			else{
				consume();
				return Token(lt_tok);
			}
		case '>' :
			consume();
			if(lookahead() == '='){
				consume();
				return Token(gt_eq_tok);
			}
			else{
				consume();
				return Token(gt_tok);
			}
		case '?' :
			consume();
		case ':' :
			consume();
			return Token(cond_tok);
		case '(' :
				consume();
				return Token(lparen_tok);
		case ')' :
			consume();
			return Token(rparen_tok);
		case isxdigit(lookahead()) :
			consume();
			while(!eof() && std::isxdigit(lookahead())){
				consume();
			}
			int n = stoi(buf);
			return Int_tokens(int_tok, n);

		//case '#' :  // make this case recognize the symbol and delete entire comment line
	}
	return Token(eof_tok);

}

void Lexer::skipSpace(){
	while(!eof()){
		switch(lookahead()){
			case ' ' :
				consume();
				break;
			case '\n' :
				++line;
				column = 1; // moves to first input character on next line
				break;
			case '\t' : {
				ignore();
				continue;
			default:
				return;
			}
		}
	}

}


