/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Header for addition
*/
#ifndef Addition_H
#define Addition_H
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
using namespace std;

class Addition : public	ArithmeticExpression {	// Class for the addition operand
public:											// These fields/functions are public		
	string Addition::evaluate();				// function to evaluate the sum
	void Addition::print();						// function to print the sub expression
};
#endif