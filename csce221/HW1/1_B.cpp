// Homework1 Problem 1.B
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int search(int, int);

int main()
{
	try
	{
		int max, max_trials;
		
		//ask for the range of numbers
		cout <<"Enter the upperbound for the range"
			 <<"you wish the computer to guess from.\n";
		cin >> max;
		
		//input validadtion
		if(max<=0)
			throw 1;
		
		//set up random number
		srand(time(0));
		int number = rand()%max +1;
		
		//find the max number of guesses
		max_trials = floor(log2(max)+1); 
		cout<< "It should not take more than " <<max_trials 
			<<" guess(es).\n";
			
		int num_trials = search(max, number);
		
		cout <<"Yes\n";
		cout <<"It took the computer " <<num_trials
			 <<" to guess the correct number\n";
	}
	catch(int)
	{
		cerr << "Exception: Please enter a resonable upperbound\n";
	}
	
return 0;
}

int search(int max, int number)
{
	int trials = 1;
	int low = 1;
	int mid = floor((max+low)/2.0); //midpoint of the data for first guess
	
	cout<<"First guess : "<<mid <<endl;
	
	while(mid!=number) // continue to search until the 
	{
		if(mid > number) // number is in lower section
		{
			max = mid-1;
			cout <<"Lower\n";
		}
		else if(mid < number) //number is in upper section
		{
			low = mid+1;
			cout <<"Higher\n";
		}
		mid = floor((max+low)/2.0);
		cout <<"Next Guess: " <<mid <<endl;
		++trials;
	}
	return trials;
}
	