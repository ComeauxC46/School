//============================================================================
// Name        : insertion-sort.cpp
// Author      : Chris Comeaux
// Date        : 2/8/2016
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{
	for(int i=1; i<size; i++)
	{
		int current = A[i]; //hold the number being inserted
		int index = i-1; //index of element being compared
		num_cmps++;
	while (A[index]>current && index>=0) //continue looping while the element is larger than the current element and it in range
	{
		A[index+1] = A[index]; //shift the element right
		index--; //move left to the next element
		
	}
	A[index+1] = current; //insert the current element int the correct element
	}
}
