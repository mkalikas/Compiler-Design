#include <iostream>
#include <unordered_map>
#include "ast.cpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"
#include "tok.hpp"
//#include "lexer.cpp"
//#include "parser.cpp"

// Global variables 
const std::unordered_map<std::string, Token *> keywords({"break", break_tok}, {"continue", continue_tok}, {"def", def_tok}, {"else", else_tok}, {"false", new bool_tok(false)}, {"if", if_tok}, {"return", return_tok}, {"true", new bool_tok(true)}, {"var", var_tok}, {"while", while_tok}, {"assert", assert_tok});
std::unordered_map<std::string, Token *> symbol_table; // insert identifiers into map


int
main() {

 // code from HW1
  Context cxt;
  {
    Expr* e =
      new Or_expr(
        new Logical_neg_expr(
          new Bool_expr(true)
        ),
        new Bool_expr(true)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e) << '\n';
  }

  {
    Expr* e =
      new Logical_neg_expr(
        new Or_expr(
          new Bool_expr(true),
          new Bool_expr(false)
        )
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e) << '\n';
  }

  {
  Expr* e = new Mult_expr(
    new Int_expr(3),
    new Add_expr(
      new Int_expr(4),
      new Int_expr(2)
    ));
    assert(check(cxt, e));
    print(e);
  std::cout << " == " << eval(e) << '\n';
  }
//std::ofstream out; // the file that will be written that contains the value of each expression
  /*std::string lexeme; // the expression being read from input
  char ch; // character

  while(true) {
    cout << "=>";
    lexeme = std::getline();

  }*/

  return 0;

}


