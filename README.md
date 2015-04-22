# SimpleRecursiveCalculator 

A simple scientific calculator using recursion (recursive decent parser) to calculate answers provided by a user’s arithmetic expression entered from a keyboard.

Implemented for win32 machine using c++11.

The following outlines the user requirements for the program:
* The user shall be able to enter as many keyboard characters into the cmd line
* However only the following operators: +, - , * , / , ^ , ( , ) and whole numbers will be accepetd.
* The Calculator will continue running until the user selects to quit by perssing ‘q’ or ‘Q’ or by entering an invalid character outside the accpetable operators.
* The user can enter whitespaces between the numbers and their operators without causing errors.
* If the user has entered a valid arthimetic expression that contains the valid operators then the answer will be displayed for the user.
* The user is then prompted to enter another arthimetic expression or they can quit.

The following outlines the software requirements:
* Public function - double Calculate(char* expression);
* Handle floating point numbers.
* The following operators: +, - , * , / , ^ , ( , ) and their precedence.
* User is prompted to enter an expression.
* User can quit by entering q and pressing enter.
* The result should be printed out using no more then 3 decimal place.
* The calculator can handle the following expressions:
  * 2^2 + 3 – 4
  * (2 + 3) * 5
  * (2 + 3) * (5 - 1)^2
  * 2 + ((3 + 1) * (6 - 2) – 1) / (4 - 2)
