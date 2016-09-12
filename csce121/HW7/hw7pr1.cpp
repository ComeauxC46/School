//Chris Comeaux
//CSCE 121-501
//Due: December 8, 2015
//hw7pr1.cpp

#include "std_lib_facilities_4.h"

struct Invalid_ISBN{};//execption handeling

int main()
{
	regex pat {R"(^(978|979)( |-)?([0-9]( |-)?){9}([0-9]{1}|X)$)"};
	string ISBN;
	cout<< "ISBN : ";
	while(getline(cin,ISBN))
	{
		try
		{
			smatch matches;
			if(regex_match(ISBN, matches, pat))
				cout<< "That is a valid format.\n";
			else if(!regex_match(ISBN, matches, pat))
				cout<< "That is not a valid format.\n";
			else
				throw Invalid_ISBN{};
			cout<< "ISBN : ";
		}
		catch(...)
		{
			cerr<<"That is not a valid format.\n";
		}
	}
return 0;
}