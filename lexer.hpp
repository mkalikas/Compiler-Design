//This file is the implementation of the program execution. 
//This class produces and evaluates expressions from the abstract syntax of the language

#ifndef LEXER_HPP
#define LEXER_HPP

#include "tok.hpp"
#include <iostream>
#include <cstdlib> // used for abort
#include <cctype>
#include <fstream>

// Definition of Lexer class

struct Lexer{
	const char *first;
	const char *last;
	int line = 1;
	bool eof() const { return first == last; }
	char LookAhead() const {
		if(eof())
			return 0;
		else
			return *first;
	}
	void getchar() { ++first; } // function moves to the next token
	Token next();
	
};

#endif


