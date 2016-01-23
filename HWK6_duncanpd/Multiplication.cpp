/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Class for multiplication
*/
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
#include"Multiplication.h"
using namespace std;

string Multiplication::evaluate() {							// Function that evaluates
	float le = 0.0, ri = 0.0, product;						// initaliaze the left, right and answer floats
	le = ArithmeticExpression::convert(left->expr);			// Convert the left expression to a float
	ri = ArithmeticExpression::convert(right->expr);		// Convert the right expression to a float
	product = le * ri;										// The product is left*right
	return to_string(product);								// Return the answer of the expression
}

void Multiplication::print() {								// (left*right)
	cout << "(" << left->expr << "*" << right->expr << ")"; // Print the multiplication expression
}

