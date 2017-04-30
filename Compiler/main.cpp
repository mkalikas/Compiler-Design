#include <iostream>
#include "ast.cpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"
#include "tok.hpp"
//#include "lexer.cpp"
//#include "parser.cpp"

int
main() {

 // code from HW1
  Context cxt;
  {
    Expr* e =
      new Or_expr(
        new Not_expr(
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
      new Not_expr(
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


