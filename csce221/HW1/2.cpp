//Homework 2
#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string, int);


int main()
{
	/*TEST CASES*/
	//empty string
	string str1;
	
	//Palidromes
	string str2 = "racecar";
	string str3 = "deified";
	string str4 = "detartrated";
	string str5 = "gohangasalamiimalasagnahog";
	
	//Not Palidromes
	string str6 = "palidromes";
	string str7 = "homework";
	
	//Test each case	
	if(is_palindrome(str1, str1.size()))
		cout <<"The empty string is a palidrome\n";
	else 
		cout <<"The empty string is not a palidrome\n";
	
	if(is_palindrome(str2, str2.size()))
		cout <<str2 <<" is a palidrome\n";
	else 
		cout <<str2 <<" is not a palidrome\n";
	
	if(is_palindrome(str3, str3.size()))
		cout <<str3 <<" is a palidrome\n";
	else 
		cout <<str3 <<" is not a palidrome\n";
	
	if(is_palindrome(str4, str4.size()))
		cout <<str4 <<" is a palidrome\n";
	else 
		cout <<str4 <<" is not a palidrome\n";
	
	if(is_palindrome(str5, str5.size()))
		cout <<str5 <<" is a palidrome\n";
	else 
		cout <<str5 <<" is not a palidrome\n";
	
	if(is_palindrome(str6, str6.size()))
		cout <<str6 <<" is a palidrome\n";
	else 
		cout <<str6 <<" is not a palidrome\n";
	
	if(is_palindrome(str7, str7.size()))
		cout <<str7 <<" is a palidrome\n";
	else 
		cout <<str7 <<" is not a palidrome\n";
	
return 0;
}

bool is_palindrome(string str, int size)
{
	int begin = 0;
	int end = size-1;

	while (str[begin] == str[end]) // keep looping while the letters match up
	{
		begin++;
		end--;
		if (begin >= end) // if all letters match up return true
			return true;
	}
	return false; //otherwise drop out of loop and return false
}
