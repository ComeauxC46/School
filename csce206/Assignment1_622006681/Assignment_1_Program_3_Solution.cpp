//Chris Comeaux
//622006681
//Section 501
//Card Shuffling: 
//draws two cards randomly from deck of 1-20 after shuffling

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//System time
	unsigned seed = time(0);
	
	//Seed random numbers
	srand(seed);
	
	//Hold the random card number to be displayed
	int randomNumber1 = 1 + rand() % 20;
	int randomNumber2 = 1 + rand() % 20;
	
		//Program output
		cout << "Shuffling the cards...\n";
		cout << "Press enter to pick a random card.\n";
		cin.get();
		cout << randomNumber1 <<endl;
		cout << "Shuffling the cards again...\n";
		cout << "Press enter to pick a random card.\n";
		cin.get();
		cout << randomNumber2;
return 0;
}