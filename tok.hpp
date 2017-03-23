//This file contains the lexical conventions

#ifndef TOK_HPP
#define TOK_HPP
#include <string>

// 	Enumerated punctuation and operation tokens
enum tok_kind{
	lparen_tok,
	rparen_tok,
	plus_tok,
	minus_tok,
	star_tok, // used for multiplication
	slash_tok, // used for division
	percent_tok, // modulus operator, used for remainder of division
	ampand_tok, // used for bitwise and
	and_tok, // &&
	pike_tok, // used for bitwise or
	or_tok, // ||
	equal_tok,
	exclamation_tok, // used for complement
	notequ_tok, // !=
	lt_tok, // less than symbol
	lt_eq_tok, // less than or equal
	gt_tok, // greater than symbol
	gt_eq_tok, // greater than or eequal
	question_tok, // question mark
	colon_tok,
	int_tok,
	bool_tok,
	eof_tok
};
struct Token{
	tok_kind kind;
	Token(tok_kind k) : kind(k) { }
	virtual ~Token();
};

struct Bool_tokens: Token {

	bool val; // True or False
	Bool_tokens(bool b) : Token(bool_tok), val(b) { }

};

struct Int_tokens: Token {
	int val; // includes the numbers 0 - 9 and hexadecimal literals A - F
	int radix; // used to denote hexadecimal and binary numbers
	Int_tokens(tok_kind t, int v) : Token(int_tok), val(v) { }
	Int_tokens(tok_kind t, int v, int r) : Token(int_tok), val(v), radix(r) { }
	
};





#endif
