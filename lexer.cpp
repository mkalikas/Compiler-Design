#include <iostream>
#include "tok.hpp"
#include "lexer.hpp"

// Definition of Token next() function
Token Lexer::next() {
	switch(LookAhead()){
		case '+' :
			consume();
			return new PuncOp_tok(plus_tok);
		case '-' :
			consume();
			return new PuncOp_tok(minus_tok);
		case '*' :
			consume();
			return new PuncOp_tok(star_tok);
		case '/' :
			consume();
			return new PuncOp_tok(slash_tok);
		case '%' :
			consume();
			return new PuncOp_tok(percent_tok);
		case '&' :
			consume();
			if(LookAhead() == '&'){
				consume();
				return new PuncOp_tok(ampand_tok);
			}
			else
				// abort program
				abort();
		case '|' :
			consume();
			if(LookAhead() == '|'){
				consume();
				return new PuncOp_tok(or_tok);
			}
			else if((LookAhead() == std::isdigit(LookAhead())) || ((LookAhead()) == std::isalpha(LookAhead())){
				consume();;
				return new PuncOp_tok(pike_tok);
			}

			else
				// abort program
				abort();
		case '!' :
			consume();
			if(LookAhead() == '='){
				consume();
				return new PuncOp_tok(notequ_tok);
			}
			else if(LookAhead() == std::isdigit(LookAhead())){ // complement with integer values
				consume();
				return new int_tok(int_tok, val);
			}
			// else if(LookAhead() == complement for boolean literal
		case '=' :
			consume();
			if(LookAhead() == '='){
				consume();
				return new PuncOp_tok(equal_tok);
			}
			else
				abort(); // invalid input
		case '<' :
			consume();
			if(LookAhead() == '='){
				consume();
				return new PuncOp(lt_eq_tok);
			}
			else{
				consume();
				return new PuncOp_tok(lt_tok);
			}
		case '>' :
			consume();
			if(LookAhead() == '='){
				consume();
				return new PuncOp(gt_eq_tok);
			}
			else{
				consume();
				return new PuncOp(gt_tok);
			}
		case '?' :
			consume();
			return new PuncOp(question_tok);
		case ':' :
			consume();
			return new PuncOp(colon_tok);
		case '(' :
			consume();
			return new PuncOp(lparen_tok);
		case ')' :
			consume();
			return new PuncOp(rparen_tok);
		case '0' : case '1' : case '2' : case '3' : case '4' :
		case '5' : case '6' : case '7' : case '8' : case '9' :
			const char *Iter = first;
			consume();
			while(!eof() && std::isdigit(LookAhead())
				consume();
			std::string str(Iter, first);
			int n = stoi(str);
			return new Int_tok(Int_tok, int )

		/*
		case '0' :
			consume();
			return new Int_tok(int_tok, 0);
		case '1' :
			consume()
			return new Int_tok(int_tok, 1);
		case '2' :
			consume();
			return new Int_tok(int_tok, 2);
		case '3' :
			consume();
			return new Int_tok(int_tok, 3);
		case '4' :
			consume();
			return new Int_tok(int_tok, 4);
		case '5' :
			consume():
			return new Int_tok(int_tok, 5);
		case '6' :
			consume();
			return new Int_tok(int_tok, 6);
		case '7' :
			consume();
			return new Int_tok(int_tok, 7);
		case '8' :
			consume():
			return new Int_tok(int_tok, 8);
		case '9' :
			consume();
			return new Int_tok(int_tok, 9);
		*/
		case 'A' :	//The following cases that include the letters from A to F represent hexadecimal literals
			consume();
			return new Int_tok(int_tok, 10);
		case 'B' :
			consume();
			return new Int_tok(int_tok, 11);
		case 'C' :
			consume();
			return new Int_tok(int_tok, 12);
		case 'D' :
			consume();
			return new Int_tok(int_tok, 13);
		case 'E' :
			consume();
			return new Int_tok(int_tok, 14);
		case 'F' :
			consume();
			return new Int_tok(int_tok, 15);
		// change the alphabetic characters to accept lowercase as well
		//case for binary integer literals to be included here
		case ' ' :
			consume();
			continue;
		case '\n' :
			line += 1;
			continue;
		case '\k' :
			consume();
			continue;
	}
}
