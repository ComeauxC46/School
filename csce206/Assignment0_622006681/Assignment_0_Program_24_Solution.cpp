#include <iostream>
using namespace std;

int main()
{
	int number = 12345;
	int rightMost = number % 10;          
	
	cout << "The rightmost digit in "
			 << number << " is "
			 << rightMost << endl;
	
	return 0;
}
