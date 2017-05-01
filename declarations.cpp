// Declarations

#ifndef DECLARATION_HPP
#define DECLARATION_HPP

<<<<<<< HEAD
#include "ast_expr.hpp"
#include "ast_types.hpp"

struct Decl {

};

struct Function_decl : Decl {

};

struct  Param_decl : Decl {
	
};

struct Var_decl : Decl {
	const std::string *next;
	Type *ty;
	Expr *int_;
=======
strut Declarations {

};

struct Function_decl : Declarations {

};

struct  Paramaters_decl : Declarations {
	
};

struct Variables_decl : Declarations {

>>>>>>> 74c400d5d6c8c6770909804f7f747253d70982e9
};

#endif