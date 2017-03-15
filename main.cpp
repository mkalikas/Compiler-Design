#include <iostream>
#include <fstream>
#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"
#include "tok.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int 
main() {

 // code from HW1
 /* Context cxt;
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

*/

//This is a driver program that implements the lexer and calculator program for homework 2


//std::ofstream out; // the file that will be written that contains the value of each expression 
	std::string lexeme; // the expression being read from input
	char ch; // character 

    in.open();

	if(in.fail())
		std::cout << "ERROR: The file does not exist.";
	else { // Open the file and read the input line by line until the end of file is detected
	
	
		in.close(); // close file
	}




}


