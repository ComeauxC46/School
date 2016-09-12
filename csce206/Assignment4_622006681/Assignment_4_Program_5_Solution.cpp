// Chris Comeaux 622006681
// Section 501
// STL Vectors

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// set up vectors being used in program
vector<int> Values(16);

bool checkPalindrome(vector<int>&, vector<int>&);

int main()
{
	// set up numbers and file size
	ifstream inputFile;
	inputFile.open ("Numbers.txt");
	int fileSize = 16;
	// stream number.txt to values an print on screen
	for(int count = 0; count <= Values.size(); count++)
	{
		inputFile >> Values[count];
		cout << Values[count] <<endl;
	}
	 cout <<"The size of Values is " << Values.size() <<endl;
	 
	// copy values into copyvalues
	vector<int> CopyValues(Values);
		
	// user input three values
	int value1;
	int value2;
	int value3;
	cout <<"\nEnter three values to push onto the CopyValues vector\n";
	cin >> value1 >> value2 >> value3;
	CopyValues.push_back(value1);
	CopyValues.push_back(value2);
	CopyValues.push_back(value3);
	
	// display CopyValues
	cout <<"\nDisplay CopyValues\n\n"; 
	for(int count1 = 0; count1 < CopyValues.size(); count1++)
		cout << CopyValues[count1] <<endl;
		
		// copy values into ReverseValues and then reverse it
	vector<int> ReverseValues(Values);
	std::reverse(ReverseValues.begin(), ReverseValues.end());
	
	// display ReverseValues
	cout <<"\nDisplay the reversed values\n\n";
	for(int index = 0; index < ReverseValues.size(); index++)
		cout << ReverseValues[index] <<endl;
		
	// checkPalindrome and return true or false
	int ToF; // hold value if function is true or false
	ToF = checkPalindrome(Values, ReverseValues);
	if(ToF == 1)
		cout <<"\nTRUE, Values is a palindrome!\n\n";
	else if(ToF == 0)
		cout <<"\nFLASE, Values is not a palindrome\n\n";
		
	// Take off user input values and display it
	cout <<"CopyValues with the user input values popped off\n\n"; 
	CopyValues.pop_back();
	CopyValues.pop_back();
	CopyValues.pop_back();
	for(int count = 0; count < CopyValues.size(); count++)
		cout << CopyValues[count] <<endl;
	
return 0;
}


bool checkPalindrome (vector<int> &original, vector<int> &R_original)
{
	bool palindrome = 1;
	for(int count = 0; count < original.size(); count++)
	{
		if(original[count] != R_original[count])
			palindrome = 0;
	}
return palindrome;
}
		
		
		
	