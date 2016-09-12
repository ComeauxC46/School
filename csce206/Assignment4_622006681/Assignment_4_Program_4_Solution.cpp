//Chris Comeaux 622006681
// section 501
// Matrix Multiplication

#include <iostream>
using namespace std;

// set up matrices
const int dem1 = 3;
const int dem2 = 3;
int A [dem1][dem2];
int B [dem2][dem1];
int C [dem1][dem2];

int main()
{
	// get user input
	cout <<"Please enter 18 integers to make 2 3x3 matrices.\n";
	cout <<"For Matrix A enter 9 values:\n";
	for(int count = 0; count < dem1; count++)
		for(int index = 0; index < dem2; index++)
			cin >> A[count][index];
	cout <<"Now enter 9 values for Matrix B:\n";
	for(int count = 0; count < dem2; count++)
		for(int index = 0; index < dem1; index++)
			cin >> B[index][count];
			
	// multiply A & B to get C
	cout <<"By multiplying A and B we get a New Matrix C\n";
	
	int sum[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0} ; // array that will hold values of C 
	int num = 0; // counter for sum array
	

	for(int index1 = 0; index1 < dem1; index1++)
	{
		for(int index2 = 0; index2 < dem1; index2++)
		{
			int sum = 0;
			for(int index = 0; index < dem2; index++)
			{
				sum += A[index1][index]*B[index2][index];
				C[index1][index2] = sum;
			}

		}
	}
	// display A B and C
	 
	cout <<"\tMatrix A:\n";
	for(int count = 0; count < dem1; count++)
	{
		cout<<endl;
		for(int index = 0; index < dem2; index++)
			cout << A[count][index] <<"\t";
	}
		cout <<endl <<endl;
	
	cout <<"\tMatrix B:\n";
	for(int count = 0; count < dem2; count++)
	{
		cout <<endl;
		for(int index = 0; index < dem1; index++)
			cout << B[index][count] <<"\t";	
	}
		cout <<endl <<endl;
		
	cout <<"\tMatrix C:\n";
	for(int c_Count = 0; c_Count < dem1; c_Count++)
	{
		cout<<endl;
		for(int c_Index = 0; c_Index < dem2; c_Index++)
			cout << C[c_Count][c_Index] <<"\t";
	}
return 0;
}

	