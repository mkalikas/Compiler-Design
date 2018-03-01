#ifndef AST_TYPES_HPP
#define AST_TYPES_HPP


// Enumeration of types
enum exprTypes {
	bool_type,
	int_type,
	function_type,
	reference_type,
	type_err
};

// Forward declaration of types
struct Bool_type;
struct Int_type;
struct Reference_type;
struct Function_type;

// Definition of Type class
struct Type {
  struct Visitor;
  virtual ~Type() = default;
  virtual void accept(Visitor&) { }
};

// Definition of Bool_type and Int_type classes
struct Bool_type : Type { 

};
struct Int_type : Type { 

};
struct Reference_type : Type { 

};
struct Function_type : Type { 
	std::std::vector<Type*> params;
	Type *ret;
};


#endif