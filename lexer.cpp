#include "lexer.hpp"

#include <iostream>
#include <cassert>

// constructor
Lexer::Lexer(std::unordered_map<std::string, Token*> &i, std::unordered_map<std::string, Token *> &keys, std::string &s) {
	first = &s.at(0);
	limit = &s.at(0) + s.length();
}

bool Lexer::match(char c) {
	assert(*(first + 1));

	if(*(first + 1) == c)
		return consume();
	else 
		return 0;
}

// Definition of consume() function
// This function gets the character at the current position
char Lexer::consume(){
	assert(!end());

	char c = *first++; 
	current_tok.push_back(c);
	return c;
}

// Definition of Token next() function
Token* Lexer::lexical_analyzer() {
	current_tok.clear();
	for(; ; consume()) { 
		if(lookahead() == ' ' || lookahead() == '\t')
			++first;
		else if(lookahead() == '\n')
			return nullptr;
	}
	Token* t;
	switch(lookahead()) {
		case '0' : 
			return nullptr;
		case '+' :
			++first;
			t = new Token(plus_tok);
			toks_to_parse.push_back(t);
			return t;
		case '-' :
			++first;
			t = new Token(minus_tok);
			toks_to_parse.push_back(t);
			return t;
		case '*' :
			++first;
			t = new Token(star_tok);
			toks_to_parse.push_back(t);
			return t;
		case '/' :
			++first;
			t = new Token(slash_tok);
			toks_to_parse.push_back(t);
			return t;
		case '%' :
			++first;
			t = new Token(percent_tok);
			toks_to_parse.push_back(t);
			return t;
		case '&' :
			if(match('&')) {
				t = new Token(and_tok);
				toks_to_parse.push_back(t);
				return t;
			}
			else
				++first;
				t = new Token(ampand_tok);
				toks_to_parse.push_back(t);
				return t;
		case '|' :
		if(match('|')) {
			t = new Token(pike_tok);
			toks_to_parse.push_back(t);
			return t;
		}
		else {
			++first;
			t = new Token(or_tok);
			toks_to_parse.push_back(t);
			return t;

		}
		case '!' :
			if(match('=')) {
				t = new Token(notequ_tok);
				toks_to_parse.push_back(t);
				return t;
			}
			else
				++first;
				t = new Token(exclamation_tok);
				toks_to_parse.push_back(t);
				return t;
		case '=' :
			if(match('=')) {
				t = new Token(equal_tok);
				toks_to_parse.push_back(t);
				return t;
			}
			else
				t = new Token(assignment_tok);
				toks_to_parse.push_back(t);
				return t;
		case '<' :
			if(match('=')) {
				t = new Token(lt_eq_tok);
				toks_to_parse.push_back(t);
				return t;
			}
			else{
				++first;
				t = new Token(lt_tok);
				toks_to_parse.push_back(t);
				return t;
			}
		case '>' :
			if(match('=')) {
				t = new Token(gt_eq_tok);
				toks_to_parse.push_back(t);
				return t;
			}
			else{
				++first;
				t = new Token(gt_tok);
				toks_to_parse.push_back(t);
				return t;
			}
		case '?' :
			++first;
			t = new Token(question_tok);
			toks_to_parse.push_back(t);
			return t;
		case ':' :
			++first;
			t = new Token(colon_tok);
			toks_to_parse.push_back(t);
			return t;
		case ';' :
			++first;
			t = new Token(semicolon_tok);
			toks_to_parse.push_back(t);
			return t;
		case '(' :
			++first;
			t = new Token(lparen_tok);
			toks_to_parse.push_back(t);
			return t;
		case ')' :
			++first;
			t = new Token(rparen_tok);
			toks_to_parse.push_back(t);
			return t;
		case '{' :
			++first;
			t = new Token(lbrace_tok);
			toks_to_parse.push_back(t);
			return t;
		case '}' :
			++first;
			t = new Token(rbrace_tok);
			toks_to_parse.push_back(t);
			return t;
		default :
			if(isxdigit(lookahead())) {	
				consume();
				while(!end() && std::isxdigit(lookahead())) {
					consume();
				}
				int n = stoi(current_tok);
				t = new Int_tokens(int_tok, n);
				toks_to_parse.push_back(t);
			return t;
			}
			else if(isalpha(lookahead())) {

				std::unordered_map<std::string, Token*>::const_iterator it = keys->find(current_tok);
				if(it != keys->end()) {
					t = new Token(it->second);
					toks_to_parse.push_back(t);
					return t;
				}			
			}

		//case '#' :  // make this case recognize the symbol and delete entire comment line
	return nullptr;

}

