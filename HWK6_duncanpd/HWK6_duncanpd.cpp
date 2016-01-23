/*
* Name:? Yifu Wu, Patick Duncan, Nicolai Kozel
* MacID:? wu235, duncanpd, kozeln
* Student Number:? 1450544, 1413067, 1404557
* Description: The main class
*/
//Assuming * is multiplication
#include<iostream>
#include<String>
#include "ArithmeticExpression.h"
using namespace std;

string RemoveSpaces(string exp) {									// Removes spaces from a stirng
	string toReturn = "";											// Initailze empty string
	for (int i = 0; i < exp.size(); i++) {							// Loop through 0-size of exp
		if (exp.at(i) != ' ') {										// If the character is not a space
			toReturn += exp.at(i);									// append that character
		}
	}
	return toReturn;												// return the string
}

bool IsDigit(char c) {												// check if the character is a number
	if ('0' <= c && c <= '9')										// if the character is between 0 and 9
		return true;												// boolean returns true
	else		                                                    // if the character is not a number
		return false;												// boolean returns false
}

bool IsOp(char d) {													// check if the character is an operator
	if (d == '+' || d == '-' || d == '/' || d == '*') {				// if the character is an operator(+,-,/,*)
		return true;												// boolean returns true
	}
	else		                                                    // if the character is not an operator
	{
		return false;												// boolean returns false
	}

}

bool isOkay(char c) {												// Check for illegal characters
	int a = 0;														// Initialize a counter to 0
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4'	// Check if its not 0-9
		&& c != '5' && c != '6' && c != '7' && c != '8' && c != '9'
		&& c != '+' && c != '-' && c != '*' && c != '/'
		&& c != '(' && c != ')') {
		return false;												// The char is not a number
	}
	return true;													// The char is a number
}

bool CheckInput(string exp) {										// boolean that check if the input is in correct format
	if (exp.size() == 0) {											// if there is an empty input
		return false;												// boolean returns false
	}
	if (!IsDigit(exp.at(exp.size() - 1))) {							// if the last character is not a number 
		if (exp.at(exp.size() - 1) != ')')							// if the last character is not a close bracket
			return false;											// boolean returns false
	}
	else {															// if it is not an empty input
		int counter1 = 0;											// initialize counter1
		int counter2 = 0;											// initialize counter2
		for (int i = 0; i < exp.size(); i++) {						// loop through every single character in the input string
			if (IsDigit(exp.at(i))) {								// if the current character is a number
				counter1++; 										// counter1 + 1
			}
			if (IsOp(exp.at(i))) {									// if the current character is a operator
				if (i > 0) {										// if the index of current character is not 0 (not the first character)
					if (IsOp(exp.at(i - 1))) {						// if the last character is a operator
						return false;								// boolean returns false
					}
				}
				counter2++;											// counter2 + 1
			}
			if (!isOkay(exp.at(i))) {								// if the current character is not a legal character
				return false;										// boolean returns false
			}
		}
		if (counter1 == 0) {										// counter1 is 0, means there is only a number on the left 
			return false;											// boolean returns false
		}
		if (counter2 == 0) {										// counter2 is 0, means there is only a number on the right
			return false;											// boolean returns false 
		}
	}
	return true;													// otherwise returns true
}

string Bedmas(string exp, int op) {									// Bedmas returns a string, takes a string and a boolean as parameters
	string Result = exp;											// initialize string Result to be equal exp
	int bracket = 0;												// initialize bracket
	int a = 0;														// initialize a to 0
	int b = 0;														// initialize b to 0
	int c = 0;														// initialize c to 0
	int d = 0;														// initialize d to 0
	int x = 0;														// initialize x to 0
	int y = 0;														// initialize y to 0
	bool inc = false;												// initialize boolean inc to be false 
																	// int i = 0;
	int counterL = 0;												//counting if we only have a number on the left side.
	int counterR = 0;												//counting if we only have a number on the right side.
	string ModifyL = "";											//substring on the left side of the operator
	string ModifyR = "";											//substring on the right side of the operator
	for (int i = 0; i < Result.size(); i++) {						/* loop through every character in Result
																	 if the current character in Result is “*” and isMultiplication , or 
																	current character in Result is “/” and isDivision, or current character 
																	in Result is “+” and isAddition, or current character in Result is “-” and isSubtraction*/
		// 0 for division, 1 for multiplication, 2 for addition, 3 for subtraction
		if ((Result.at(i) == '/' && op == 0) || (Result.at(i) == '*' && op == 1) ||
			(Result.at(i) == '+' && op == 2) || (Result.at(i) == '-' && op == 3)) {
			for (int e = i - 1; e > -1; e--) {						//Go from the left of the operand
				y = e;												// set y equals to e
				if (Result.at(e) == '+' || Result.at(e) == '-' || Result.at(e) == '*'
					|| Result.at(e) == '/' || Result.at(e) == '(' || Result.at(e) == ')') {//check if we have only a number left on left side.
					counterL++;
				}
				if (!IsDigit(Result.at(e))) {						//if it is not a digit or "."
					if ((Result.at(e) == '+' || Result.at(e) == '-' || Result.at(e) == '*'
						|| Result.at(e) == '/') && bracket == 0) {	//see if next digit is an operator
						ModifyL = Result.substr(0, e + 1);			// ModifyL equals the substring on the left of operator
						ModifyL += '(';								// ModifyL adds a “(” 
						ModifyL += Result.substr(e + 1, i - e - 1); // ModifyL adds the rest of the substring from the bracket to the operator we detected
						inc = true;									//set the inc to true
						break;										//break out for the if 
					}
					else if (Result.at(e) == ')' || Result.at(e) == '(') {	// if the current character is a open or close bracket
						if (Result.at(e) == ')') {					//if hit ')' ie. (5+3)*4
							bracket--;								// bracket - 1
							a = e;									// set a to equal the current index e
						}
						else if (Result.at(e) == '(') {				//if hit '(' ie. 2+(4*5)
							bracket++;								// bracket + 1
							b = e;									// set b to equal the current index e
						}
						if (bracket == 0) {							//if bracket is 0 means either it is closed, or we don’t have any bracket in this case.
							if (a > b) {							//  if the index of the close bracket is greater than the index of the open bracket.
								ModifyL = Result.substr(0, b);		// ModifyL equals to the substring from the 0 to the index of the open bracket
								ModifyL += '(';						// ModifyL adds a open bracket
								ModifyL += Result.substr(b, i - b); // ModifyL adds the substring from the bracket to where the operator we found
								inc = true;							// set boolean inc to true 
								break;								// break out from the if statement
							}
						}
					}
				}
				if ((e == 0 && ModifyL == "")) {					//if ModifyL contains nothing, and for loop hits the left end
					ModifyL = '(';									// ModifyL equals to “(”
					ModifyL += Result.substr(0, i);					// ModifyL adds the entire left expression till the operator we found
					bracket = 0; 									// set bracket to be 0
					inc = true;										// set boolean inc to true
				}
			}
			// Go to the right of the operand
			for (int f = i + 1; f < Result.size(); f++) {			// i+1 to size of result				
				x = f;												// x becomes f
				if (Result.at(f) == '+' || Result.at(f) == '-' || Result.at(f) == '*'
					|| Result.at(f) == '/' || Result.at(f) == '(' || Result.at(f) == ')') {		//check if we have only a number left on right side.
					counterR++;
				}
				if (!IsDigit(Result.at(f))) {								//if it is not a digit or "."
					if ((Result.at(f) == '+' || Result.at(f) == '-' || Result.at(f) == '*'
						|| Result.at(f) == '/') && bracket == 0) {			//see if next digit is an operator
						ModifyR = Result.substr(i, f - i);					// The Modified right is the substring from i to f-i
						ModifyR += ')';										// Append a closing bracket
						ModifyR += Result.substr(f);						// modified right append the result’s substring from f to the end
						break;
					}
					else if (Result.at(f) == ')' || Result.at(f) == '(') {	// If the result at f is an open or close bracket
						if (Result.at(f) == '(') {							//if hit ')' ie. (5+3)*4
							bracket--;										// decrement i
							c = f;											// c becomes f
						}
						else if (Result.at(f) == ')') {						//if hit '(' ie. 2+(4*5)
							bracket++;										//increment bracket
							d = f;											// d becomes f
						}
						if (bracket == 0) {									//it is closed
							if (d > c) {									// ie. (1+2)*3
								ModifyR = Result.substr(i, d - i);			// Substring from i to d-i
								ModifyR += ')';								// Add a closing bracket
								ModifyR += Result.substr(d);				// Add the substring from d to the end to modify right
								break;
							}
						}
					}
				}
			}
			if (counterL == 0) {											//if there is only a number on the left.
				ModifyL = Result.substr(0, i);								// The substring from the beginning to i
				ModifyL = '(' + ModifyL;									// add opening bracket
				inc = true;													// inc is true
			}
			if (counterR == 0) {											//if there is only a number on the left.
				ModifyR = Result.substr(i);									// The right modified is the substring from i
				ModifyR += ')';												// Add closing bracket
			}
			if ((x == Result.size() - 1) && ModifyR == "") {				// If x is the size of the result -1 and modifyR is empty
				ModifyR = Result.substr(i);									// The right modified is the substring from i	
				ModifyR += ')';												// Add a bracket to Modify right
			}
		}
		if (inc) {															// if we should increment
			++i;															// increment i
			Result = ModifyL + ModifyR;										// Result is left + right modified	
			inc = false;													// increment is false
		}
		counterL = 0;														// Set left counter to 0
		counterR = 0;														// Set right counter to 0
		ModifyL = "";														// Set ModifyL to empty
		ModifyR = "";														// Set ModifyR to empty
	}
	return Result;															// Return the result
}

bool isNumber(char c) {														// Check if a char is 0-9, ie a number
	int a = 0;																// Initialize a counter to 0
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4'			// Check if its not 0-9
		&& c != '5' && c != '6' && c != '7' && c != '8' && c != '9'
		&& c != '+' && c != '-' && c != '*' && c != '/') {
		return false;														// The char is not a number
	}
	return true;															// The char is a number
}

int main() {																// The main function
	string exp = "";														// initialize string
	while (exp != "#") {
		cout << "Please enter an expression: ";								// print
		getline(cin, exp);													// exp is the input entered
		if (exp.size() >= 3) {												// An expression must be >= to 3 in length
			exp = RemoveSpaces(exp);										// Remove spaces from the expression string
			bool correctInput = CheckInput(exp);							// If the input is correct
			if (correctInput) {												// The input correct
				// Add brackets to fix bedmas
				exp = Bedmas(exp, 0);										// Bedmas for division
				exp = Bedmas(exp, 1);										// Bedmas for multiplication
				exp = Bedmas(exp, 2);										// Bedmas for addition
				exp = Bedmas(exp, 3);										// Bedmas for subtraction
				Expression *ex;												// Initalize Expression object
				ArithmeticExpression *e = new ArithmeticExpression(exp);	// Create an object of ArithmeticExpression
				e->Split();													// call e’s split, call the recursive tree function
				if (!e->error) {											// If e’s member variable error is not true								
					ex = e;													// Set an Expression to an ArithmetricExpression to use fields not in Expression
					ex->print();											// call ex’s print
					printf(" = %.2f\n", atof(ex->evaluate().c_str()));		// print the rounded answer
					delete e;												// Delete the ArithemeticExpression pointer
				}
			}
			else {
				cout << "Expression is not well formed" << endl;			// print expression
			}
		}
		else {
			if (exp != "#")													// if the expr is not #
				cout << "Expression is not well formed" << endl;			// error message
		}
		cout << endl;														// new line
	}
	return 0;																// return 0 to close program
}


