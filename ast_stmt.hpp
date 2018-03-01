#ifndef AST_STMT_HPP
#define AST_STMT_HPP

struct Stmt {


};

struct Block_stmt : Stmt {

};

struct If_Else_stmt : Stmt {

};

struct While_stmt : Stmt {

};

struct Break_stmt :Stmt {
	
};


struct Continue_stmt : Stmt {
	
};

struct Return_stmt : Stmt {
	
};

struct Assert_stmt : Stmt
{
	
};

struct Expr_stmt : Stmt
{
	
};

struct Decl_stmt : Stmt
{
	Var_decl();
};

#endif