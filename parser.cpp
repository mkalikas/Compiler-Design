#include "parser.hpp"


// definition of match member function
// definition of lookahead member function
tok_kind Parser::lookahead() {
	Token *tok = peek();

	return tok->kind;

}

// definition of consume member funciton
Token* Parser::consume() {
	Token *t = tokens.top();
	tokens.pop();

	if(tokens.empty()) {
		if(Token *t = lexer.next())
			tokens.push(t);
	}
	return t;
}


Token* Parser::match(tok_kind k) {
	if(lookahead() == k)
		return consume();
	//else
		//std::cout << "Expected: " << k << "\n";
		// need to throw an error
	else break;
}


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



