//============================================================================
// Name        : radix-sort.cpp
// Author      : Chris Comeaux
// Date        : 2/8/2016
// Copyright   : 
// Description : Implementation of radix sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
#include <cmath>

using namespace std;

const int base = 10;
int digit(int k, int num)
{
	int r;
	r = num/(int)pow(static_cast<double>(base),k);
	return r%base;
}

void RadixSort::sort(int A[], int size)
{
	//adjust to make all positive (add 2^15)
	for(int i=0; i<size; i++)
		A[i] = A[i] + 32768;
	
	// finds the largest number 
	int d=0;	//holds the number of digits
	int largest=0;
	for(int i=0; i<size; i++)	
		if(largest<A[i])	
			largest=A[i];	
	//counts how many digits it is		
	while(largest>0)
	{
		d++;
		largest/=10;
	}

	//COUNTING SORT
	int i, j, m;
	
	int* Temp_C = new int [base];
	int* Temp_B = new int[size];
	
	for (m=0; m<d; m++)
	{
		for(i=0; i<base; i++)
		{
			Temp_C[i] =0;
		}
		for (j=0; j<size; j++)
		{
			Temp_C[digit(m,A[j])]++;
		}
		for(i=1; i<base; i++)
		{
			Temp_C[i] += Temp_C[i-1];
		}
		for (j=size-1; j>=0; j--)
		{
			i = --Temp_C[digit(m, A[j])];
			Temp_B[i] = A[j];
		}
		
		for(j=0; j<size; j++)
		{
			A[j] = Temp_B[j];
		}
	}
	delete [] Temp_B;
	delete [] Temp_C;
	
 	//reverse (subtract 2^15)
	for(int i=0; i<size; i++)
		A[i] = A[i] - 32768;
}
	
	
	
	

