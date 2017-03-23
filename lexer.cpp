#include "tok.hpp"
#include "lexer.hpp"

#include <iostream>


// Definition of consume() function
// This function gets the character at the current position
char Lexer::consume(){
	if(eof())
		return 0;
	//char c = s.get();
	//buf += c;
	buf += *first++;
	++column;
	//return c;
	return buf.back();
}

// Definition of Token next() function
Token Lexer::next() {
	buf.clear();
	ignore();
	//Token t;
	
    switch(LookAhead()) {
        case '+' :
            consume();
           // t.kind = Token::plus_tok;
            return new Token(Token::plus_tok);
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
                return new PuncOp_tok(gt_eq_tok);
            }
            else{
                consume();
                return new PuncOp_tok(gt_tok);
            }
        case '?' :
            consume();
            return new PuncOp_tok(question_tok);
        case ':' :
            consume();
            return new PuncOp_tok(colon_tok);
        case '(' :
            consume();
            return new PuncOp_tok(lparen_tok);
        case ')' :
            consume();
            return new PuncOp_tok(rparen_tok);
        case '0' : case '1' : case '2' : case '3' : case '4' :
        case '5' : case '6' : case '7' : case '8' : case '9' : 
        case 'A' : case 'a' : case 'B' : case 'b' : case 'C' : 
        case 'c' : case 'D' : case 'd' : case 'E' : case 'e' :
        case 'F' : case 'f' : {
            const char *Iter = first;
            consume();
            while(!eof() && std::isxdigit(LookAhead()){
                consume();
                std::string str(Iter, buf);
            }
            int n = stoi(str);
            return new Int_tokens(Int_tokens, n);
        }
        /*
        case '0' :
            consume();
            return new Int_tokens(Int_tokens, 0);
        case '1' :
            consume()
            return new Int_tokens(Int_tokens, 1);
        case '2' :
            consume();
            return new Int_tokens(Int_tokens, 2);
        case '3' :
            consume();
            return new Int_tokens(Int_tokens, 3);
        case '4' :
            consume();
            return new Int_tokens(Int_tokens, 4);
        case '5' :
            consume():
            return new Int_tokens(Int_tokens, 5);
        case '6' :
            consume();
            return new Int_tokens(Int_tokens, 6);
        case '7' :
            consume();
            return new Int_tokens(Int_tokens, 7);
        case '8' :
            consume():
            return new Int_tokens(Int_tokens, 8);
        case '9' :
            consume();
            return new Int_tokens(Int_tokens, 9);
        
        case 'A' :  //The following cases that include the letters from A to F represent hexadecimal literals
            consume();
            return new Int_tokens(Int_tokens, 10);
        case 'B' :
            consume();
            return new Int_tokens(Int_tokens, 11);
        case 'C' :
            consume();
            return new Int_tokens(Int_tokens, 12);
        case 'D' :
            consume();
            return new Int_tokens(Int_tokens, 13);
        case 'E' :
            consume();
            return new Int_tokens(Int_tokens, 14);
        case 'F' :
            consume();
            return new Int_tokens(Int_tokens, 15);
        
        //case for binary integer literals to be included here
        */
        case '#' : {
			const char *Iter = first;
            consume();
            while((LookAhead() != '\n') && (std::isalpha(LookAhead()) || std::isspace(LookAhead()))){
                consume();
                // add characters to an array
				std::string str(Iter, buf);
			}
			return new Pound_tok(pound_tok, str);		 	
		}
            
        default:
            break;
                  
    }
     
}

void Lexer::skipSpace(){
while(!eof()){
	switch(LookAhead()){
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

bool Lexer::match(char ch) {
	if(LookAhead == k)
		consume();
	else 
		throw syntax_error();
	
