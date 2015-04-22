////////////////////////////////////////////////////////////////////////////////////
// Filename:		Calculator.cpp
// Author:			Charles Nelson - s2884951
// Date Modified:	12/04/2014 Created
//					15/04/2014 Updated
// Description:		This file contains the Implementation of the Calculator Class 
////////////////////////////////////////////////////////////////////////////////////
#include "Calculator_H.h"

//=============================== PUBLIC FUNCTIONS ==========================================
	/*********************************************************************************
	* Description:		This function is the Default Constructor for the Calculator.
	*
	* Returns:			Is Constructor
	*
	* Parameters:		NIL
	*
	* Preconditions:	NIL
	*
	* Postconditions:	A default Memory Manger object has been constructed.
	*********************************************************************************/
	Calculator::Calculator()																						//- Default Constructor
	{
		currentChar = 0;																							//- currentChar set
	}

	/*********************************************************************************
	* Description:		This function is the Default Destructor for the Calculator.
	*
	* Returns:			NIL
	*
	* Parameters:		NIL
	*
	* Preconditions:	NIL
	*
	* Postconditions:	Calculator memory has been freed.
	*********************************************************************************/
	Calculator::~Calculator()																						//- Default Destructor 
	{

	}
	/*********************************************************************************
	* Description:		This function calculates a user arthimetic expression and returns
	*					the result to the user;
	*					
	* Returns:			double calculatorAnswer;	Calculator's answer to user expression
	*
	* Parameters:		const char* expression;
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::Calculate( const char* expression )															//- Public Calculate function. Starts the calculators calculation calls
	{
		userInput = expression;																						//- Setting expression char array to userInput

		readNextChar();																								//- Reading the next char from the user input
	
		double calculatorAnswer = 0;																				//- Setting answer to 0 for each time.
		calculatorAnswer = Calculator::expression();																//- Start the recursive decent parser operations
		return calculatorAnswer;																					//- Return the calculator's answer to the user.
	}

//=============================== PRIVATE  FUNCTIONS ==========================================

/*********************************************************************************
	* Description:		This function parses the predence for + and -.
	*
	* Returns:			double a; The result from the addition/subtraction.
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::expression( void )																			//- Handles the precedence of "+" and "-" and any negative values before a number
	{
		double symbol;																								//- Used to check if a negative was infront of the number. Holds the original char value
		double mathsOperator;																						//- Used to check the arthimetic operators infront of the number. Hold the original currentChar detected e.g '+' or '-'
		double a, b;																								//- Holds the first and second values. e.g a + b, a - b, a*b, a/b etc.
		double result;
		result = 0;
		if ( ( symbol = currentChar == '-' ) || currentChar == '+' )												//- Checks the currentChar 
		{
			readNextChar();																							//- Reads the next char from user input. Ignores white space, except for the '\n'.
		}
		
		a = term();																									//- Stores the result of the term() function
  
		if ( symbol )																								//- If symbol is true, then there is/was a negative symbol infront of a. 
		{
			cout<< "Ensuring negative values remain negative" << endl;
			a = -a;
		}
		while ( ( mathsOperator = currentChar ) == '+' || mathsOperator == '-' )									//- Executes while their is addition or subtraction to complete.
		{
			readNextChar();																							//- Moves to the next char.
			b = term();																								//- Stores the result of the term() function from the new char value. 
       
			if ( mathsOperator  == '+' )
			{
				//std::cout << "Addition Detected "	<< std::endl;													//- Used for Testing - Checked what operators where being called
				a = a + b;																							//- Calculates the result of addition
			}
			else 
			{
				//std::cout << "Subtraction Detected"	<< std::endl;												//- Used for Testing - Checked what operatiors where being called
				a = a - b;																							//- Calculates the result of addition of subtraction
			} 
		}
		return a;																									//- Returns the result. Ethier the original a value or the new updated value from the while loop
	}

	/*********************************************************************************
	* Description:		This function handles the predence and the operations for 
	*					"*" and "/".
	*
	* Returns:			double a; Result from exponent() or "multiplication and divison"  .
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::term( void )																					//- Handles the predence and the operations for "*" and "/"
	{
		double mathsOperator,  a, b;
	
		a = exponent();
		while ( ( mathsOperator = currentChar ) == '*' || mathsOperator == '/' )									//- Checks the currentChar symbol for multiplication and division
		{
			readNextChar();																							//- Reads the next char from user input. Ignores white space, except for the '\n'.
			b = exponent();
		
			if ( mathsOperator  != '*' )
			{
				//std::cout << "Divide Detected "		<< std::endl;												//- Used for Testing - Checked what operators where being called
				a = division( a, b );																				//- Operator input was division, Dividing a/b 
			}
			else 
			{
				//std::cout << "Multiply Detected"	<< std::endl;													//- Used for Testing - Checked what operators where being called
				a = a * b;																							//- Operator input was Multiplication, Multiplying a*b 
			} 
		}
		return a;																									//- Returns the result
	}

	/*********************************************************************************
	* Description:		This function handles the predence and the operation for 
	*					the power or exponenet
	*
	* Returns:			double a; The result from '^' or factor().
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::exponent( void )																				//- Handles the power precedence operation 																	
	{
		double a,b;																							

		a = factor();																								//- Calls the factor() to provide answer

		while ( currentChar  == '^' )																				//- Check to see if currentChar is a Power sign. 
		{
			readNextChar();																							//- Reads the next char from user input. Ignores white space, except for the '\n'.
			b = factor();
			a = power(a,b);																							//- Where a = base & b = power
		}
		return a;																									//- Return the Answer
	}
/*********************************************************************************
	* Description:		This function handles the precedence of the "(" and ")" and 
	*					operations for inside the brackets.
	*
	* Returns:			double result; The result from inside '('')' or calculateNumbers() .
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::factor( void )																				//- Handles the precedence of the "(" and ")"
	{
		double result;
	
		if ( currentChar == '(' )																					//- Checking for precedence due to brackets
		{
			readNextChar();																							//- Reading the next char from the user input
			result = expression();																					//- Setting i to the the expression()

			if ( currentChar != ')' ) 
			{
				displayError( "WARNING: SYNTAX ERROR: ')' was expected. Exiting Program..." );						//- Displays a warning error saying there was a missing ")". Terminates the program
			}
			readNextChar();																							//- Reads the next char from user input. Ignores white space, except for the '\n'.
		}
		else
		{
			result = calculateNumbers();																			//- Calculates the Numbers
		}
		return result;																								//- Return the result
	}

	/*********************************************************************************
	* Description:		This function calculates the user's inputs that are whole numbers
	*					and passes the back up to the functions.
	*
	* Returns:			double wholeNumber; The number values from the user expression.
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::calculateNumbers( void )																		//- Calculates the user's inputs that are whole numbers
	{
		double wholeNumber = 0;																						//- Setting wholeNumber value to 0;
	
		if ( !isdigit( currentChar ) ) 
		{
			displayError("WARNING: SYNTAX ERROR: A whole number was expected. Exiting Program...");
		}
		do 
		{
			wholeNumber = wholeNumber*10 + ( currentChar - '0' );													//- Making sure any number larger then 10 does not get lost and cut off	
			readNextChar();																							//- Reads the next char from user input. Ignores white space, except for the '\n'.			
		} 
		while ( isdigit( currentChar ) );																			//- Loop while currentChar is a digit
		return wholeNumber;																							//- Return the result
	}
	
/*********************************************************************************
	* Description:		This reads the next input char from the user input expression
	*					and set it to the current char. The function also checks the 
	*					currentChar to see if the user has selected to quit the program. 
	*
	* Returns:			void;
	*
	* Parameters:		void
	*
	* Preconditions:	NIL
	*
	* Postconditions:	A default Memory Manger object has been constructed.
	*********************************************************************************/
	void Calculator::readNextChar( void )																			//- Reads the next input char and sets it to current char
	{
		currentChar = *userInput++;																					//- Setting the currentChar to the next char in the string
	
		while ( isspace( currentChar ) && currentChar != '\n' )														//- Checks to see if currentChar is a white space, but not the 'n\' character (otherwise code will get stuck when enter is hit). If currentChar is a whitespace it gets the next Char
		{
			currentChar = *userInput++;																				//- Setting currentChar to the next char
		}
	
		if ( currentChar == EOF )
		{
			displayError( "Thats strange, the EOF has been reached. Exiting Program...");							//- End of file char has been reached, for when files are used Quits the program
		}

		if ( currentChar == 'q' || currentChar == 'Q')																//- Checking to see if user has asked to quit by pressing q or Q.
		{
			displayError( "You have selected to quit the program. Quiting the program..."	 );						//- User has selected to quit the program
		}
	}

	/*********************************************************************************
	* Description:		This function displays the error message that is invoked and
	*					then exits the program with a specified exit number.
	*
	* Returns:			NIL
	*
	* Parameters:		char* errorMessage;	Error message to print out to ostream.
	*
	* Preconditions:	NIL
	*
	* Postconditions:	Program has exited with code 69
	*********************************************************************************/
	void Calculator::displayError( char* errorMessage )																//- Prints out a custom error message depending on the case and terminates the program
	{
		puts( errorMessage );																						//- Copies the char* errorMessage to the stdout until the null terminating char and prints.
	#ifdef WIN32 
		system("PAUSE");																							//- Pausing the system to see the output message
	#else
		//- Left Empty
	#endif																						
		exit( 69 );																									//- Setting a custom exit number, so we know the program exited due to our error handling
	}

	/*********************************************************************************
	* Description:		This function calculates the division of a/b and handles
	*					the dividing by 0 error by invoking the displayError() and 
	*					exiting the program with code 69.
	*
	* Returns:			double result;
	*
	* Parameters:		double a; Top
	*					double b; Divisor 
	*
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::division( double a, double b )																//- Calculates the division of a/b. Created to handle dividing by 0 error.
	{
		if ( b == 0 )
		{
			displayError( "WARNING: ARITHMETIC ERROR: Attempting to divide by zero. Exiting Program" );				//- Exits the program after displaying Warning - Arithmetic Error: Attempting to divie by zero
		}
		return a / b;	
	}

	/*********************************************************************************
	* Description:		This function calculates the result of base ^ power. 
	*					The function handles both Postive or Negative values but cannot
	*					handle decimal numbers. E.G 2 ^ 5.65
	*
	* Returns:			double result;
	*
	* Parameters:		double base; double power;
	*
	* Preconditions:	Input values must be whole numbers.
	*
	* Postconditions:	NIL
	*********************************************************************************/
	double Calculator::power( double base, double power )															//- Calculates the result of base ^ power. Created to handle the Case of Postive or Negative
	{
		double result = 1;
		if ( power > 0 )																							//- Case 1: The power number is positive.
		{
			for ( double i = 0; i < power; i++ )																	//- Loop through and multiply the base
			{
				result *= base;
			}
		}
		else																										//- Case 2: The power number is negative.
		{
			for ( double i = 0; i >power; i-- )																		//- Work backwards e.g opposite to the positive
			{
				result /= base;
			}
		}
		return result;																								//- Return the answer
	}

///////////////////////////////////////////////////////////////////////////////////
// END OF FILE
///////////////////////////////////////////////////////////////////////////////////