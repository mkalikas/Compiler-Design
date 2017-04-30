//This file contains the lexical conventions

#ifndef TOK_HPP
#define TOK_HPP

#include <string>

// 	Enumerated punctuation and operation tokens
enum tok_kind {
	int_tok, // used for integer literals
	bool_tok, // used for boolean literals

	lparen_tok,
	rparen_tok,
	lbrace_tok, // used in statements
	rbrace_tok, // used in statements
	
	ampand_tok, // used for bitwise and
	and_tok, // &&
	pike_tok, // used for bitwise or
	or_tok, // ||
	equal_tok, // ==
	assignment_tok, // =
	exclamation_tok, // used for complement
	notequ_tok, // !=

	question_tok, // question mark
	colon_tok, // colon

	plus_tok,
	minus_tok,
	star_tok, // used for multiplication
	slash_tok, // used for division
	percent_tok, // modulus operator, used for remainder of division
	
	lt_tok, // less than symbol
	lt_eq_tok, // less than or equal
	gt_tok, // greater than symbol
	gt_eq_tok, // greater than or eequal

	id_tok, // identifies a keyword
	eof_tok
};
struct Token{
	tok_kind kind;
	Token(tok_kind k) : kind(k) { }
	virtual ~Token();
};

struct Bool_tokens : Token {

	bool val; // True or False
	Bool_tokens(bool b) : Token(bool_tok), val(b) { }

};

struct Int_tokens : Token {
	int val; // includes the numbers 0 - 9 and hexadecimal literals A - F
	int radix; // used to denote hexadecimal and binary numbers
	Int_tokens(tok_kind t, int v) : Token(int_tok), val(v) { }
	Int_tokens(tok_kind t, int v, int r) : Token(int_tok), val(v), radix(r) { }

};

struct Identifier_tokens : Token {
	std::string s; 
	Identifier_tokens(tok_kind t, std::string s) : Token(id_tok), s(s) { }
};

#endif
