// Chris Comeeaux 622006681
// Section 501
// isPrime Function

#include <iostream>
#include <cstdlib>
using namespace std;

void isPrime (int); // function prototype

int main ()
{
	int N ; // holds the number the user inputs

	cout << "Please enter a integer from 1 to 100\n";
	cout << "and I will tell you if it is prime of not!\n";
	cin >> N;

	while (N < 1 || N > 100) // input validation
	{
		cout << "Please enter a valid number (1-100)\n\n";
		cin >> N;
	}
	
	// call function 
	isPrime (N);

		
return 0;
}


// Function definition

void isPrime (int param1)
{	
	int answer; // holds value of answer in isPrime function

	if (param1 == 2)
	{	
		cout << "The number is prime\n";
		exit(0);
	}
	
	for (int divisor = 2; divisor < param1; divisor++)
	{
		answer = param1%divisor;
		
		if (answer == 0)
		{	
			cout << param1 <<" is not Prime!";
			break;
		}
	}
	
	if (answer != 0)
		cout << param1 <<" is Prime!";
}	
			