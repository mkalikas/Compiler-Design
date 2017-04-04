//This file is the implementation of the program execution.
//This class produces and evaluates expressions from the abstract syntax of the language

#ifndef LEXER_HPP
#define LEXER_HPP

#include "tok.hpp"
#include <iostream>
#include <cstdlib> // used for abort
#include <cctype>
//#include <fstream> might use when implement parser
#include <string>
#include <map>
#include <vector>

// Definition of Lexer class

struct Lexer{
	char *first;
	char *last;
	//const char ch;
	//std::istream s;
	std::string buf;
	int line;
	int column;
	Lexer(char *ch) : first(ch), line(1), column(1) {}
	bool eof() const { return first == last; }
	char lookahead() const { return *first; }
	char consume(); // function moves to the next token
	char ignore() { return eof() ? 0 : *first++; }
	void skipSpace();
	Token next();
	std::map<std::string, Token *> st;
	std::vector<Token>& getTokens(Token);

};

#endif


