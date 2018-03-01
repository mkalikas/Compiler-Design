#include "parser.hpp"

// Constructor 
Parser(std::unordered_map<std::string, Token*> &i, std::unordered_map<std::string, Token *> &keys, std::string &s) : lexer(i, keys, s) {
 	if(Token* t = lexer.lexical_analyzer())
 		tokens.push_front(t);
}

// definition of lookahead member function
tok_kind Parser::lookahead() {
	if(Token *tok = peek())
		return tok->kind;
	else
		return eof_tok;
}

// definition of consume member funciton
Token* Parser::consume() {
	Token *t = tokens.top();
	tokens.pop();

	if(tokens.empty()) {
		if(Token *t = lexer.lexical_analyzer())
			tokens.push(t);
	}
	return t;
}

// definition of match member function
Token* Parser::match(tok_kind k) {
	if(lookahead() == k)
		return consume();
	//else
		//std::cout << "Expected: " << k << "\n";
		// need to throw an error
	else break;
}


Token Parser::match_expected(tok_kind k) {
	if(lookahead() == k)
		return consume();
	else
		return nullptr;
}




