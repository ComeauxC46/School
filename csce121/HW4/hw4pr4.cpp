// Chris Comeaux
// CSCE 121-501
// Due: october 8, 2015
// hw4pr4.cpp

#include "std_lib_facilities_4.h"
#include "Chrono.h"

int main()
{
			try
		{
			Chrono::Date date1;
			cout << "Enter date as (year,month,day): ";
			cin >> date1;
			Chrono::Date date2 = date1; // date2 has origional date
			Chrono::Date date3 = date1++; // date3 has origioal date and date 1 is incremented
			if(date2 != date3) 
				error("error in postfix++");
			if(date2 == date1) 
				error("error in postfix++");
			if(date1 != ++date2) 
				error("error in postfix++");
			cout<< "Tomorrow is " <<date1 <<endl;
			
		}
		catch(...)
		{
			cerr << "That is not a valid date\n";
			return 1;
		}
return 0;
}