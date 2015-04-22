////////////////////////////////////////////////////////////////////////////////////
// Filename:		main.cpp
// Author:		Charles Nelson - s2884951
// Date Modified:	12/04/2014 Created
//			15/04/2014 Updated 
// Description:		This file contains the main function
////////////////////////////////////////////////////////////////////////////////////
#include "Calculator_H.h"

int main (void)
{
	/*** Ensure that the calculator is always running. 
	     Bool is never set to true, loop only ends when 
	     an error occurs or user selects q || Q.    **/
	bool quitCalculator = false;		
	
	std::cout << "Hello, I am a simple scientific calculator."					<< std::endl;
	std::cout << "I accept numbers and the following operators."					<< std::endl;
	std::cout << "+ , - , * , / , ^ , ( , and )"							<< std::endl;
	std::cout << "If you wish to exit, enter \"q\" and press ENTER."				<< std::endl;
	std::cout << "Otherwise, please enter in an expression for calculation and press ENTER."	<< std::endl;
	
	Calculator calculator; 
	do
	{											
		double calculatorAnswer = 0;
	
		string userInput;
		getline(cin, userInput);					//- Retrieving the user's input  and storing it in the string

		calculatorAnswer = calculator.Calculate(userInput.c_str());	//- Returns the calculators answer.Calls the Calculate function with a char* which is the userInput.c_str()
		
		std::cout << "Calculating your Answer now." << std::endl;
		std::cout << "\nAnswer = " << std::fixed    << std::setprecision(3) << calculatorAnswer << std::endl;
		std::cout << "\nIf you want to go again, please enter in an expression and press ENTER."<< std::endl;
		std::cout << "Otherwise if you wish to exit, enter \"q\" and press ENTER.\n"		<< std::endl;
#ifdef WIN32 
		system("PAUSE");
#else
		//- Left Empty
#endif
	}
	while (!quitCalculator);
    return 0;
};

///////////////////////////////////////////////////////////////////////////////////
// END OF FILE
///////////////////////////////////////////////////////////////////////////////////
