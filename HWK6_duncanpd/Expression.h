/*
* Name:? Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID:? wu235, duncanpd, kozeln
* Student Number:? 1450544, 1413067, 1404557
* Description: Header for Expression.cpp
*/
#ifndef Expression_H
#define Expression_H
#include<String>
using namespace std;
class Expression {
public: 
	Expression *left;								// Pointer of type Expression for the left of the expression
	Expression *right;								// Pointer of type Expression for the right of the expression
	virtual string evaluate();						// Virtual function to get the solution	
	virtual void print();							// Virtual function to print the solution
	virtual void Split();							// Virtual recursive tree funciton	
	virtual ~Expression();							// Virtual destructor
	string expr;									// The expression's string
	char op;										// The operation type
};
#endif
