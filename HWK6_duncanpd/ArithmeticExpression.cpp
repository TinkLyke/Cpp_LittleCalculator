/*
* Name:? Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID:? wu235, duncanpd, kozeln
* Student Number:? 1450544, 1413067, 1404557
* Description:? This is the audio class that has properties for audio items
*/
#include "ArithmeticExpression.h"
#include <String>
#include <iostream>
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

void ArithmeticExpression::print() {								// Member function that prints the answer							
	string s = left->expr;											// Initialize string s, and set it equal to the substring on the left side of the operator
	string s2 = right->expr;										// Initialize string s2, and set it equal to the substring on the right side of the operator
	bool leftNum = true, rightNum = true;							/* Set 2 booleans, one is checking if there is only a number on the 
																		left side of the expression. Another one is for the right side.*/
	for (int i = 0; i < s.size(); i++) {							// loop through every character of string s
		if (!isNumber(s.at(i))) {									// if the character at current place is not a number in string s
			leftNum = false;										// set the leftNum to false
			break;													// break out from the for loop
		}
	}
	for (int i = 0; i < s2.size(); i++) {							// if the character at current place is not a number in string s2
		if (!isNumber(s2.at(i))) {									// if the character at current place is not a number in string s
			rightNum = false;										// set rightNum to false		 
			break;													// break out from the for loop

		}
	}
	if (leftNum && rightNum) {										// if both leftNum and rightNum are true
		//print from op class
		if (op == '+') {											// checks if the operator in between is “+”
			Addition a;												//  calling addition
			a.left = left;											// set pointer left in addition points to the left of the expression
			a.right = right;										// set pointer right in addition points to the right of the expression 
			a.print();												// calling print method in addition
		}
		else if (op == '-') {										// checks if the operator in between is “-”
			Subtraction a;											// calling subtraction
			a.left = left;											// set pointer left in subtraction points to the left side of the expression
			a.right = right;										// set pointer right in subtraction points to the right side of the expression
			a.print();												// calling print method in addition
		}
		else if (op == '*') {										// checks if the operator in between is “*”
			Multiplication a;										// calling multiplication
			a.left = left;											// set pointer left in multiplication points to the left side of the expression
			a.right = right;										// set pointer right in multiplication points to the right side of the expression
			a.print();												// calling print method in multiplication
		}
		else if (op == '/') {										// checks if the operator in between is “/”
			Division a;												// calling division
			a.left = left;											// set pointer left in division points to the left side of the expression
			a.right = right;										// set pointer right in division points to the right side of the expression
			a.print();												// calling print method in division
		}
	}
	else if (!leftNum && !rightNum) {								// if leftNum and rightNum are false
		left->print();												// print the left of the operation 
		cout << op;													// print the operator
		right->print();												// print the right of the operation
	}
	else if (leftNum && !rightNum) {								// if only left side is a number
		cout << "(" << left->expr << op;							// add a open bracket and print the left expression with the operator
		right->print();												// right calls print method again
		cout << ")";												// print a close bracket 
	}
	else if (!leftNum && rightNum) {								// if only right side of expression is a number 
		cout << "(";												// print a open bracket
		left->print();												// left calls print method again
		cout << op << right->expr << ")";							// print the operator with right expression and a close bracket
	}
}

string ArithmeticExpression::evaluate() {							// Member function that evaluates a simple expession
	string s = left->expr;											// initialize the string s to be the left of expression 
	string s2 = right->expr;										// initialize the string s2 to be the right of the expression
	bool leftNum = true, rightNum = true;							// initialize boolean leftNum and rightNum to be true
	for (int i = 0; i < s.size(); i++) {								// Go through left side
		if (!isNumber(s.at(i))) {									// if the character at the current place is not a number.
			if (s.at(i) != '.') { 									// if the character at the current place is not a “.” 				
				leftNum = false;									// set bool leftNum to false
				break;												// break out from the for loop
			}
		}
	}
	for (int i = 0; i < s2.size(); i++) {							// Go though right side
		if (!isNumber(s2.at(i))) {									// if the character at the current place is not a number.
			if (s2.at(i) != '.') {									// if the character at the current place is not a “.” 
				rightNum = false;									// set bool rightNum to false
				break;												// break out from the for loop
			}
		}
	}
	if (leftNum && rightNum) {										// boolean leftNum and rightNum are both true
																	//print from op class
		if (op == '+') {											// if the operator is “+”
			Addition a;												// create a addition object
			a.left = left;											// a’s left is left
			a.right = right;										// a’s right is right
			expr = a.evaluate();									// expr is a’s evaluate
		}
		else if (op == '-') {										// If the operand is subtraction
			Subtraction a;											// Create a subtraction object
			a.left = left;											// a’s left is left
			a.right = right;										// a’s right is right
			expr = a.evaluate();									// expr is what a’s evaluate returns
		}
		else if (op == '*') {
			Multiplication a;										// Create a multiplication object
			a.left = left;											// a’s left is left
			a.right = right;										// a’s right is right
			expr = a.evaluate();									// expr is what a’s evaluate returns
		}
		else if (op == '/') {										// If the operand is diviision
			Division a;												// create a division object
			a.left = left;											// a’s left is left
			a.right = right;										// a’s right is right
			expr = a.evaluate();									// expr is what a’s evaluate returns
		}
	}
	else if (!leftNum && !rightNum) {								// If left and right are not numbers
		left->evaluate();											// call left’s evaluate
		right->evaluate();											// call right’s evaluate
		evaluate();													// call evaluate
	}
	else if (leftNum && !rightNum) {								// if left is a number and right is not
		right->evaluate();											// Call right’s evaluate
		evaluate();													// Call evaluate
	}
	else if (!leftNum && rightNum) {								// If right is a number and left is not
		left->evaluate();											// Call left’s evaluate
		evaluate();													// Call evaluate
	}
	return expr;													// Return the expression
}

float ArithmeticExpression::convert(string s) {						// Convert a string to float
	return atof(s.c_str());											// Return the value converted to a float
}

ArithmeticExpression::ArithmeticExpression(string exp) {			// Constructor switch sets expr
	expr = exp;														// Set expr to the parameter
	leftExpr = NULL;												// Set the pointer to null
	rightExpr = NULL;												// Set the pointer to null
}
ArithmeticExpression::ArithmeticExpression() {}						// Default constructor

ArithmeticExpression::~ArithmeticExpression() {						// Default destructor
	delete leftExpr;												// Delete the left expression pointer
	delete rightExpr; 												// Delete the right expression pointer
}

void ArithmeticExpression::Split() {								// Function to split an Arithmetic Expressoin 
	if (expr.at(0) == '(') {										// If the first character is an open bracket
		int brackets = 0, i = 0;									// Brackets keeps track if the brackets are closed and i is a counter for the while loop
		bool closed, done, extra, bExtra;							// predicates for if its closed, the while is done, there’s extra operations, and another predicate
		closed = done = extra = bExtra = false;						// Set them all to faslse
		string le, ri;												// Create 2 strings
		while (i < expr.size() && !done) {							// While i is less than the size of the expression
			if (!closed) {											// While the brackets aren’t closed
				switch (expr.at(i)) {								//	Using the char  at i as the equality
				case '(':											// If its an open bracket
					brackets++;										// increment the brackets counter
					break;											// break out of switch
				case ')':											// If its a closed bracket
					brackets--;										// decrement bracktes
					if (brackets == 0) {							// if the brackets is equal to 0
						closed = true;								// Closed is true 
					}
					break;											// break out of switch
				}
				i++;												// increment i
			}
			else {													// Brackets are closed, find next op
				extra = true;										// There is more stuff after the brackets
				char lastChar, afterOp;								// Initialize the last char and the thing after the operation
				string s;											// initialize a string
				switch (expr.at(i)) {								// Using the char at i as the switch of equality
				case '+':											// If the char is an operand
				case '-':
				case '/':
				case '*':
					le = expr.substr(0, i);							// The left 
					ri = expr.substr(i + 1);						// substring of i+1 to the end
					lastChar = ri.at(size(ri) - 1);					// The last char is the right at the length of ri
					if (i + 1 != size(expr))						// too make sure it doesn’t go out of bounds
						afterOp = expr.at(i + 1);					// set after op to the next character
					if (!isNumber(lastChar) && afterOp == '(') {	// If the last char is not a number and after op is an open bracket
						extra = true;								// extra is true
						goto exit;									// goto the label exit
					}
					leftExpr = new ArithmeticExpression(le);		// create a new memory location of type arithmetic expression
					rightExpr = new ArithmeticExpression(ri);
					// create a new memory location of type arithmetic expression
					left = leftExpr;								// Expression -> leftExpr
					right = rightExpr;								// Expression -> rightExpr
					op = expr.at(i);								// Op is the expression at i
					left->Split();									// Call the split function for left
					right->Split();									// Call the split function for right
					done = true;									// Set done to true
					break;											// Break out of switch
				default:
					goto Error;										// Go to the label Error
					break;											// break out of switch
				}
			}
		}
		if (!done) {												// If not done
		exit:														// The label exit
			if (closed && !extra) {									// If it is closed and there’s no extra operations
				expr = expr.substr(1, expr.size() - 2);				// Set the expression to the substring of the expression without the first and last character
				Split();											// Call the split function
			}
			else if (closed && extra) {								// If the brackets are closed and there’s extra operations
				leftExpr = new ArithmeticExpression(le);			// create a new memory location of type arithmetic expression
				rightExpr = new ArithmeticExpression(ri);			// create a new memory location of type arithmetic expression
				left = leftExpr;									// Expression -> leftExpr					
				right = rightExpr;									// Expression -> rightExpr
				op = expr.at(i);									// the operand is the character at i
				left->Split();										// Call left’s split function
				right->Split();										// Call right’s split function
				done = true;										// Set done to true
			}
			else {
				goto Error;											// Go to the label Error
			}
		}
	}
	else if (isNumber(expr.at(0))) {								// If the first char of the expression is a number
		int i = 0;													// Set i to 0
		string le, ri;												// Initialize 2 strings
		bool expression = false, canSplit = false;					// expression is if its the string is an expression and can split is if we’re allowed to split
		while (i < size(expr) && !expression) {						// While i is less than the size of expr and its not an expression
			switch (expr.at(i)) {									// Using expr’s char at i for equality
			case '+':												// If its an operand
			case '-':
			case '/':
			case '*':
				expression = true;									// Set expression to true
				le = expr.substr(0, i);								// The left string is a substring from 0 to i
				l = convert(le);									// convert left
				ri = expr.substr(i + 1);							// The right string is a substring from i+1 to the end
				r = convert(ri);									// convert right
				leftExpr = new ArithmeticExpression(le);			// create a new memory location of type arithmetic expression
				rightExpr = new ArithmeticExpression(ri);			// create a new memory location of type arithmetic expression
				left = leftExpr;									// Expression -> ArithmeticExpression
				left->expr = le;									// Expression->ArithmeticExpresssion
				right = rightExpr;									//	Expression->ArithmeticExpresssion
				right->expr = ri;									// The right’s expr is now the substring ri
				op = expr.at(i);									// the operand is expr at i
				canSplit = false;									// You cannot split anymore
				for (i = 0; i < left->expr.size(); i++) {			// For i is less than left’s expr
					if (!isNumber((left->expr).at(i)) && (left->expr).at(i) != '.') {	//	If left expr’s char at i not a number and left expr’s char at i is not a “.”
						left->Split();								// Call left’s split function
						break;
					}
				}	
				for (i = 0; i < right->expr.size(); i++) {			// For i is less than right's expr
					if (!isNumber((right->expr).at(i)) && (right->expr).at(i) != '.') {	// If right expr's char at i not a number and riht expr's char at i i not a "."
						right->Split();								// Call right's split function
						break;
					}
				}
				break;												// Break out of switch
			default:												// Number expression
				if (!isNumber(expr.at(i))) {						// If char at i is not a number
					goto Error;										// Goto the Error label
				}
				break;												// Break out of the switch
			}
			i++;													// Increment i
		}
	}
	else {
	Error:															// The Error label
		cout << "Expression is not well formed." << endl;			// Print error
		error = true;												// error is true
	}
}

bool ArithmeticExpression::isNumber(char c) {						// Check if a char is 0-9, ie a number
	int a = 0;														// Initialize a counter to 0
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4'	// Check if its not 0-9
		&& c != '5' && c != '6' && c != '7' && c != '8' && c != '9') {
		return false;												// The char is not a number
	}
	return true;													// The char is a number
}