// Chris Comeaux 
// CSCE 121-501
// Due: September 15, 2015
// hw1pr4.cpp

#include "std_lib_facilities_4.h"

 // function prototypes
 void num_squares(int);
 void find_total();

 //define global variables used in all function
 unsigned long long square[63] = {1}; // since the first square will be one and doubled from there
 unsigned long long total=0;

int main()
{
	//variables only in main function
	const int MAX1=1000;
	const int MAX2=1000000;
	const int MAX3=1000000000;
	
	//call num_squares for 1000
	num_squares(MAX1);
	//call num_squares for 1000000
	num_squares(MAX2);
	//call num_squares for 1000000000
	num_squares(MAX3);
	
	
	//find the total for 64 squares
	find_total();
	
return 0;
}

void num_squares (int max)
{
	int count = 1;// def of counter variable outside for loop so that it can be used in cout statement
	
	//compiler outputs a warning about comparing two unsigned values
	//this is acceptable because all values used are greater than 0
	
	for(; square[count] <= max; count++) 
	{
		square[count] = square[count-1]*2;
		if(square[count] >= max)
			break;
	}
	cout<< "It would take " <<count+1 <<" squares to reach " <<max <<" grains\n";
return;
}

void find_total()
{
	//assigning each element of array with values
	for(int c = 1; c <=63; c++) // start at seconend element because the first element was initialized
		square[c] = square[c-1]*2;
	for(int c = 0; c<= 63; c++)
		total += square[c];
		
	cout<< "The toal number of grains in 64 squares is " <<total<<endl;
	
return;
}
	
	