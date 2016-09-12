//Homework 1_D
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

int search(int, int);

int main()
{
	try
	{
		int max, max_trials, number;
		
		//ask for the range of numbers
		cout <<"Enter the upperbound for the range"
			 <<"you wish the computer to guess from.\n";
		cin >> max;
		
		//input validadtion
		if(max<=0)
			throw 1;
		
		//set up target number
		cout <<"Enter a target value between [1," <<max <<"] \n";
		cin >> number;
		
		//input validation
		if(number<1 || number>max)
			throw 'e';
		
		//find the max number of guesses
		max_trials = floor(log2(max)+1); 
		cout<< "It should not take more than " <<max_trials 
			<<" guess(es).\n";
			
		int num_trials = search(max, number);
		
		cout <<"Yes\n";
		cout <<"It took the computer " <<num_trials 
			 <<" guess(es)to guess the correct number\n";
	}
	catch(int)
	{
		cerr << "Exception: Please enter a resonable upperbound\n";
	}
	catch(char)
	{
		cerr << "Exception: Please enter a number within the range"
			 <<" [1,upperbound]\n";
	}
	
return 0;
}

int search(int max, int number)
{
	int trials = 1;
	int low = 1;
	int mid = floor((max+low)/2.0); //midpoint of the data for first guess
	int guesses = 0; 
	int range = max;// remember value to be out in resullts vector
	
	/*SEARCH*/
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
	
	//Tabulate results in STL vector 
	//(range, guessed number, number of comparisons required to guess it)	
	vector<int> results;
	results.push_back(range); //range
	results.push_back(number); //number trying to be guessed
	results.push_back(trials); //number of camparisons	
	
	return trials;
}
