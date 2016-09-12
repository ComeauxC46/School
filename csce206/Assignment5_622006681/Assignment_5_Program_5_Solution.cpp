// Chris Comeaux	622006681
// section 501
// String Concatenation

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


int main()
{
	// variables to hold user input string
	string string_1;
	string string_2;

	

	// get user input
	cout <<"Please enter two strings\n";
	cout <<"String one...\n";
	getline (cin, string_1);
	cout <<"String two...\n";
	getline (cin, string_2);
	
	// set up string pointer
	const char* Ptr1 = string_1.c_str();
	const char* Ptr2 = string_2.c_str();
	
	int mem_Size = (string_1.size() + string_2.size() + 2);
	
	//set up pointer and memory
	char* Ptr;
	Ptr = new char[mem_Size];

	for (int count = 0; count < string_1.size(); count++)
	{
		*Ptr = *Ptr1;
		Ptr1++;
		Ptr++;
	}
	
	*Ptr = ' ';
	Ptr++;
	
	for (int index = 0; index < string_2.size(); index++)
	{
		*Ptr = *Ptr2;
		Ptr2++;
		Ptr++;
	}
	
	*Ptr = '\0';
	
	Ptr -= mem_Size;
		
	cout <<string_1 <<endl;
	cout <<string_2 <<endl;
	cout <<"The strings put together are "; 
	for (int count = 0; count < mem_Size; count++, Ptr++)
		cout <<*Ptr;
	
 return 0;
 }
	