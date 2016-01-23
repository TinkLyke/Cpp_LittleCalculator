/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Class for subtraction
*/
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
#include"Subtraction.h"
using namespace std;

string Subtraction::evaluate() {							// Function that evaluates
	float le = 0.0, ri = 0.0, difference;					// initaliaze the left, right and answer floats
	le = ArithmeticExpression::convert(left->expr);			// Convert the left expression to a float
	ri = ArithmeticExpression::convert(right->expr);		// Convert the right expression to a float
	difference = le - ri;									// The difference is the left - right
	return to_string(difference);							// Return the answer of the expression
}

void Subtraction::print() {									// (left-right)
	cout << "(" << left->expr << "-" << right->expr << ")"; // Print the subtraction expression
}

