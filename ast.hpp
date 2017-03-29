// Abstract Syntax Tree

#ifndef AST_HPP
#define AST_HPP

#include <cassert>

// Forward declaration of types
struct Type;
struct Bool_type;
struct Int_type;

// Forward declaration of expressions
struct Bool_expr;
struct Int_expr;
struct And_expr;
struct Or_expr;
struct Not_expr;
struct Cond_expr;
struct Equal_expr;
struct Not_Equal_expr;
struct Less_than_expr;
struct Greater_than_expr;
struct Less_orEqual_expr;
struct Greater_orEqual_expr;
struct Add_expr;
struct Sub_expr;
struct Mult_expr;
struct Div_expr;
struct Rem_expr;
struct Neg_expr;

struct Context
{
  Bool_type bool_type;
  Int_type int_type;
};

#endif // AST_HPP
