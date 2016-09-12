// Homework Problem 1.A
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
	int max, guess;
	int num_trials=1, max_trials;
	
	//ask for the range of numbers
	cout <<"Enter the upperbound for the range you wish to guess from.\n";
	cin >> max;
	
	//set up random number
	srand(time(0));
	int number = rand()%max +1;
	
	//find the max number of guesses
	max_trials = floor(log2(max)+1); 
	cout<< "It should not take more than " <<max_trials <<" guess(es).\n\n";
	
	//set up first prompt
	cout <<"First guess: ";
	while(cin>>guess && guess != number) //continue loop while reciving 
	{									 //input and the guess is not correct
		if(guess > number)
			cout <<"Lower\n\n";
		else
			cout <<"Higher\n\n"; 
		// if user guesses too many times throw fail 
		if(++num_trials > max_trials)
		{							
			cout<<"It should not have taken you that many guesses.\n"
			 <<"You Lose...\n";
			return 1;
		}
		cout <<"Next guess: "; //prompt again
	}
	
	cout <<"Yes\n\n";
	cout <<"It took you " <<num_trials <<" guesses.\n";
return 0;
}
