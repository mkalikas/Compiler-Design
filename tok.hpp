//This file contains the lexical conventions 

#ifndef TOK_HPP
#define TOK_HPP

struct Token{
	int kind;
};

struct PuncOp_tok : Token{

};

// 	Enumerated punctuation and operation tokens
enum tok_kind{
	lparen_tok; 
	rparen_tok; 
	plus_tok;
	minus_tok;
	star_tok; // used for multiplication
	slash_tok; // used for division
	percent_tok; // modulus operator, used for remainder of division
	ampand_tok; // used for and
	pike_tok; // used for or
	equal_tok; 
	exclamation_tok; // used for complement 
	notequ_tok; // !=
	lt_tok; // less than symbol
	lt_eq_tok; // less than or equal
	gt_tok; // greater than symbol
	gt_eq_tok; // greater than or eequal
	question_tok; // question mark
	colon_tok; 
		
};



struct Bool_tokens : Token{

	bool val; // True or False

};

struct Int_tokens : Token{
	int val; // includes the numbers 0 - 9 and hexadecimal literals A - F

};





#endif
