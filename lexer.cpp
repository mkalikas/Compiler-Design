#include "tok.hpp"
#include "lexer.hpp"

#include <iostream>
#include <exception>


// Definition of consume() function
// This function gets the character at the current position
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
			return Token(or_tok);
		}
		else if((lookahead() == std::isdigit(lookahead())) || ((lookahead()) == std::isalpha(lookahead()))){
			consume();;
			return Token(pike_tok);
		}
		else
			// abort program
			abort();
	case '!' :
		consume();
		if(lookahead() == '='){
			consume();
			return Token(notequ_tok);
		}
		else if(lookahead() == std::isdigit(lookahead())){ // complement with integer values
			char c = consume();
			return  Int_tokens(int_tok, c);
		}
		// else if(lookahead() == complement for boolean literal
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
		return Token(question_tok);
	case ':' :
		consume();
		return Token(colon_tok);
	case '(' :
			consume();
			return Token(lparen_tok);
	case ')' :
		consume();
		return Token(rparen_tok);
	case '0' : case '1' : case '2' : case '3' : case '4' :
	case '5' : case '6' : case '7' : case '8' : case '9' : {
		consume();
		while(!eof() && std::isxdigit(lookahead())){
			consume();
		}
		int n = stoi(buf);
		return Int_tokens(int_tok, n);
	}

	case '#' :  // make this case recognize the symbol and delete entire comment line


	default:
		break;
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


