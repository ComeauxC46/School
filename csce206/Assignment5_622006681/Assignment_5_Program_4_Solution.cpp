// Chris Comeaux 622006681
// Section 501
// Swap Array

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//set up arrays
const int size = 100;
int array[size];


void swapArray( int *, int);


int main()
{
	cout <<"\t\tBefore Swap\n";
	// set up random number
	srand (time(0));
	
	// initilize rand array
	for (int count = 0; count < 100; count++)
	{
		array[count] = (rand() % 1001);
		cout << array[count] <<"\t";
	}
	cout <<endl <<endl;
	
	swapArray(array, size);
	
	
return 0;
}

void swapArray (int *ptrArray, int size)
{
	int middle = 49;  // middle element
	int hold; // holds value while swapArray
	
	for(int count = 0; count <= 49; count++)
	{
		hold = ptrArray[count];
		ptrArray[count] = ptrArray[50 + count];
		ptrArray[50 + count] = hold;
	}
	
	cout <<"\t\tAfter Swap\n";
	for(int index = 0; index < size; index++)
	{
		cout <<ptrArray[index] <<"\t";
		
	}
}



















