/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Header for subtraction
*/
#ifndef Subtraction_H
#define Subtraction_H
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
using namespace std;

class Subtraction : public ArithmeticExpression {	// Class for the addition operand
public:												// These fields/functions are public
	string Subtraction::evaluate();					// Function to evaluate the difference
	void Subtraction::print();						// function to print the sub expression
};
#endif