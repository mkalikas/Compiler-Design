//This file contains the lexical conventions

#ifndef TOK_HPP
#define TOK_HPP
#include <string>

struct Token{
	int kind;
	
	
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
		pound_tok // # used for comments

	};
	//tok_kind kind;
	Token();
	Token(tok_kind k);
	~Token();
};

struct PuncOp_tok: Token{
	// tok_kind is represented by symbol
	//Token t;
	//PuncOp_tok(Token::tok_kind);
};
/*
// 	Enumerated punctuation and operation tokens
enum class tok_kind{
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
	pound_tok // # used for comments

};
*/



struct Bool_tokens: Token {

	bool val; // True or False
	std::string str; // need to finish this 

};

struct Int_tokens: Token {
	int val; // includes the numbers 0 - 9 and hexadecimal literals A - F
	Int_tokens(tok_kind t, int v) { 
		t = tok_kind::int_tok; 
		v = val; 
	} 
};

struct Pound_tok: Token {
	std::string str;
	Pound_tok(tok_kind p, std::string s){
		p = tok_kind::pound_tok;
		s = str;
	}
};




#endif
