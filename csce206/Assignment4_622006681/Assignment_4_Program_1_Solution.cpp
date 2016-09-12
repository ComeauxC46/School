//Chris Comeaux 622006681
//Section 501
//Lottery Game

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int lottery[5]; // Array that will hold lottery numbers
int user[5];    // Array holding user input numbers
int sum;        // Accumulator variable 

int main ()
{
	// set up random numbers
	srand(time (0)); // make all numbers random
	
	//get user input
	cout << "Please enter your lucky numbers (0-9).\n";
	cout << "First number:\n";
	cin >> user[0];
	cout << "Second number:\n";
	cin >> user[1];
	cout << "Third number:\n";
	cin >> user[2];
	cout << "Fourth number:\n";
	cin >> user[3];
	cout << "Fifth number:\n";
	cin >> user[4];
	
	// code to creat random number list
	for (int count = 0; count < 5; count++)
		lottery[count] = rand() % 10;
		
	// display lottery numbers
	cout <<"Lottery Numbers\n";
	for (int count = 0; count < 5; count++)
		cout << lottery[count] << "\t";
	cout <<"\nUser Numbers\n";
	for (int count = 0; count < 5; count++)
		cout << user[count] << "\t";
		
	// Compare numbers
	for (int count = 0; count < 5; count++)
	{
		if (lottery[count] == user[count])
		{
			cout << "\n\nArray element " << count <<" (value:" << user[count] <<") matches\n";
			sum += 1;
		}
	}
	cout <<"\nThere are in total " << sum << " matching digits\n";
	
	// test for grand prize
	if (sum == 5)
		cout <<" Congradulations, You Are A Grand Prize Winner!\n";
		
return 0;
}
		
		
	
