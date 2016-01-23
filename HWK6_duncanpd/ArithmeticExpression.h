/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Header for ArithmeticExpression.cpp
*/
#ifndef ArithmeticExpression_H
#define ArithmeticExpression_H
#include "Expression.h"
#include <String>
using namespace std;

class ArithmeticExpression : public Expression {	// Class that inherits from expression
public:		
	bool error;										// Does the expression raise an error?
	string ArithmeticExpression::evaluate();		// Function to evaluate an expression into a numerical form
	void ArithmeticExpression::print();				// Function to print
	void Split();									// Recursive tree funciton
	char op;										// The operation type
	bool isNumber(char c);							// Checks if the char is a number
	float convert(string s);						// Convert string to float
	float l;										// float value of the left side of a simple expression
	float r;										// float value of the right side of a simple expression
	string answer;									// string for the answer of the expression
	ArithmeticExpression();							// Default constructor
	ArithmeticExpression(string exp);				// Constructor that sets expr
	~ArithmeticExpression();						// The destructor
	ArithmeticExpression *leftExpr;					// Pointer to the ArithmeticExpression of left
	ArithmeticExpression *rightExpr;				// Pointer to the ArithmeticExpression of right
};
#endif