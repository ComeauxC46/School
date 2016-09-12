// Chris Comeaux 622006681
// Section 501
// Linear Search

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//set up array
const int size = 100;
int array[size];


int main()
{
	// set up random number
	srand (time(0));
	
	// initilize rand array
	for (int count = 0; count < 100; count++)
	{
		array[count] = (rand() % 1001);
		cout << array[count] <<"\t";
	}
	cout << endl;
	
	// search the array
	int primeNum[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41
					   ,43,47,53,59,61,67,71,73,79,83,89,97}; 
	vector<int>position;
	bool prime = false;
	
	for(int index = 0; index < 25; index++)
	{
		prime = false;
		
		for(int count = 0; count < 100; count++)
		{
			if(array[count] == primeNum[index])
			{
				prime = true;

			}
				if(prime)
				{
					cout <<"Prime Number " <<array[count];
					cout <<"\tFound at index " << count <<endl;
					position.push_back(array[count]);
					break;
				}
		}
	}
	
	
	// find sumPrime
	int sumPrime = 0;
	if (position.size() == 0)
		sumPrime = 5 + 7;
	else if (position.size() == 1)
		sumPrime = position[0] + 19;
	else if (position.size() >= 2)
		sumPrime = position[0] + position[1];

		
	cout <<"sumPrime = " << sumPrime <<endl;
	
	for(int count = 0; count < size; count++)
	{
		if((array[count]%sumPrime) == 0)
			cout << array[count] <<endl;
	}
	
return 0;
}
		
		
		
		
		
		
		
	
	
	
	

 
