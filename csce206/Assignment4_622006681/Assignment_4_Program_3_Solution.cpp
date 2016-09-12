// Chris Comeaux 622006681
// section 501
// 2D Arrays

#include <iostream>
#include <fstream>
using namespace std;

// set up array
const int rows = 4;
const int cols = 4;
int Values[rows][cols];

// Function prototype
void columnStats (const int[][cols], int);
void transposed_Values (const int[][cols], int);

int main ()
{
	// set up file stream
	ifstream inputFile;
	inputFile.open ("Numbers.txt");

	for(int r_Count = 0; r_Count < rows; r_Count++)
	{
		cout << endl;
		for(int c_Count = 0; c_Count < cols; c_Count++)
		{
			inputFile >> Values[r_Count][c_Count];
			cout << Values[r_Count][c_Count] << "\t"; 
		}
	}
	
	// array calculations
	columnStats (Values, rows);
	
	// transpose array
	transposed_Values (Values, rows);
return 0;
}

void columnStats (const int numbers[][cols], int rows)
{
	// creat local variables
	double sum = 0;
	double avg;
	
	for(int count = 0; count < cols; count++)
	{
		for( int index = 0; index < rows; index++)
		{
			sum += numbers[index][count];
		}
		cout << endl;
		avg = sum/4;
		cout << "Column " << (count+1) << ":Sum = " << sum;
		cout << "\tAverage = " << avg <<endl;
		sum = 0;
	}
}

void transposed_Values (const int numbers[][cols], int rows)
{
	int transposed_Values[4][4] = {0,0,0,0,0,0,0,0,
								   0,0,0,0,0,0,0,0};
	// transpose values							   
	for(int count = 0; count < cols; count++)
	{	
		for(int index = 0; index < rows; index++)
			transposed_Values[count][index] = numbers[count][index];
	}
	// display values
		for(int count = 0; count < cols; count++)
	{
		cout << endl;
		for(int index = 0; index < rows; index++)
		{
			cout << transposed_Values[index][count] << "\t"; 
		}
	}
}	
			
	
		