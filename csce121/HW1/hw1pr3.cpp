// Chris Comeaux 
// CSCE 121-501
// Due: September 15, 2015
// hw1pr3.cpp

#include "std_lib_facilities_4.h"

 //function prototypes
 void num_squares (int);

int main()
{
	
	const int MAX1=1000;
	const int MAX2=1000000;
	const int MAX3=1000000000;
	
	//call num_squares for 1000
	num_squares(MAX1);
	//call num_squares for 1000000
	num_squares(MAX2);
	//call num_squares for 1000000000
	num_squares(MAX3);
	
	
return 0;
}

void num_squares (int max)
{
	//define variables used in function
	double square[64]; 
	int count = 1;
	
	square[0] = 1; // since the first square will always have one grain
	for(count=1; square[count] <= max; count++)
	{
		square[count] = square[count-1]*2;
		if(square[count] >= max)
			break;
	}
	cout<< "It would take " <<count+1 <<" squares to reach " <<max <<" grains\n";
return;
}
	