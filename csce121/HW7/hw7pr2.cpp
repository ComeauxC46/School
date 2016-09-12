//Chris Comeaux
//CSCE 121-501
//Due: December 8, 2015
//hw7pr2.cpp

#include "std_lib_facilities_4.h"

struct Invalid_SSN{};// if it doesnot match any case.
bool check_zero(const string&);//check to see if any field is all zeros

int main()
{
	regex pat {R"(^\d{3}-?(?!00)\d{2}-?(?!0000)\d{4}$)"}; //correct pattern also checks if second and third fields are zeros
	regex wrong {R"(^(042-?68-?4425|078-?05-?1120|123-?45-?6789)$)"};//sepcial cases
	regex repeat {R"(^(\d)\1+-?(\d)\1+-?(\d)\1+$)"};//if the numbers repeat
	regex bad_start {R"(^(666|9\d\d|000)-?\d{2}-?\d{4}$)"}; // invalid start
	string SS_number;
	while(cout<< "Enter a Social Security Number : " && getline(cin,SS_number))
	{
		try
		{
			smatch matches;			
			if(regex_match(SS_number, matches, pat))//check if correct fromat and checks for all zeros
			{
				if(regex_match(SS_number, matches, bad_start)) //if it starts with an invalid numbers
					cout<< "That is a invalid Social Security Number.\n\n";
				else if(regex_match(SS_number, matches, wrong)) //check for special cases
					cout<< "That is a invalid Social Security Number.\n\n";
				else if(regex_match(SS_number, matches, repeat)) //check for repeating cases
					cout<< "That is an invalid Social Security Number.\n\n";
				else
					cout<< "That is a valid Social Security Number.\n\n";
			}
			else if(!regex_match(SS_number, matches, pat))//if it has all zeros or is not the correct foramt
				cout<<"That is a invalid Social Security Number.\n\n";
			else //if some other error occurs terminate with an exception
				throw Invalid_SSN{};
		}
		catch(...)
		{
			cout<<"That is a invalid Social Security Number.\n\n";
		}
	}
return 0;
}
