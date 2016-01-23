/*
* Name:? Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID:? wu235, duncanpd, kozeln
* Student Number:? 1450544, 1413067, 1404557
* Description: Parent class for ArithmeticExpression
*/
#include "Expression.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include <String>
#include <iostream>
using namespace std;

string Expression::evaluate() {							// Function that evaluates the expression
	return "";											// Return nothing.
};
void Expression::print() {}								// Function to print the expression's solution

void Expression::Split() {}								// Recrusive tree function, for the child

Expression::~Expression() {}							// Virutal destructor
