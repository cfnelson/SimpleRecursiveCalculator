////////////////////////////////////////////////////////////////////////////////////
// Filename:			Calculator_H.h
// Author:				Charles Nelson - s2884951
// Date Modified:	12/04/2014 Created
//							15/04/2014 Updated
// Description:		This file contains the prototypes of the Calculator Class.
////////////////////////////////////////////////////////////////////////////////////
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//- Grammar for calculator class
//	
//-	Calculate	--Invokes->	expression() which starts the recursion parsing. 
//
//-	expression:						[ '+' | '-' ]	term [ '+' | '-' term ]*
//
//-	term:				exponenent	[ '*' | '/'	exponenent	]*
// 
//-	exponenent:			factor		[ '^'	factor ]* 
//
//-	factor:				'(' expression ')'| calculateNumbers
//
//-	calculateNumbers:	digit [ digit ]*

class Calculator 
{
private:
	double currentChar;								//- Stores the value of the currentChar read from the string/char Array
	const char* userInput;							//- Pointer to the expression the user has entered

	void displayError(char *errorMessage);			//- Prints out a custom error message depending on the case and terminates the program
	void readNextChar(void);						//- Reads the next input char and sets it to current char, also checks if user wishes to quit the program

	/*** Recursive Decent Parsing Functions - 
			Ordered in Hierarchical Order ***/
	double expression(void);						//- Handles the precedence of "+" and "-" and any negative values before a number
	double term(void);								//- Handles the precedence and the operations for "*" and "/"
	double exponent(void);							//- Handles the power precedence operation 
	double factor(void);							//- Handles the precedence of the "(" and ")" 
	double calculateNumbers(void);					//- Calculates the user's inputs that are whole numbers
	
	/*** Operator functions - Only created for
		    ones needing special handling	***/
	double division(double a, double b);			//- Calculates the division of a/b. Created to handle dividing by 0 error.
	double power(double base, double power);		//- Calculates the result of base ^ power. Created to handle the Case of Positive or Negative

public:

	Calculator();									//- Default Constructor
	~Calculator();									//- Default Destructor 
	double Calculate(const char* expression);		//- Public Calculate function. Starts the calculators calculation calls and returns the calculators answer
};
///////////////////////////////////////////////////////////////////////////////////
// END OF FILE
///////////////////////////////////////////////////////////////////////////////////