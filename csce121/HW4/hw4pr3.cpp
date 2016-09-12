// Chris Comeaux
// CSCE 121-501
// Due: october 8, 2015
// hw4pr3.cpp

#include "std_lib_facilities_4.h"
#include "Chrono.h"

int main()
{
			try
		{
			Chrono::Date date1;
			cout << "Enter date as (year,month,day): ";
			while(cin >> date1) // keep asking for more data until bad input is entered
			{
				++date1;
				cout << "Tomorrow is " <<date1 <<endl;
				cout << "Enter another date as (year,month,day) or 'qq' to exit: ";
			}
		}
		catch(...)
		{
			cerr << "That is not a valid date\n";
			return 1;
		}
return 0;
}