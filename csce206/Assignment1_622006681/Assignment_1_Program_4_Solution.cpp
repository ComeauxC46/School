//Chris Comeaux 622006681
//Section 501
//Scientific Calculator
//A program that can preform many mathematical operations on the same numbers

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

		// Define variables that will hold user assigned numbers
		int num1, num2;
		
			//Ask user for numbers
			cout << "Hello, this program will take the numbers you \n";
			cout << "enter and preform various types of mathematical operations\n";
			cout << "Please enter the first number....\n";
			cin >> num1;
			cout << "Please enter the second number....\n";
			cin >> num2;
			cin.ignore();
			cout << "Calculating.......\n";
			cout << "Please press enter to continue\n";
			cin.get();
			
			// Variables that will hold answers
		double abs_num1 = abs(num1);
		double abs_num2 = abs(num2);
		double cos_num1 = cos(num1);
		double sin_num2 = sin(num2);
		double fmod_num1_2 = fmod(static_cast<double>(num1), num2); //fmod has to have at least one double argument 
		double sqrt_num1 = sqrt(abs_num1);
		double pow_num1_2 = pow(num1,num2);
		
			//Following lines will display results
			cout << "abs(num1)        = " <<abs_num1 <<endl;
			cout << "abs(num2)        = " <<abs_num2 <<endl;
			cout << "cos(num1)        = " <<cos_num1 <<endl;
			cout << "sin(num2)        = " <<sin_num2 <<endl;
			cout << "fmod(num1,num2)  = " <<fmod_num1_2 <<endl;
			cout << "sqrt(num1)       = " <<sqrt_num1 <<endl;
			cout << "pow(num1,num2)   = " <<pow_num1_2 <<endl;
			
			// next lines will ask questions and display the answer to the follow up questions
			cout << "What is the difference between fmod and the modulus operator?\n";
			cout << "\n";
			cout << "-- The fmod function and the modulus both take the remainder\n";
			cout << ",however, the arguments in fmod have to be type double\n";
			cout << "where as the modulus operator only works with integer type operands\n";
			cout << "\n";
			cout << "Why do we have to have the abs(num1) as argument for sqrt() ";
			cout << "and not just num1?\n";
			cout << "\n";
			cout << "-- Since int type variables can be signed, the user";
			cout << "could have entered a negative number.\n";
			cout << "It is not possible to take the sqrt() of a negative number";
			cout << ",therefore the argument had to be the abs(num1).\n";
			
	return 0;
}
			
			
			