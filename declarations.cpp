// Declarations
#include "parser.hpp"
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
};
