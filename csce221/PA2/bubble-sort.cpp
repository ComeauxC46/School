//============================================================================
// Name        : bubble-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
		for (int k = 1; k < size; k++) 
		{
			bool cont = false;
			
			for (int j = 0; j < size - k; j++)
			{
				num_cmps++;
				if (A[j+1] < A[j]) 
				{
					int tmp = A[j]; // swap A[j] and A[j+1]
					A[j] = A[j+1];
					A[j+1] = tmp;
					cont = true;
					
				}
			}	
				if (!cont) break; // stop sorting
		}
}
