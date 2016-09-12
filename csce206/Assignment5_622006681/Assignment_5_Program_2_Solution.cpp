// Chirs Comeuax 62200681
// Section 501
// Selection Sort

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// random array
const int size = 100;
int RandomNums[size];

int main()
{
	//random numbers
	srand(time(0));
	
	cout <<"\t\tRandom Array\n";
	for (int count = 0; count < size; count++)
	{	
		RandomNums[count] = rand() % 1001;
		cout <<RandomNums[count];
		cout <<"\t";
	}
	cout <<endl <<endl;
	
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
	
	cout <<"\n\t\tSorted Random Array\n";
	for(int count = 0; count < size; count ++)
	{
		cout <<RandomNums[count];
		cout << "\t";
	}
	cout <<"\v\v";
	
	//creat terminal sum array
	int TerminalSum[50];
	
	cout <<"\n\t\tTerminal sum array\n";
	// fill terminalsum
	int Bcount = 0; // counter for the beginning values 
	int Ecount = 99; // counter for the end values
	int index = 0;  // index Terminalsum
	for(Bcount, Ecount, index; Bcount < Ecount; Bcount++, Ecount--, index++)
	{
		TerminalSum[index] = RandomNums[Bcount] + RandomNums[Ecount];
		cout <<TerminalSum[index];
		cout << "\t";
	}
	cout <<"\v\v";
	// sort terminalSum
	
	int Scan2 = 0;
	int Min;
	int MinValue;
	
	for(Scan2; Scan2 < 50; Scan2++)
	{
		Min = Scan2;
		MinValue = TerminalSum[Scan2];
		for(int index2 = (Scan2 + 1); index2 < 50; index2++)
		{
			if (TerminalSum[index2] < MinValue)
			{
				MinValue = TerminalSum[index2];
				Min = index2;
			}
		}
		TerminalSum[Min] = TerminalSum[Scan2];
		TerminalSum[Scan2] = MinValue;
	}
	
	cout <<"\n\t\tSorted Terminal Sum Array\n";
		for(int count2 = 0; count2 < 50; count2++)
	{
		cout << TerminalSum[count2];
		cout << "\t";
	}
	
return 0;
}
	
	
	
	
	
	