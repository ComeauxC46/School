// Chris Comeaux 622006681
// Section 501
// Binary Search

// code reused from problem 2

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// random array
const int size = 100;
int RandomNums[size];

bool BinarySearch (const int [], int, int);

int main()
{
	//random numbers
	srand(time(0));
	
	for (int count = 0; count < size; count++)
		RandomNums[count] = rand() % 1001;
	
	//Sort values
	int Scan = 0;
	int MaxElement;
	int MaxValue;
	
	for(Scan; Scan < size; Scan++)
	{
		MaxElement = Scan;
		MaxValue = RandomNums[Scan];
		for(int index = (Scan + 1); index < size; index++)
		{
			if (RandomNums[index] > MaxValue)
			{
				MaxValue = RandomNums[index];
				MaxElement = index;
			}
		}
		RandomNums[MaxElement] = RandomNums[Scan];
		RandomNums[Scan] = MaxValue;
	}
	cout <<"The array of values is\n";
	for(int count = 0; count < size; count ++)
	{
		cout <<RandomNums[count];
		cout << "\t";
	}
	
	int number = 681; // number being searched for
	cout <<"\n\nThe number is " << number <<endl;
	bool result = BinarySearch(RandomNums, size, number); // run search
	
	if(result)
		cout <<"681 is present in RandomNums array\n";
		
	else
		cout <<"681 was not present in RandomNums array\n";
		
	int U_number; // user defined number
	cout <<"Please enter a number from -infinity to 1000 you would like to search for\n";
	cin >> U_number;
	
	bool U_result = BinarySearch(RandomNums, size, U_number);
	
	if(U_result)
		cout <<U_number <<" was present in RandomNums array\n";
		
	else 
		cout <<U_number <<" was not present in RandomNums array\n";
		
return 0;
}

bool BinarySearch (const int array[], int size, int key)
{
	int first = 0;
	int last = size - 1;
	int middle;
	bool found = false;
	
	while(!found && first <= last)
	{
		middle = (first + last)/2;
		if (array[middle] == key)
			found = true;
		else if (array[middle] < key)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return found;
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	