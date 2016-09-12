// Chris Comeaux 622006681
// Section 501	
// Sum of Digits in a String

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	// variable to hold user input
	int MaxSize = 100;
	char input[MaxSize];
	
	cout <<"Please enter a string of digits at least 4 numbers long\n";
	cin.getline(input, MaxSize);
	// find null terminator
	int NullT = 0;
	for(int i = 0; i < MaxSize; i++)
	{
		if(input[i] == '\0')
		{
			NullT = i;
			break;
		}
	}
		
	while(NullT <= 3) // input validation
	{
		cout <<"Please enter at least 4 numbers\n";
		cin.getline(input,MaxSize);
		for(int i = 0; i < MaxSize; i++)
		{
			if(input[i] == '\0')
			{
				NullT = i;
				break;
			}
		}
	}
	
	// convert and find smallest/largest
	int numbers;
	numbers = atoi(input);
	int sum = 0;
	int nums = numbers%10;
	int largest = nums;
	int smallest = nums;
	
	while(numbers>0)
	{
		nums = numbers%10;
		sum += nums;
		numbers= numbers/10;
		if(smallest > nums)
			smallest = nums;
		if(largest < nums)
			largest = nums;
	}
	
	cout <<"The sum of all the numbers is: " <<sum <<endl;
	cout <<"The largest value is: " <<largest <<endl;
	cout <<"The smallest value is: " <<smallest <<endl;
	
return 0;	
}
	
	
	
	
		
		
	