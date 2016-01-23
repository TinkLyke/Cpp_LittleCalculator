/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Division for division
*/
#ifndef Division_H
#define Division_H
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
using namespace std;

class Division : public ArithmeticExpression {	// Class for the addition operand
public:											// These fields/functions are public
	string Division::evaluate();				// function to evaluate the quotient
	void Division::print();						// function to print the sub expression
};
#endif