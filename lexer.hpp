//This file is the implementation of the program execution.
//This class produces and evaluates expressions from the abstract syntax of the language

#ifndef LEXER_HPP
#define LEXER_HPP

#include "tok.hpp"
#include <iostream>
#include <cstdlib> // used for abort
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

// Definition of Lexer class

struct Lexer{
	
	Lexer(std::unordered_map<std::string, Token*> *i, std::unordered_map<std::string, Token *> *k, std::string &); // constructor
	~Lexer() { toks_to_parse.erase(toks_to_parse.begin(), toks_to_parse.end()); } // destructor
	char *first; // 
	char *limit;
	int line;
	std::string current_tok;
	bool end() { return first == limit; }
	char lookahead() { return end() ? 0 : *first; }
	bool match(char c); // matches operators that are made of two symbols 
	char check_next();
	char consume(); // moves to the next token
	Token* lexical_analyzer(); // reads the input from the source
	const std::unordered_map<std::string, Token *> *keys;
	std::vector<Token*> toks_to_parse; // creates a queue of the tokens from the input string
	std::unordered_map<std::string, Token *> *ids; // insert identifiers into map

};

#endif


