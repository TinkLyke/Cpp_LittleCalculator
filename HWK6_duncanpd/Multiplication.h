/*
* Name: Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID: wu235, duncanpd, kozeln
* Student Number: 1450544, 1413067, 1404557
* Description: Header for multiplication
*/
#ifndef Multiplication_H
#define Multiplication_H
#include"ArithmeticExpression.h"
#include<iostream>
#include<String>
using namespace std;

class Multiplication : public ArithmeticExpression {	// Class for the addition operand
public:													// These fields/functions are public
	string Multiplication::evaluate();					// function to print the product
	void Multiplication::print();						// function to print the sub expression
};
#endif